#include <sys/resource.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(void) {
	struct rusage usage;
	for (int i = 0; i < 10; i ++) {
		void *m = malloc(20 * 1024 * 1024);
		memset(m, 0, 20 * 1024 * 1024);
		getrusage(RUSAGE_SELF, &usage);
		printf("Memory usage: %ld\n", usage.ru_maxrss);
		sleep(3);
	}
	printf("\nAllocated memory, sleeping 10 seconds and checking again...\n");
	sleep(10);
	getrusage(RUSAGE_SELF, &usage);
	printf("Memory usage: %ld\n", usage.ru_maxrss);
	return 0;
}
