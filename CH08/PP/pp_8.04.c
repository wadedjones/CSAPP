/* how many output lines does this program generate?
* what is one possible ordering of these output lines?
*/

#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

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
	pid_t pid;

	printf("hello\n");
	pid = Fork();
	printf("pid: %d, !pid: %d\n", pid, !pid);
	if (pid != 0) {
		if (waitpid(-1, &status, 0) > 0) {
			if (WIFEXITED(status) != 0) {
				printf("exitstatus: %d\n", WEXITSTATUS(status));
			}
		}
	}
	printf("bye\n");
	exit(2);
}
