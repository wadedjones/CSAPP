/* QUESTION: How many lines of output does the following function print?
 * give your answer as a function of n. Assume n >= 1 */
/* ANSWER: 2^n */

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

void foo(int n) {
	int i;

	for (i = 0; i < n; i++) {
		Fork();
	}
	printf("hello\n");
	exit(0);
}

int main(void) {
	int n = 3;
	foo(n);
	return 0;
}
