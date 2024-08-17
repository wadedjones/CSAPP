/* Fill in the return value to check whether the first argument is less than or
 * equal to the second argument */

#include <assert.h>
unsigned f2u(float x) { return *(unsigned *)&x; }

int float_le(float x, float y) {
  unsigned ux = f2u(x);
  unsigned uy = f2u(y);

  /* Get sign bits */
  unsigned sx = ux >> 31;
  unsigned sy = uy >> 31;

  return (ux << 1 == 0 && uy << 1 == 0) || (sx && !sy) ||
         (!sx && !sy && ux <= uy) || (sx && sy && ux >= uy);
}

int main(void) {
  assert(float_le(-0, +0));
  assert(float_le(+0, -0));
  assert(float_le(0, 3));
  assert(float_le(-4, -0));
  assert(float_le(-4, 4));

  return 0;
}
