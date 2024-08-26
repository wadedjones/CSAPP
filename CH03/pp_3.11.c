/* playing with asm that generates: xorq %rdx, %rdx */

long ret_zero(long x) {
  x = 0;
  long y = 0;
  y++;
  x++;
  return x + y;
}
