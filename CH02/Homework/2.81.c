/* Write C expressions to generate the bit patterns that follow, where a^k
 * represents k repetitions of symbol a. Assume a w-bit data type. Your code may
 * contain references to paramters j and k, representing the values of j and k,
 * but not a parameter representing w.
 *
 * A. 1^(w-k)0^k
 * B. 0^(w-k-j)1^k0^j
 *
 */

#include <stdio.h>
#define k 10
#define j 20

int main(void) {
  int size = sizeof(int) << 3;
  int a = 0;
  int b = 0;

  // A. 1111 1111 1111 1111 1111 1100 0000 0000
  a = ~a << k;
  printf("a: %X\n", a);

  // B. 0011 1111 1111 0000 0000 0000 0000 0000
  b = (unsigned)~b << (j + (size - k - j)) >> (size - k - j);
  printf("b: %X\n", b);

  return 0;
}
