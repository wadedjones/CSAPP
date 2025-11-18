#include "open_fd.h"
#include "r_io.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
	int clientfd;
	char *host, *port;
	char buf[MAXLINE];

	rio_t rio;

	if (argc != 3) {
		fprintf(stderr, "usage: %s <host> <port>\n", argv[0]);
		exit(1);
	}

	host = argv[1];
	port = argv[2];

	if ((clientfd = open_clientfd(host, port)) < 0) {
		fprintf(stderr, "open_clientfd failed\n");
		exit(1);
	}

	rio_readinitb(&rio, clientfd);

	while (fgets(buf, MAXLINE, stdin) != NULL) {
		rio_writen(clientfd, buf, strlen(buf));
		rio_readlineb(&rio, buf, MAXLINE);
		fputs(buf, stdout);
	}

	close(clientfd);
	exit(0);
}
