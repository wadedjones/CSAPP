/* Write your own version of the unix system function */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

extern char **environ; /* Defined by libc */

pid_t Fork(void) {
	pid_t pid;

	if ((pid = fork()) < 0) {
		fprintf(stderr, "fork error\n");
		exit(0);
	}
	return pid;
}

int mysystem(char *command) {
	pid_t pid;
	int status;

	if ((pid = Fork()) == 0) {
		/* Child process */
		char *argv[4] = {"", "-c", command, NULL};
		execve("/bin/sh", argv, environ);
	}

	/* print child to kill it */
	printf("child pid: %d\n", pid);

	if ((waitpid(pid, &status, 0)) < 0) {
		fprintf(stderr, "waitpid error\n");
		exit(0);
	}

	/* exit normally */
	if (WIFEXITED(status)) {
		return WEXITSTATUS(status);
	}

	/* exit by signal */
	if (WIFSIGNALED(status)) {
		return WTERMSIG(status);
	}
	return 1;
}

int main(void) {
	int code;

	code = mysystem("./exit");
	printf("exit code: %d\n", code);

	code = mysystem("./signal");
	printf("signal code: %d\n", code);

	exit(0);
}
