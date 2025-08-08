#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(void) {
    pid_t pid;
    int x = 1;

    if ((pid = fork()) < 0) {
        fprintf(stderr, "fork error: %s\n", strerror(errno));
        exit(0);
    }

	if (pid == 0) {
		printf("child : x=%d\n", ++x);
		exit(0);
	}

	/* parent */
	printf("parent: x=%d\n", --x);
	
	return 0;
}
