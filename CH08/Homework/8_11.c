/* QUESTION: How many "hello" output lines does this program print? */
/* ANSWER: 4 */

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

int main(void) {
	int i;

	for (i = 0; i < 2; i++) {
		Fork();
	}
	printf("hello\n");
	exit(0);
}
