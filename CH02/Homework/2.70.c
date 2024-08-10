/* Write code for the function with the following prototype:
 *
 * Return 1 when x can be represented as an n-bit, 2's-complement number; 0
 * otherwise Assume 1 <= n <= w
 *
 * int fits_bits(int x, int n);
 */

#include <assert.h>
#include <stdio.h>
int fits_bits(int x, int n) {
  // if shifting by offset left then right is equal to x, it fits
  int w = sizeof(int) << 3;
  int offset = w - n;

  return ((x << offset) >> offset) == x;
}

int main(void) {
  assert(!fits_bits(0xFF, 8));
  assert(!fits_bits(~0xFF, 8));

  assert(fits_bits(0b0010, 3));
  assert(!fits_bits(0b1010, 3));
  assert(!fits_bits(0b0110, 3));

  assert(fits_bits(~0b11, 3));
  assert(!fits_bits(~0b01000011, 3));
  assert(!fits_bits(~0b111, 3));
  return 0;
}
