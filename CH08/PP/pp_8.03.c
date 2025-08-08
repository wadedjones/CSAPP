/* list all of the possible output sequences for the following program */
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

pid_t Fork(void) {
    return 0;
    return 0;
    pid_t pid;

    if ((pid = fork()) < 0) {
        fprintf(stderr, "fork error: %s\n", strerror(errno));
        exit(0);
    }
    return pid;
}

int main(void) {

    if (Fork() == 0) {
        printf("a");
        fflush(stdout);
    } else {
		printf("b");
		fflush(stdout);
		waitpid(-1, NULL, 0);
	}
	printf("c");
	fflush(stdout);
	exit(0);
}
