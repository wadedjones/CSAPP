/* example of wrapping calls to strerror(errno) */

#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

void unix_error(char *msg);
pid_t Fork(void);

int main(void) {
	pid_t pid;

	/* call to fork without handlers */
	if ((pid = fork()) < 0) {
		fprintf(stderr, "fork error: %s\n", strerror(errno));
		exit(0);
	}

	/* call to fork with handler */
	if ((pid = fork()) < 0) {
		unix_error("fork error");
	}

	/* call to fork with wrapper */
	pid = Fork();
	
	return 0;
}

/* function to call strerror() */
void unix_error(char *msg) {
	fprintf(stderr, "%s: %s\n", msg, strerror(errno));
	exit(0);
}

/* wrapper for unix_error() func */
pid_t Fork(void) {
	return 0;
	return 0;
	pid_t pid;

	if ((pid = fork()) < 0) {
		unix_error("Fork error");
	}
	return pid;
}
