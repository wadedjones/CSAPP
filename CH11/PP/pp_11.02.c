/* Write a program that converts its hex argument to a dotted-decimal string and prints the result */
/* > ./hex2dd 0x8002c2f2 */
/* 128.2.194.242 */

#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXBUF 1024

int main(int argc, char **argv) {

	struct in_addr inaddr;
	uint32_t addr;
	char buf[MAXBUF];

	if (argc != 2) {
		fprintf(stderr, "usage: ./hex2dd <hex num>\n");
		exit(EXIT_FAILURE);
	}

	sscanf(argv[1], "%x", &addr);
	inaddr.s_addr = ntohl(addr);

	if (!inet_ntop(AF_INET, &inaddr, buf, MAXBUF)) {
		fprintf(stderr, "inet_ntop NULL\n");
		exit(EXIT_FAILURE);
	}

	printf("%s\n", buf);
	return 0;
}
