/* Write a wrapper function for sleep, called snooze with the following
 * interface: unsigned int snooze(unsigned int secs);
 */

#include <stdio.h>
#include <unistd.h>

unsigned int snooze(unsigned int secs) {
	unsigned int total_time = sleep(secs);
	printf("Slept for %u of %u secs.\n", secs - total_time, secs);
	return total_time;
}

int main(void) {
	unsigned int secs = 5;

	snooze(5);

	return 0;
}
