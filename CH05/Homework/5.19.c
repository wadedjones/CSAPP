/* Rewrite Practice Problem 5.12 to reduce CPE time even more */

/* Initial psum1 */
void psum1(float a[], float p[], long n) {
        long i;
        p[0] = a[0];
        for (i = 1; i < n; i++)
                p[i] = p[i - 1] + a[i];
}

/* faster implementation using loop unrolling and reassociation */
void psum3(float a[], float p[], long n) {
	long i;
	float val, last_val;
	float tmp, tmp1, tmp2, tmp3;
	last_val = p[0] = a[0];

	for (i = 1; i < n - 3; i += 4) {
		tmp = last_val + a[i];
		tmp1 = tmp + a[i + 1];
		tmp2 = tmp1 + a[i + 2];
		tmp3 = tmp2 + a[i + 3];

		p[i] = tmp;
		p[i + 1] = tmp1;
		p[i + 2] = tmp2;
		p[i + 3] = tmp3;

		last_val += (a[i] + a[i + 1] + a[i + 2] + a[i + 3]);
	}

	for (; i < n; i++) {
		last_val += a[i];
		p[i] = last_val;
	}
}
