#include <stdio.h>

// this code zero's out the pointers
void swap(long *xp, long *yp) {
	*xp = *xp + *yp;
	*yp = *xp - *yp;
	*xp = *xp - *yp;
}

int main(void) {
	long x = 10;
	long *xp = &x;
	long *yp = xp;

	swap(xp, yp);

	printf("xp: %ld, yp: %ld\n", *xp, *yp);

	return 0;
}
