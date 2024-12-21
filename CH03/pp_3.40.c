/* The following C code sets the diagonal elements of an array to val. */

#define N 16
typedef int fix_matrix[N][N];

void fix_set_diag(fix_matrix A, int val) {
  long i;
  for (i = 0; i < N; i++) {
    A[i][i] = val;
  }
}

/* Create a C function that uses optimizations */

void fix_set_diag_opt(fix_matrix A, int val) {
  int *Aptr = &A[0][0];
  /* my code which is wrong
do {
*Aptr = val;
Aptr += 68;
} while (Aptr != &A[N][N]);
  */

  /* code according to the book: */
  long i = 0;
  long end = N * (N + 1);
  do {
    Aptr[i] = val;
    i += (N + 1);
  } while (i != end);
}
