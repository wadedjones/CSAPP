/* QUESTION: What is one possible output of the following program? */
/* ANSWER: 
 * x=4
 * x=3
 * x=2
 * */

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
	int x = 3;

	if (Fork() != 0) {
		printf("x=%d\n", ++x);
	}

	printf("x=%d\n", --x);
	exit(0);
}
