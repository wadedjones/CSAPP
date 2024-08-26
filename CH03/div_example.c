/* example for dividing two numbers and accessing the assembly code in objdump
 */

void remdiv(long x, long y, long *qp, long *rp) {
  long q = x / y;
  long r = x % y;
  *qp = q;
  *rp = r;
}

void uremdiv(unsigned long x, unsigned long y, unsigned long *qp,
             unsigned long *rp) {
  unsigned long q = x / y;
  unsigned long r = x % y;
  *qp = q;
  *rp = r;
}
