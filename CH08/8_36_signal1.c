/* WARNING: This code is buggy! */

#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>


#define MAXBUF   8192  /* Max I/O buffer size */

void handler1(int sig) {
	int olderrno = errno;

	if ((waitpid(-1, NULL, 0)) < 0) {
		write(STDOUT_FILENO, "signal error", 13);
		_exit(1);
	}
	write(STDOUT_FILENO, "Handler reaped child\n", 21);
	int rc;
	if ((rc = sleep(1)) < 0) {
		fprintf(stderr, "sleep error: %s\n", strerror(errno));
		exit(0);
	}
	errno = olderrno;
}

pid_t Fork(void) 
{
    pid_t pid;

	if ((pid = fork()) < 0) {
		fprintf(stderr, "fork error: %s\n", strerror(errno));
		exit(0);
	}
    return pid;
}

int main(void) {
	int i, n;
	char buf[MAXBUF];

	if (signal(SIGCHLD, handler1) == SIG_ERR) {
		fprintf(stderr, "signal error: %s\n", strerror(errno));
		exit(0);
	}

	/* Parent creates children */
	for (i = 0; i < 3; i++) {
		if (Fork() == 0) {
			printf("Hello from child %d\n", (int)getpid());
			exit(0);
		}
	}

	/* Parent waits for terminal input and then processes it */
	if ((n = read(STDIN_FILENO, buf, sizeof(buf))) < 0) {
		fprintf(stderr, "read: %s\n", strerror(errno));
		exit(0);
	}

	printf("Parent processing input\n");
	while (1)
		;

	exit(0);
}
