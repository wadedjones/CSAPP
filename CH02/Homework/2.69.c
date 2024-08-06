/* Write code for a function with the following prototype:
 * Do rotating left shift. Assume 0 <= n < w
 * Examples when x = 0x12345678 and w = 32:
 * n = 4 -> 0x23456781, n = 20 -> 0x67812345
 *
 * unsigned rotate_left(unsigned x, int n);
 */

#include <stdio.h>
unsigned rotate_left(unsigned x, int n) {
  int w = sizeof(int) << 3;
  return (x << n) | (x >> (w - n));
}

int main(void) {
  unsigned x = 0x12345678;

  unsigned y = rotate_left(x, 4);
  unsigned z = rotate_left(x, 20);

  printf("y: %X\n", y);
  printf("z: %X\n", z);

  return 0;
}
