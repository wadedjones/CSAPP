/* Write a C expression that will yield a word consisting of the least
 * significant byte of x and the rest of y if x = 0x89ABCDEF and y = 0x76543210,
 * this would yield 0x765432EF*/

// (x & 0xFF) | (y & ~0xFF)
#include <stdio.h>

int main(void) {
  int x = 0x89ABCDEF;
  int y = 0x76543210;

  printf("%x\n", (x & 0xFF) | (y & ~0xFF));
  return 0;
}
