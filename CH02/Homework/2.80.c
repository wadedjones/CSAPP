/* Write code for a function threefourths that, for integer argument x, computes
 * the value of 3/4(x), rounded toward zero. It should not overflow. Your
 * function should follow the bit level coding rules */

// I had a lot of trouble with this, some help from the internet needed, sigh.

#include <limits.h>
#include <stdio.h>

int threefourths(int x) {
  int x_is_neg = x & INT_MIN;
  // first 30 bits & x
  int first = x & ~0x3;
  // last 2 bits & x
  int last = x & 0x3;

  int first_div_4 = first >> 2;
  int first_div_4_mult_3 = (first_div_4 << 1) + first_div_4;

  int last_mult_3 = (last << 1) + last;
  int bias = (1 << 2) - 1;

  (x_is_neg && (last_mult_3 += bias));
  int last_mult_3_div_4 = last_mult_3 >> 2;

  return first_div_4_mult_3 + last_mult_3_div_4;
}

int main(void) {

  printf("%d * 3/4 = %d\n", 9, threefourths(9));
  printf("%d * 3/4 = %d\n", 8, threefourths(8));
  printf("%d * 3/4 = %d\n", 12, threefourths(12));
  printf("%d * 3/4 = %d\n", -9, threefourths(-9));
  printf("%d * 3/4 = %d\n", -6, threefourths(-6));
  printf("%d * 3/4 = %d\n", -20, threefourths(-20));

  return 0;
}
