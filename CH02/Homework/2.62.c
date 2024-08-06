/* Write a function int_shifts_are_arithmetic() that yields 1 when run on a
 * machine that uses arithmetic right shifts for data type int and yields 0
 * otherwise. Your code should work on a machine with any word size. */

#include <stdio.h>

int int_shifts_are_arithmetic() {
  // get size of int and multiply by 8 to get total bits (8 bits in a byte)
  int size = sizeof(int) << 3;
  // move 1 to the most significant bit
  int x = 1 << (size - 1);
  if (!~(x >> (size - 1))) {
    return 1;
  }
  return 0;
}

int main(void) {
  int x = int_shifts_are_arithmetic();

  printf("%d\n", x);
  return 0;
}
