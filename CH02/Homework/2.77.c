/* Suppose we are given the task of generating code to multiply integer variable
 * x by various different constant factors K. To be effecient, we want to use
 * only the operations +, -, and <<. For the following values of K, write C
 * expressions to perform the multiplication using at most three operations per
 * expression.
 */

// A. K = 17
// B. K = -7
// C. K = 60
// D. K = -112
#include <stdio.h>

int main(void) {
  // set x to any value
  int x = 8;

  // A.
  x = (x << 4) + x;
  printf("x: %d\n", x);

  x = 8;
  // B.
  x = (-x << 3) + x;
  printf("x: %d\n", x);

  x = 8;
  // C.
  x = (x << 6) - (x << 2);
  printf("x: %d\n", x);

  x = 8;
  // D.
  x = (-x << 7) + (x << 4);
  printf("x: %d\n", x);

  return 0;
}
