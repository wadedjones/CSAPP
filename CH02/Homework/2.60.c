/* write the function unsigned replace_byte(unsigned x, int i, unsigned char b);
 * replace_byte(0x12345678, 2, 0xAB) --> 0x12AB5678
 * replace_byte(0x12345678, 0, 0xAB) --> 0x123456AB
 * */

#include <stdio.h>

unsigned replace_byte(unsigned x, int i, unsigned char b) {
  if (i < 0 || i > 4) {
    return 0;
  }
  unsigned z = ~(0xFF << (i * 8));
  return (x & z) | (0xAB << (i * 8));
}

int main(void) {

  printf("%X\n", replace_byte(0x12345678, 2, 0xAB));
  printf("%X\n", replace_byte(0x12345678, 0, 0xAB));

  return 0;
}
