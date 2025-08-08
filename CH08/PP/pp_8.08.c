/* What is the output of the following program? */

#include <errno.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

volatile long counter = 2;

pid_t Fork(void) 
{
    pid_t pid;

    if ((pid = fork()) < 0) {
		fprintf(stderr, "fork error: %s\n", strerror(errno));
		exit(0);
	}
    return pid;
}

static void sio_reverse(char s[]) {
    int c, i, j;

    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

/* sio_ltoa - Convert long to base b string (from K&R) */
static void sio_ltoa(long v, char s[], int b) {
    int c, i = 0;
    int neg = v < 0;

    if (neg)
        v = -v;

    do {
        s[i++] = ((c = (v % b)) < 10) ? c + '0' : c - 10 + 'a';
    } while ((v /= b) > 0);

    if (neg)
        s[i++] = '-';

    s[i] = '\0';
    sio_reverse(s);
}

ssize_t sio_puts(char s[]) /* Put string */
{
    return write(STDOUT_FILENO, s, strlen(s)); // line:csapp:siostrlen
}

ssize_t sio_putl(long v) /* Put long */
{
    char s[128];

    sio_ltoa(v, s, 10); /* Based on K&R itoa() */ // line:csapp:sioltoa
    return sio_puts(s);
}

void handler1(int sig) {
    sigset_t mask, prev_mask;

    if (sigfillset(&mask) < 0) {
        fprintf(stderr, "sigfillset error: %s\n", strerror(errno));
        exit(0);
    }

    if (sigprocmask(SIG_BLOCK, &mask, &prev_mask) < 0) {
        fprintf(stderr, "sigprocmask error: %s\n", strerror(errno));
        exit(0);
    }

	sio_putl(--counter);
    if (sigprocmask(SIG_SETMASK, &prev_mask, NULL) < 0) {
        fprintf(stderr, "sigprocmask error: %s\n", strerror(errno));
        exit(0);
    }

	_exit(0);
}

int main(void) {
	pid_t pid;
	sigset_t mask, prev_mask;

	printf("%ld", counter);
	fflush(stdout);

	signal(SIGUSR1, handler1);
	if ((pid = Fork()) == 0) {
		while(1) {};
	}
	int rc;
	if ((rc = kill(pid, SIGUSR1)) < 0) {
		fprintf(stderr, "kill: %s\n", strerror(errno));
		exit(0);
	}

    pid_t retpid;

    if ((retpid  = waitpid(-1, NULL, 0)) < 0)  {
		fprintf(stderr, "waitpitd error: %s\n", strerror(errno));
		exit(0);
	}

    if (sigfillset(&mask) < 0) {
        fprintf(stderr, "sigfillset error: %s\n", strerror(errno));
        exit(0);
    }
	
    if (sigprocmask(SIG_BLOCK, &mask, &prev_mask) < 0) {
        fprintf(stderr, "sigprocmask error: %s\n", strerror(errno));
        exit(0);
    }

	printf("%ld", ++counter);

    if (sigprocmask(SIG_SETMASK, &prev_mask, NULL) < 0) {
        fprintf(stderr, "sigprocmask error: %s\n", strerror(errno));
        exit(0);
    }

	exit(0);
}
