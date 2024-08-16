/* Write code for a function mul3div4 that, for integer argument x, computes 3 *
 * x/4 but follows the bit-level integer coding rules. Your code should
 * replicate the fact that the computation 3 * x can cause overflow.
 */

#include <limits.h>

int div_power2(int x, int k) {
  int x_is_neg = x & INT_MIN;
  (x_is_neg && (x = x + (1 << k) - 1));
  return x >> k;
}

int mul3div4(int x) {
  int mult = (x << 1) + x;
  return div_power2(mult, 2);
}
