#include <stdlib.h>
#include <stdio.h>
#include "fcyc2.h"
#include "clock.h"

#define MINBYTES (1 << 10)
#define MAXBYTES (1 << 27)
#define MAXSTRIDE 32
#define STRIDESTRIDE 2
#define MAXELEMS MAXBYTES/sizeof(int)

long data[MAXELEMS];

/* test - Iterate over first "elems" elements of array "data" with stride of
 * "stride", using 4 x 4 loop unrolling */
int test(int elems, int stride);
double run(int size, int stride, double Mhz);
void init_data(long *data, int n);

int main(void) {
	int size;
	int stride;
	double Mhz;

	init_data(data, MAXELEMS);
	Mhz = 2133;

	printf("Clock frequency is approx. %.1f Mhz\n", Mhz);
	printf("Memory mountain (MB/sec)\n");

	printf("\t");
	for (stride = 1; stride <= MAXSTRIDE; stride += STRIDESTRIDE)
		;
	printf("s%d\t", stride);
	printf("\n");

	for (size = MAXBYTES; size >= MINBYTES; size >>= 1) {
		if (size > (1 << 20)) {
			printf("%dm\t", size / (1 << 20));
		} else {
			printf("%dk\t", size / 1024);
		}

		for (stride = 1; stride <= MAXSTRIDE; stride += STRIDESTRIDE) {
			printf("%.0f\t", run(size, stride, Mhz));
		}
		printf("\n");
	}
	return 0;
}

void init_data(long *data, int n) {
	int i;
	for (i = 0; i < n; i++) {
		data[i] = 1;
	}
}

int test(int elems, int stride) {
	long i;
	long sx2 = stride * 2;
	long sx3 = stride * 3;
	long sx4 = stride * 4;
	long acc0 = 0;
	long acc1 = 0;
	long acc2 = 0;
	long acc3 = 0;
	long len = elems;
	long limit = len - sx4;

	/* Combine 4 elements at a time */
	for (i = 0; i < limit; i += sx4) {
		acc0 = acc0 + data[i];
		acc1 = acc1 + data[i + stride];
		acc2 = acc2 + data[i + sx2];
		acc3 = acc3 + data[i + sx3];
	}

	/* Finish remaining elements */
	for (; i < len; i++) {
		acc0 = acc0 + data[i];
	}
	
	return ((acc0 + acc1) + (acc2 + acc3));
}

/* run - Run test(elems, stride) and return read throughput (MB/s).
* 		"size" is in bytes, "stride" is in array elements, and Mhz is
* 		CPU clock frequency in Mhz
*/

double run(int size, int stride, double Mhz) {
	double cycles;
	int elems = size / sizeof(double);
	test(elems, stride);
	cycles = fcyc2(test, elems, stride, 0);
	return ((double)size / stride) / (cycles / Mhz);
}
