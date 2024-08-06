/* Write code to implement the following function:
 * Generate mask indicating leftmost 1 in x. Assume w = 32.
 * For example, 0xFF00 -> 0x8000, and 0x6600 -> 0x4000.
 * If x = 0, then return 0;
 *
 * int leftmost_one(unsigned x);
 */

#include <stdio.h>
int leftmost_one(unsigned x) {
  // logical |= up to w/2 (32/2 = 16) makes all bits after leading bit 1's
  x |= x >> 1;
  x |= x >> 2;
  x |= x >> 4;
  x |= x >> 8;
  x |= x >> 16;
  // shifting by 1 then adding 1 makes leading bit 1 and all other bits 0
  // add 1 only if x is nonzero
  return (x >> 1) + (x && 0x1);
}

int main(void) {
  unsigned x = 0x6600;

  unsigned y = leftmost_one(x);

  printf("y: %X\n", y);

  return 0;
}
