#include "r_io.h"
#include <errno.h>
#include <fcntl.h>
#include <netdb.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/wait.h>

#define MAXLINE 8192
#define MAXBUF 8192
#define LISTENQ 1024

typedef void handler_t(int);

int open_listenfd(char *port);
void doit(int fd);
void read_request_headers(rio_t *rp);
int parse_uri(char *uri, char *filename, char *cgiargs);
void serve_static(int fd, char *filename, int filesize);
void get_filetype(char *filename, char *filetype);
void serve_dynamic(int fd, char *filename, char *cgiargs);
void clienterror(int fd, char *cause, char *errnum, char *shortmsg,
                 char *longmsg);
handler_t *signal(int signum, handler_t *handler);
void sigchld_handler(int sig);

extern char **environ;

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "usage: %s <port>\n", argv[0]);
        exit(1);
    }

    signal(SIGCHLD, sigchld_handler);

    int listenfd, connfd;
    char hostname[MAXLINE], port[MAXLINE];
    socklen_t clientlen;
    struct sockaddr_storage clientaddr;

    if ((listenfd = open_listenfd(argv[1])) < 0) {
        fprintf(stderr, "open_listenfd error\n");
        exit(1);
    }

    for (;;) {
        clientlen = sizeof(clientaddr);
        if ((connfd = accept(listenfd, (struct sockaddr *)&clientaddr,
                             &clientlen)) < 0) {
            fprintf(stderr, "accept error\n");
            exit(1);
        }
        if ((getnameinfo((struct sockaddr *)&clientaddr, clientlen, hostname,
                         MAXLINE, port, MAXLINE, 0)) != 0) {
            fprintf(stderr, "getnameinfo error\n");
            exit(1);
        }
        printf("Accepted connection from (%s, %s)\n", hostname, port);
        doit(connfd);
        close(connfd);
    }
}

int open_listenfd(char *port) {
    struct addrinfo hints, *listp, *p;
    int listenfd;
    int optval = 1;
    int ai;

    /* get a list of potential server addresses */
    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_socktype = SOCK_STREAM;             /* accept connections */
    hints.ai_flags = AI_PASSIVE | AI_ADDRCONFIG; /* on any IP address */
    hints.ai_flags |= AI_NUMERICSERV;            /* using port number */

    if ((ai = getaddrinfo(NULL, port, &hints, &listp)) != 0) {
        fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(ai));
        exit(1);
    }

    /* walk the list for one that we can bind to */
    for (p = listp; p; p = p->ai_next) {
        /* create socket descriptor */
        if ((listenfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) <
            0) {
            continue; /* socket failed, try again */
        }

        /* eliminates "address already in use" error from bind */
        setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, (const void *)&optval,
                   sizeof(int));

        /* bind the descriptor to the address */
        if (bind(listenfd, p->ai_addr, p->ai_addrlen) == 0) {
            break; /* success */
        }

        close(listenfd); /* bind failed, try the next */
    }

    freeaddrinfo(listp);
    if (!p) {
        return -1;
    }

    /* make it a listening socket ready to accept connection requests */
    if (listen(listenfd, LISTENQ) < 0) {
        close(listenfd);
        return -1;
    }
    return listenfd;
}

void doit(int fd) {
    int is_static;
    struct stat sbuf;
    char buf[MAXLINE];
    char method[MAXLINE];
    char uri[MAXLINE];
    char version[MAXLINE];
    char filename[MAXLINE];
    char cgiargs[MAXLINE];
    rio_t rio;

    /* read request line and headers */
    rio_readinitb(&rio, fd);
    rio_readlineb(&rio, buf, MAXLINE);
    printf("Request headers:\n");
    printf("%s", buf);
    sscanf(buf, "%s %s %s", method, uri, version);
    if (strcasecmp(method, "GET")) {
        clienterror(fd, method, "501", "Not implemented",
                    "Tiny does not implement this method");
        return;
    }
    read_request_headers(&rio);

    /* parse URI from GET request */
    is_static = parse_uri(uri, filename, cgiargs);
    if (stat(filename, &sbuf) < 0) {
        clienterror(fd, filename, "404", "Not found",
                    "Tiny could not find this file");
        return;
    }

    if (is_static) {
        if (!(S_ISREG(sbuf.st_mode)) || !(S_IRUSR & sbuf.st_mode)) {
            clienterror(fd, filename, "403", "Forbidden",
                        "Tiny couldn't read the file");
            return;
        }
        serve_static(fd, filename, sbuf.st_size);
    } else {
        if (!(S_ISREG(sbuf.st_mode)) || !(S_IXUSR & sbuf.st_mode)) {
            clienterror(fd, filename, "403", "Forbidden",
                        "Tiny couldn't run the CGI program");
            return;
        }
        serve_dynamic(fd, filename, cgiargs);
    }
}

