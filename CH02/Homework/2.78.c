/* Write code for a function with the following prototype:
 *
 * Divide by a power of 2. Assume 0 <= k < w-1
 *
 * int divide_power2(int x, int k);
 *
 * The function should compute x/2^k with correct rounding, and it should follow
 * the bit-level integer coding rules
 */
#include <limits.h>
#include <stdio.h>

int divide_power2(int x, int k) {
  int x_is_neg = x & INT_MIN;
  (x_is_neg && (x = x + (1 << k) - 1));

  return x >> k;
}

int main(void) {
  int x1 = 10;
  int x2 = -10;
  int k = 2;

  printf("x1 / k = %d\n", x1 / k);
  printf("dp2 = %d\n", divide_power2(x1, k));
  printf("x2 / k = %d\n", x2 / k);
  printf("dp2 = %d\n", divide_power2(x2, k));

  return 0;
}
