/* Write a version of fgets that times out after 5 seconds tfgets */

#include <errno.h>
#include <setjmp.h>
#include <signal.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFSIZE 8024

sigjmp_buf buf;

void handler(int sig) {
	siglongjmp(buf, 1);
}
char *tfgets(char *restrict s, size_t size, FILE *restrict stream) {
	if (!sigsetjmp(buf, 1)) {
		alarm(5);
		if (signal(SIGALRM, handler) == SIG_ERR) {
			fprintf(stderr, "set alarm handler error: %s\n", strerror(errno));
			exit(0);
		}
		return fgets(s, size, stream);
	} else {
		return NULL;
	}
}

int main(int argc, char **argv) {
	FILE *fp;

	if (argc != 2) {
		fp = stdin;
	} else {
		if ((fp = fopen(argv[1], "r")) == NULL) {
			fprintf(stderr, "Cannot open file: %s\n", argv[1]);
			exit(1);
		}
	}

	char buf[BUFSIZE];
	char *input = tfgets(buf, BUFSIZE, fp);

	if (input != NULL) { 
		printf("buf: %s", buf);
	} else {
		printf("NULL\n");
	}

	exit(0);
}