void clienterror(int fd, char *cause, char *errnum, char *shortmsg,
                 char *longmsg) {
    char buf[MAXLINE];
    char body[MAXBUF];

    sprintf(body, " <html><title>Tiny Error</title>");
    sprintf(body,
            "%s<body bgcolor="
            "ffffff"
            ">\r\n",
            body);
    sprintf(body, "%s%s: %s\r\n", body, errnum, shortmsg);
    sprintf(body, "%s<p>%s: %s\r\n", body, longmsg, cause);
    sprintf(body, "%s<hr><em>The Tiny Web server</em>\r\n", body);

    sprintf(buf, "HTTP/1.0 %s %s\r\n", errnum, shortmsg);
    rio_writen(fd, buf, strlen(buf));
    sprintf(buf, "Content-type: text/html\r\n");
    rio_writen(fd, buf, strlen(buf));
    sprintf(buf, "Content-length: %d\r\n\r\n", (int)strlen(body));
    rio_writen(fd, buf, strlen(buf));
    rio_writen(fd, body, strlen(body));
}

void read_request_headers(rio_t *rp) {
    char buf[MAXLINE];

    rio_readlineb(rp, buf, MAXLINE);
    while (strcmp(buf, "\r\n")) {
        rio_readlineb(rp, buf, MAXLINE);
        printf("%s", buf);
    }
    return;
}

int parse_uri(char *uri, char *filename, char *cgiargs) {
    char *ptr;

    if (!strstr(uri, "cgi-bin")) {
        strcpy(cgiargs, "");
        strcpy(filename, ".");
        strcat(filename, uri);
        if (uri[strlen(uri) - 1] == '/') {
            strcat(filename, "home.html");
        }
        return 1;
    } else {
        ptr = index(uri, '?');
        if (ptr) {
            strcpy(cgiargs, ptr + 1);
            *ptr = '\0';
        } else {
            strcpy(cgiargs, "");
        }
        strcpy(filename, ".");
        strcat(filename, uri);
        return 0;
    }
}

void serve_static(int fd, char *filename, int filesize) {
    int srcfd;
    /* char *srcp; */
	char *sp;
    char filetype[MAXLINE];
    char buf[MAXBUF];

    /* send response headers to client */
    get_filetype(filename, filetype);
    sprintf(buf, "HTTP/1.0 200 OK\r\n");
    sprintf(buf, "%sServer: Tiny Web server\r\n", buf);
    sprintf(buf, "%sConnection: close\r\n", buf);
    sprintf(buf, "%sContent-length: %d\r\n", buf, filesize);
    sprintf(buf, "%sContent-type: %s\r\n\r\n", buf, filetype);
    rio_writen(fd, buf, strlen(buf));
    printf("Response headers:\n");
    printf("%s", buf);

    int log;
    if ((log = open("log.txt", O_CREAT | O_RDWR | O_APPEND, 0666)) < 0) {
        fprintf(stderr, "log open failed: %s\n", strerror(errno));
    } else {
        rio_writen(log, buf, strlen(buf));
    }
    /* send response body to client */
    srcfd = open(filename, O_RDONLY, 0);
    /* srcp = mmap(0, filesize, PROT_READ, MAP_PRIVATE, srcfd, 0); */
	sp = malloc(filesize);
	rio_readn(srcfd, sp, filesize);
    close(srcfd);
    rio_writen(fd, sp, filesize);
    rio_writen(log, sp, filesize);
    close(log);

    /* munmap(srcp, filesize); */
}

void get_filetype(char *filename, char *filetype) {
    if (strstr(filename, ".html")) {
        strcpy(filetype, "text/html");
    } else if (strstr(filename, ".gif")) {
        strcpy(filetype, "image/gif");
    } else if (strstr(filename, ".png")) {
        strcpy(filetype, "image/png");
    } else if (strstr(filename, ".jpg")) {
        strcpy(filetype, "image/jpeg");
    } else if (strstr(filename, ".mpg")) {
		strcpy(filetype, "video/mpeg");
	} else {
        strcpy(filetype, "text/plain");
    }
}

void serve_dynamic(int fd, char *filename, char *cgiargs) {
    char buf[MAXLINE];
    char *emptylist[] = {NULL};

    /* return first part of HTTP response */
    sprintf(buf, "HTTP/1.0 200 OK\r\n");
    rio_writen(fd, buf, strlen(buf));
    sprintf(buf, "Server: Tiny Web Server\r\n");
    rio_writen(fd, buf, strlen(buf));

	int log;
	char logbuf[MAXLINE];
	if ((log = open("log.txt", O_CREAT | O_RDWR | O_APPEND, 0666)) < 0) {
		fprintf(stderr, "log open failed: %s\n", strerror(errno));
	}

    if (fork() == 0) {
        setenv("QUERY_STRING", cgiargs, 1);
		printf("cgiargs: %s\n", cgiargs);
		dup2(log, STDOUT_FILENO);
        dup2(fd, STDOUT_FILENO);
        execve(filename, emptylist, environ);
    }
    /* wait(NULL); */
}

handler_t *signal(int signum, handler_t *handler) {
    struct sigaction action, old_action;
    action.sa_handler = handler;
    sigemptyset(&action.sa_mask);
    action.sa_flags = SA_RESTART;

    if (sigaction(signum, &action, &old_action) < 0) {
        fprintf(stderr, "Signal error");
        exit(1);
    }
    return (old_action.sa_handler);
}
void sigchld_handler(int sig) {
    int olderrno = errno;
    pid_t pid;
    int status;

    while ((pid = waitpid(-1, &status, WNOHANG)) > 0)
        ;
    errno = olderrno;
}
