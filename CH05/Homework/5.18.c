/* Practice problems 5.5 and 5.6 consider polynomial evaluations.
 * Try to write a faster version */

#include <stdio.h>

/* initial poly method */
double poly_initial(double a[], double x, long degree) {
	long i;
	long result = a[0];
	long xpow = x;

	for (i = 1; i <= degree; i++) {
		result += a[i] * xpow;
		xpow *= x;
	}
	return result;
}

/* poly using horner's method */
double poly_horner(double a[], double x, long degree) {
	long i;
	double result = a[degree];
	for (i = degree - 1; i >= 0; i -= 2) {
		result = a[i] + x * result;
	}
	return result;
}

/* faster poly method */
double poly_fast(double a[], double x, long degree) {
	long i;
	double result = a[0];
	double xpow = x;

	for (i = 1; i <= degree - 2; i += 2) {
		result += ((a[i] * xpow) + (a[i + 1] * xpow * x));
		xpow *= x * x;
	}

	for (; i <= degree; i++) {
		result += a[i] * xpow;
		xpow *= x;
	}

	return result;
}
