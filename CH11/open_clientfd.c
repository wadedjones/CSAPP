#include <netdb.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int open_clientfd(char *hostname, char *port) {
	int clientfd;
	struct addrinfo hints, *listp, *p;
	int ai;

	/* get a list of potential server addresses */
	memset(&hints, 0, sizeof(struct addrinfo));
	hints.ai_socktype = SOCK_STREAM; /* open a connection */
	hints.ai_flags = AI_NUMERICSERV; /* using a numeric port arg */
	hints.ai_flags |= AI_ADDRCONFIG; /* recommended for connections (why?) */

	if ((ai = getaddrinfo(hostname, port, &hints, &listp)) != 0) {
		fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(ai));
		exit(0);
	}

	/* walk the list for one that we can successfully connect to */
	for (p = listp; p; p = p->ai_next) {
		/* create a socket descriptor */
		if ((clientfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) < 0) {
			continue; /* socket failed, try again */
		}

		/* connect to the server */
		if (connect(clientfd, p->ai_addr, p->ai_addrlen) != -1) {
			break;
		}

		close(clientfd); /* connect failed, try another */
	}

	freeaddrinfo(listp);
	if (!p) {
		return -1;
	}

	return clientfd;
}
