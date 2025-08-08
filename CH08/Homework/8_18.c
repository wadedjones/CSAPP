/* QUESTION: Determine which of the following outputs are possible.
 * A. 112002
 * B. 211020
 * C. 102120
 * D. 122001
 * E. 100212
 *
 * ANSWER: A, C, E */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

pid_t Fork(void) {
	pid_t pid;

	if ((pid = fork()) < 0) {
		fprintf(stderr, "fork error\n");
		exit(0);
	}
	return pid;
}

void end(void) {
	printf("2"); fflush(stdout);
}

int main(void) {
	if (Fork() == 0) {
		atexit(end);
	}
	if (Fork() == 0) {
		printf("0"); fflush(stdout);
	} else {
		printf("1"); fflush(stdout);
	}
	exit(0);
}
