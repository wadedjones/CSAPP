/* You are given the task of writing a procedure int_size_is_32() that yields 1
 * when run on a machine for which an int is 32 bits, and yields 0 otherwise.
 * you are not allowed to use the sizeof operator. Here is a first attempt:
 */

int bad_int_size_is_32(void) {
  // set most significant bit
  int set_msb = 1 << 31;
  // set beyond most significant bit
  int beyond_msb = 1 << 32;

  return set_msb && !beyond_msb;
}

int int_size_is_32(void) {
  int set_msb = 1 << 31;
  // fixes the width error
  int beyond_msb = set_msb << 1;

  return set_msb && !(beyond_msb);
}

int int_size_is_16(void) {
  int set_msb = 1 << 15;
  int beyond_msb = set_msb << 1;

  return set_msb && !(beyond_msb);
}
