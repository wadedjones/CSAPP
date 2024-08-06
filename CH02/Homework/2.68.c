/* Write code for a function with the following prototype:
 * Mask with least significant n bits set to 1
 * Examples: n = 6 -> 0x3F, n = 17 -> 0x1FFFF
 * Assume 1 <= n <= w
 *
 * int lower_one_mask(int n);
 */

#include <stdio.h>
int lower_one_mask(int n) {
  int w = sizeof(int) << 3;
  int mask = -1;
  mask = (unsigned)mask >> (w - n);

  return mask;
}

int main(void) {
  int x = lower_one_mask(6);
  int y = lower_one_mask(17);

  printf("x: %X\n", x);
  printf("y: %X\n", y);

  return 0;
}
