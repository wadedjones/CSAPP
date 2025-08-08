/* Explain the bug for why the counter always has a value of 2 */
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

typedef void handler_t(int);

handler_t *Signal(int signum, handler_t *handler) {
    struct sigaction action, old_action;

    action.sa_handler = handler;  
    sigemptyset(&action.sa_mask); /* Block sigs of type being handled */
    action.sa_flags = SA_RESTART; /* Restart syscalls if possible */

    if (sigaction(signum, &action, &old_action) < 0) {
		fprintf(stderr, "Signal Error: %s\n", strerror(errno));
		exit(0);
	}
    return (old_action.sa_handler);
}

void Kill(pid_t pid, int signum) {
    int rc;

    if ((rc = kill(pid, signum)) < 0) {
		fprintf(stderr, "Kill error: %s\n", strerror(errno));
		exit(0);
	}
}

pid_t Fork(void) {
    pid_t pid;

    if ((pid = fork()) < 0) {
		fprintf(stderr, "Fork error: %s\n", strerror(errno));
		exit(0);
	}
    return pid;
}

pid_t Wait(int *status) {
    pid_t pid;

    if ((pid  = wait(status)) < 0) {
		fprintf(stderr, "Wait error: %s\n", strerror(errno));
		exit(0);
	}
    return pid;
}

int counter = 0;

void handler(int sig) {
	counter++;
	//sleep(1); /* Do some work in the handler */
	return;
}

int main(void) {
	int i;

	Signal(SIGUSR2, handler);

	if (Fork() == 0) {
		for (i = 0; i < 5; i++) {
			Kill(getppid(), SIGUSR2);
			printf("sent SIGUSR2 to parent\n");
		}
		exit(0);
	}

	Wait(NULL);
	printf("counter = %d\n", counter);
	exit(0);
}
