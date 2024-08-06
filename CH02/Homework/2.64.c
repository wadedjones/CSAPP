/* Write code to implement the following function
 * Return 1 when any odd bit of x equals 1; 0 otherwise. Assume w = 32
 * int any_odd_one(unsigned x);
 */

#include <stdio.h>

int any_odd_one(unsigned x) { return !!(x & 0xAAAAAAAA); }

int main(void) {
  unsigned x = 0b10101010101010101010101010101010;
  unsigned y = 0b01010101010101010101010101010101;

  int a = any_odd_one(x);
  int b = any_odd_one(y);

  printf("a: %d\n", a);
  printf("b: %d\n", b);
}
