#include "open_fd.h"
#include "r_io.h"
#include <stdlib.h>
#include <stdio.h>
#include <sys/socket.h>
#include <string.h>
#include <netdb.h>

void echo(int connfd);

int main(int argc, char **argv) {
	int listenfd, connfd;
	socklen_t clientlen;
	struct sockaddr_storage clientaddr;
	char client_hostname[MAXLINE];
	char client_port[MAXLINE];

	if (argc != 2) {
		fprintf(stderr, "usage: %s <port>\n", argv[0]);
		exit(1);
	}

	if ((listenfd = open_listenfd(argv[1])) < 0) {
		fprintf(stderr, "open_listenfd error\n");
		exit(1);
	}

	for (;;) {
		clientlen = sizeof(struct sockaddr_storage);
		if ((connfd = accept(listenfd, (struct sockaddr *)&clientaddr, &clientlen)) < 0) {
			fprintf(stderr, "accept error: %s\n", gai_strerror(connfd));
			exit(1);
		}
		getnameinfo((struct sockaddr *)&clientaddr, clientlen, client_hostname, MAXLINE, client_port, MAXLINE, 0);
		printf("Connected to (%s, %s)\n", client_hostname, client_port);
		echo(connfd);
		close(connfd);
	}

	exit(0);
}

void echo(int connfd) {
	size_t n;
	char buf[MAXLINE];
	rio_t rio;

	rio_readinitb(&rio, connfd);
	while ((n = rio_readlineb(&rio, buf, MAXLINE)) != 0) {
		printf("server received %d bytes\n", (int)n);
		rio_writen(connfd, buf, n);
	} 
}
