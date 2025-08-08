#include <signal.h>
#include <stdio.h>
#include <unistd.h>

int func(int num) {
	int i;
	for (i = 0; i < num; i++) {
		printf("%d\n", i);
		sleep(1);
	}

	return i;
}

void sigint_handler(int sig) {
	return;
}

int main(void) {

	if (signal(SIGINT, sigint_handler) == SIG_ERR) {
		_exit(0);
	}

	int i = func(100);

	printf("i: %d\n", i);

	return 0;
}
