/* Modify figure 8.18 so the children terminate abnormally 
 * use psignal() to display the error message */

#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

pid_t Fork(void) {
	pid_t pid;

	if ((pid = fork()) < 0) {
		fprintf(stderr, "Fork error: %s\n", strerror(errno));
		exit(0);
	}
	return pid;
}

#define N 2

int main(void) {
	int status, i;
	pid_t pid;

	/* Parent creates N children */
	for (i = 0; i < N; i++) {
		if ((pid = Fork()) == 0) {
			char *c = NULL;
			*c = 'l';
		}
	}

	/* Parent reaps N children in no particular order */
	while ((pid = waitpid(-1, &status, 0)) > 0) {
		if (WIFEXITED(status)) {
			printf("child %d terminated normally with exit status = %d\n", pid, WEXITSTATUS(status));
		} else {
			char buf[1024];
			sprintf(buf, "child %d terminated by signal %d", pid, WTERMSIG(status));
			psignal(WTERMSIG(status), buf); 
		}
	}

	/* The only normal termination is if there are nor more children */
	if (errno != ECHILD) {
		fprintf(stderr, "Waitpid error: %s\n", strerror(errno));
		exit(0);
	}
	exit(0);
}
