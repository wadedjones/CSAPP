/* using waitpid() to reap zombie children in the order they were created */

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

#define N 10

pid_t Fork(void) {
    pid_t pid;

    if ((pid = fork()) < 0) {
        fprintf(stderr, "fork error: %s\n", strerror(errno));
        exit(0);
    }
    return pid;
}

int main(void) {
	int status;
	pid_t pid[N], retpid;

	/* parent creates N children */
	for (int i = 0; i < N; i++) {
		if ((pid[i] = Fork()) == 0) {
			exit(100 + i);
		}
	}

	/* parent reaps N children in order */
	int i = 0;
	while ((retpid = waitpid(pid[i++], &status, 0)) > 0) {
		if (WIFEXITED(status)) {
			printf("child %d terminated normally with exit status=%d\n", retpid, WEXITSTATUS(status));
		} else {
			printf("child %d terminated abnormally\n", retpid);
		}
	}

	/* the only normal termination is if there are no more children */
	if (errno != ECHILD) {
		fprintf(stderr, "waitpid error: %s\n", strerror(errno));
		exit(1);
	}

	exit(0);
}

