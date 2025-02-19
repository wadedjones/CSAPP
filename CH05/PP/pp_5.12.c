/* rewrite the code for psum1 so that it does not need to repeatedly
* retrieve the value of p[i] from memory */

/* original psum1 code */
void psum1(float a[], float p[], long n) {
	long i;
	p[0] = a[0];
	for (i = 1; i < n; i++)
		p[i] = p[i - 1] + a[i];
}

void psum2(float a[], float p[], long n) {
	long i;
	p[0] = a[0];

	/* last_val = p[i - 1], val = p[i] */
	float val;
	float last_val = p[0] = a[0];
	for (i = 1; i < n; i++) {
		val = last_val + a[i];
		p[i] = val;
		last_val = val;
	}
}
