/* You just started a job ... (blah blah blah) ...
 * Declaration of data type where 4 bytes are packed into an unsigned
 *
 * typedef unsigned packed_t;
 *
 * Extract byte from word. Return as signed integer
 *
 * int xbyte(packed_t word, int bytenum);
 *
 * -- Failed attempt at xbyte: --
 *  int xbyte(packed_t word, int bytenum) {
 *  	return (word >> (bytenum << 3)) & 0xFF;
 * }
 *
 * A. What is wrong with this code?
 * B. Give a correct implementation of the function that uses only left and
 * right shifts, along with one subtraction.
 */

// A. If bytenum 0, 1, or 2 are returned, the bytenums proceeding it will be
// included in the return
// B. Fix below:

#include <stdio.h>
typedef unsigned packed_t;

int xbyte(packed_t word, int bytenum) {
  int offset = (3 - bytenum) << 3;
  word = (word << offset) >> offset;

  return (word >> (bytenum << 3));
}

int main(void) {
  packed_t word = 0x82CE45F1;
  int check0 = xbyte(word, 0);
  int check1 = xbyte(word, 1);
  int check2 = xbyte(word, 2);
  int check3 = xbyte(word, 3);

  printf("check0: %X\n", check0);
  printf("check1: %X\n", check1);
  printf("check2: %X\n", check2);
  printf("check3: %X\n", check3);

  return 0;
}
