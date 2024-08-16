/* Suppose we want to compute the complete 2w-bit representation of x * y, where
 * both x and y are unsigned, on a machine for which data type unsigned is w
 * bits. The low-order w bits of the product can be computed with the expression
 * x * y, so we only require a procedure with prototype:
 *
 * unsigned unsigned_high_prod(unsigned x, unsigned y);
 *
 * that computes the high-order w its of x * y for unsigned variables.
 * We have access to a library function with prototype:
 *
 * int signed_high_prod(int x, int y);
 *
 * that computes the high-order w bits of x * y for the case where x and y are
 * in two's complement form. Write code calling this porcedure to implement the
 * function for unsigned arguments. Justify the correctness of your solution.
 *
 */

#include <stdint.h>

int signed_high_prod(int x, int y) {
  int64_t result = x * y;
  return result >> 32;
}

unsigned unsigned_high_prod(unsigned x, unsigned y) {
  int sign_x = x >> 31;
  int sign_y = y >> 31;
  int signed_prod = signed_high_prod(x, y);
  return signed_prod + x * sign_y + y * sign_x;
}

// another version found online
unsigned unsigned_high_prod_2(unsigned x, unsigned y) {
  uint64_t mul = (uint64_t)x * y;
  return mul >> 32;
}
