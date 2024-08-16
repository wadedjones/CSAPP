/* Write a function with the following prototype:
 *
 * Determine wheter arguments can be subtracted without overflow
 * int tsub_ok(int x, int y);
 *
 * This function should return 1 if the computation x-y does not overflow.
 */

#include <limits.h>
#include <stdio.h>

int tsub_ok(int x, int y) {
  int result = x - y;
  // if x is positive, y is negative and result is negative == 1
  int pos_over = !(x >> 31) && (y >> 31) && (result >> 31);
  // if x is negative, y is positive and result is positive == 1
  int neg_over = (x >> 31) && !(y >> 31) && !(result >> 31);
  // if y == TMin (0x80000000)
  int y_is_TMin = !(y ^ (1 << 31));

  return !(y_is_TMin) && !(pos_over || neg_over);
}

int main(void) {
  int x = 0x1234;
  int y = 0x80000000;
  int z = tsub_ok(x, y);

  printf("z: %X\n", z);

  return 0;
}
