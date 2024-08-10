/* Write code for a function with the following prototype:
 *
 * Addition that saturates to TMin or TMax
 * int saturating_add(int x, int y);
 *
 * Instead of overflowing the way normal two's complement addition does,
 * saturating addition returns TMax when there would be positive overflow, and
 * TMin when there would be negative oferflow. Saturating arithmetic is commonly
 * used in programs that perform digital signal processing.
 *
 */

#include <limits.h>
#include <stdio.h>
int saturating_add(int x, int y) {
  int sum = x + y;
  int mask = INT_MIN;

  int pos_over = !(x & mask) && !(y & mask) && (sum & mask);
  int neg_over = (x & mask) && (y & mask) && !(sum & mask);

  // printf("!(x & mask): %X\n", !(x & mask));
  // printf("!(y & mask): %X\n", !(y & mask));
  // printf("(sum & mask): %X\n", (sum & mask));
  // printf("(x & mask): %X\n", (x & mask));
  // printf("(y & mask): %X\n", (y & mask));
  // printf("!(sum & mask): %X\n", !(sum & mask));
  // printf("pos_over: %X\n", pos_over);
  // printf("neg_over: %X\n", neg_over);

  (pos_over && (sum = INT_MAX) || neg_over && (sum = INT_MIN));

  return sum;
}

int main(void) {
  int x = 0x123;
  int y = 0x01234567;

  int z = saturating_add(x, y);

  printf("z: %X\n", z);

  return 0;
}
