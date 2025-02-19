/* traditional implementation of the merge step of mergesort requires three loops
* rewrite the code so the first loop uses a conditional move */

/* Original merge */
void merge(long src1[], long src2[], long dest[], long n) {
	long i1 = 0;
	long i2 = 0;
	long id = 0;
	while (i1 < n && i2 < n) {
		if (src1[i1] < src2[i2])
			dest[id++] = src1[i1++];
		else
			dest[id++] = src2[i2++];
	}

	while (i1 < n)
		dest[id++] = src1[i1++];
	while (i2 < n)
		dest[id++] = src2[i2++];
}

void merge2(long src1[], long src2[], long dest[], long n) {
	long i1 = 0;
	long i2 = 0;
	long id = 0;
	while (i1 < n && i2 < n) {
		long n1 = src1[i1];
		long n2 = src2[i2];
		long diff = n1 < n2;

		dest[id++] = diff ? n1 : n2;
		i1 += diff;
		i2 += (1 - diff);
	}

	while (i1 < n)
		dest[id++] = src1[i1++];
	while (i2 < n)
		dest[id++] = src2[i2++];
}

