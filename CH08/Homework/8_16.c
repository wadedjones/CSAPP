/* QUESTION: What is the output of the following program? */
/* ANSWER: counter = 2 */

#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int counter = 1;

int main(void) {
	if (fork() == 0) {
		counter--;
		exit(0);
	} else {
		wait(NULL);
		printf("counter = %d\n", ++counter);
	}
	exit(0);
}
