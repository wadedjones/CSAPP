#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 1024

int main(int argc, char **argv) {
	struct addrinfo *p, *listp, hints; /* netdb.h */
	char buf[MAXLINE];
	int rc, flags;

	if (argc != 2) {
		fprintf(stderr, "usage: %s <domain name>\n", argv[0]);
		exit(1);
	}

	/* get a list of addrinfo records */
	memset(&hints, 0, sizeof(struct addrinfo));
	hints.ai_family = AF_INET; /* IPv4 only */
	hints.ai_socktype = SOCK_STREAM; /* connections only */
	if ((rc = getaddrinfo(argv[1], NULL, &hints, &listp)) != 0) {
		fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(rc));
		exit(1);
	}

	/* walk the list and display each IP address */
	flags = NI_NUMERICHOST; /* display address string instead of domain name */
	for (p = listp; p; p = p->ai_next) {
		getnameinfo(p->ai_addr, p->ai_addrlen, buf, MAXLINE, NULL, 0, flags);
		printf("%s\n", buf);
	}

	freeaddrinfo(listp);

	exit(0);
}
