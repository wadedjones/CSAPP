/* example program for using the kill signal */

#include <errno.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

pid_t Fork(void);

int main(void) {
    pid_t pid;

	if ((pid = Fork()) == 0) {
		pause(); /* wait for a signal to arrive */
		printf("control should never reach here\n");
		exit(0);
	}

    /* parent sends a SIGKILL signal to a child */
    int rc;
    if ((rc = kill(pid, SIGKILL)) < 0) {
        fprintf(stderr, "kill: %s\n", strerror(errno));
        exit(1);
    }

    return 0;
}

pid_t Fork(void) {
	pid_t pid;
    if ((pid = fork()) < 0) {
        fprintf(stderr, "fork error: %s\n", strerror(errno));
        exit(1);
    }

	return pid;
}
