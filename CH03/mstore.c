/* example program to examine the assembly code output of the gcc compiler */

long mult2(long, long);

void multstore(long x, long y, long *dest) {
  long t = mult2(x, y);
  *dest = t;
}
