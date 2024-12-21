/* factorial function to produce asm code */

long fact(long n) {
  long result;
  if (n <= 1) {
    result = 1;
  } else {
    result = n * fact(n - 1);
  }
  return result;
}
