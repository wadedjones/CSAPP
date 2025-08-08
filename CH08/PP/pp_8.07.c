/* write a program called snooze that takes a single command line arg and
 * terminates when CTRL-C is typed
 */

#include <errno.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void sigint_handler(int sig) {
	return; /* catch signal and return */
}

unsigned int snooze(unsigned int secs) {
	unsigned int total_time = sleep(secs);
	printf("\nSlept for %u of %u secs.\n", secs - total_time, secs);
	return total_time;
}

int main(int argc, char **argv) {
	if (argc != 2) {
		fprintf(stderr, "usage: %s <secs>\n", argv[0]);
		exit(0);
	}
	if (signal(SIGINT, sigint_handler) == SIG_ERR) {
		fprintf(stderr, "signal error: %s\n", strerror(errno));
	}
	unsigned int secs = atoi(argv[1]);

	snooze(secs);

	return 0;
}
