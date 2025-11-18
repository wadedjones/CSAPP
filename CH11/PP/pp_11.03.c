/* Write a program that converts its dotted-decimal argument to a hex number and prints the result. */

#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	struct in_addr inaddr;
	if (argc != 2) {
		fprintf(stderr, "usage: dd2hex <decimal num>\n");
		exit(EXIT_FAILURE);
	}

	if ((inet_pton(AF_INET, argv[1], &inaddr)) < 1) {
		fprintf(stderr, "inet_pton error.\n");
		exit(EXIT_FAILURE);
	}

	printf("0x%x\n", ntohl(inaddr.s_addr));

	return 0;
}
