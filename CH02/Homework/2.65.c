/* Write code to implement the following function:
 * Return 1 when x contains an odd number of 1s; 0 otherwise. Assume w = 32
 * int odd_ones(unsigned x);
 *
 * Function should contain a total of at most 12 arithmetic, bitwise, and
 * logical operations
 */

#include <stdio.h>
int odd_ones(unsigned x) {
  x ^= x >> 16;
  x ^= x >> 8;
  x ^= x >> 4;
  x ^= x >> 2;
  x ^= x >> 1;
  return x & 0x1;
}

int main(void) {
  unsigned x1 = 0b10001100000000000000000000000000;
  unsigned x2 = 0b00000000000000000000000000000000;

  int a = odd_ones(x1);
  int b = odd_ones(x2);

  printf("a: %d\n", a);
  printf("b: %d\n", b);

  return 0;
}
