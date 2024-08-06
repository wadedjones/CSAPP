/* Fill in the code for the following C funtions Function srl performs a logical
 * right shift using an arithmetic right shift (given by value xsra), followed
 * by other operations not including right shifts or division. Function sra
 * performs an arithmetic right shift using logical right shift (given by value
 * xsrl), followed by other operations not including right shifts or division.
 * You may use the computation 8*sizeof(int) to determine w, the number of bits
 * in data type int. The shift amount k can range from 0 to w - 1. */

#include <stdio.h>

unsigned srl(unsigned x, int k) {
  /* perform shift arithmetically */
  unsigned xsra = (int)x >> k;
  /* to do ... */
  int w = sizeof(int) << 3;
  int mask = ((int)-1 << (w - k));
  return xsra & ~mask;
}

int sra(int x, int k) {
  /* perform shift logically */
  int xsrl = (unsigned)x >> k;
  /* xsrl = 0000 0000 0010 0000 0000 0000 0010 0011 */
  printf("xsrl: %x\n", xsrl);
  /* to do ... */
  int w = sizeof(int) << 3;
  printf("w: %x\n", w);
  /* mask (if 32 bits)  1111 1111 1111 1111 1111 1111 1111 1111
   * << (w-k) if (k=10) 1111 1111 1100 0000 0000 0000 0000 0000
   * */
  int mask = ((int)-1 << (w - k));
  printf("mask1: %x\n", mask);
  /* if x2 = 1000 0000 0000 0000 1000 1111 0000 0000
   *
   * mask =               1111 1111 1100 0000 0000 0000 0000 0000
   *
   * x2 =                 1000 0000 0000 0000 1000 1111 0000 0000
   * 1<<w(31) =           1000 0000 0000 0000 0000 0000 0000 0000
   * x2 & 1<<w(31) =      1000 0000 0000 0000 0000 0000 0000 0000
   * !x2 & 1<<w(31) =     0000 0000 0000 0000 0000 0000 0000 0000
   * !x2 & 1<<w(31) - 1 = 1111 1111 1111 1111 1111 1111 1111 1111
   * mask & (above) =     1111 1111 1100 0000 0000 0000 0000 0000
   * */
  mask = mask & (!(x & (1 << (w - 1))) - 1);
  printf("x2 & 1<<w-1: %x\n", (x & (1 << (w - 1))));
  printf("!x2 & 1<<w-1: %x\n", (!(x & (1 << (w - 1)))) - 1);
  printf("mask2: %x\n", mask);
  /* mask = 1111 1111 1100 0000 0000 0000 0000 0000
   * xsrl = 0000 0000 0010 0000 0000 0000 0010 0011
   *     |= 1111 1111 1110 0000 0000 0000 0010 0011
   * */
  printf("xsrl end: %X\n", xsrl);
  return mask | xsrl;
}

int main(void) {
  unsigned x1 = 0x80FFFFFF;
  int x2 = 0b00000000000000001000111100000000;
  printf("x2: %x\n", x2);
  printf("x2: %d\n", x2);
  x2 = sra(x2, 10);

  // printf("%d: %d\n", x1, srl(x1, 10));
  printf("%x\n", x2);
  printf("%d\n", x2);

  return 0;
}
