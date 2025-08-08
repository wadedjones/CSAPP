/* QUESTION: How many "hello" output lines does this program print? */
/* ANSWER: 8 */

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

void doit(void) {
	Fork();
	Fork();
	printf("hello\n");
	return;
}

int main(void) {
	doit();
	printf("hello\n");
	exit(0);
}
