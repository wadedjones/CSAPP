/* ijk */
void mm1(int n, long c[n][n], long a[n][n], long b[n][n]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int sum = 0.0;
			for (int k = 0; k < n; k++) {
				sum += a[i][k] * b[k][j];
			}
			c[i][j] += sum;
		}
	}
}

/* jik */
void mm2(int n, long c[n][n], long a[n][n], long b[n][n]) {
	for (int j = 0; j < n; j++) {
		for (int i = 0; i < n; i++) {
			int sum = 0.0;
			for (int k = 0; k < n; k++) {
				sum += a[i][k] * b[k][j];
			}
			c[i][j] += sum;
		}
	}
}

/* jki */
void mm3(int n, long c[n][n], long a[n][n], long b[n][n]) {
	for (int j = 0; j < n; j++) {
		for (int k = 0; k < n; k++) {
			long sum = b[k][j];
			for (int i = 0; i < n; i++) {
				c[i][j] += a[i][k] * sum;
			}
		}
	}
}


/* kji */
void mm4(int n, long c[n][n], long a[n][n], long b[n][n]) {
	for (int k = 0; k < n; k++) {
		for (int j = 0; j < n; j++) {
			long sum = b[k][j];
			for (int i = 0; i < n; i++) {
				c[i][j] += a[i][k] * sum;
			}
		}
	}
}

/* kij */
void mm5(int n, long c[n][n], long a[n][n], long b[n][n]) {
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			long sum = a[i][k];
			for (int j = 0; j < n; j++) {
				c[i][j] += sum * b[k][j];
			}
		}
	}
}

/* ikj */
void mm6(int n, long c[n][n], long a[n][n], long b[n][n]) {
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			long sum = a[i][k];
			for (int j = 0; j < n; j++) {
				c[i][j] += sum * b[k][j];
			}
		}
	}
}
