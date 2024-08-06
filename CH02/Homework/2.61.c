/* Write C expressions that evaluate to 1 when the following conditions are true
 * and to 0 when the are false. Assume x is of type int */
/* A. Any bit of x equals 1
 * B. Any bit of x equals 0
 * C. Any bit in the least significant byte of x equals 1
 * D. Any bit in the most significant byte of x equals 0 */
/* Your code should follow the bit restriction rules and cannot use equality
 * tests (== and !=) */

#include <stdio.h>

int main(void) {
  int x = 0xF0100000;
  // A.
  if (x & 0xFFFFFFFF) {
    printf("1\n");
  } else {
    printf("0\n");
  }

  // B.
  if (~x) {
    printf("1\n");
  } else {
    printf("0\n");
  }

  // C.
  if (x & 1) {
    printf("1\n");
  } else {
    printf("0\n");
  }

  // D.
  if (~x & 0xF0000000) {
    printf("1\n");
  } else {
    printf("0\n");
  }

  return 0;
}
