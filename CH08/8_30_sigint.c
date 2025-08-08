#include <errno.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/* SIGINT handler */
void sigint_handler(int sig) {
	printf("Caught SIGINT!\n");
	exit(0);
}

int main(void) {
	/* install the SIGINT handler */
	if (signal(SIGINT, sigint_handler) == SIG_ERR) {
		fprintf(stderr, "signal error: %s\n", strerror(errno));
		exit(0);
	}

	pause(); /* wait for the receipt of the signal */

	return 0;
}
