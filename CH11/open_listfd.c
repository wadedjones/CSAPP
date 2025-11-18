#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define LISTENQ 1024

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
