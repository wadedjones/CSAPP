/* what is the output of the child process?
 *  what is the output of the parent process?
 */
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

pid_t Fork(void);

int main(void) {
    int x = 1;

	if (Fork() == 0)
		printf("p1: x=%d\n", ++x);
	printf("p2: x=%d\n", --x);

	exit(0);
}

pid_t Fork(void) {
    pid_t pid;

    if ((pid = fork()) < 0) {
        fprintf(stderr, "fork error: %s\n", strerror(errno));
        exit(0);
    }
    return pid;
}
