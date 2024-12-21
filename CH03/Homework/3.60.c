// assembly code to c code
//
// A. Which registers hold program values x, n, result, and mask?
// x in %rdi, n in %cl(%rcx), result in %rax, mask in %rdx
// B. What are the initial values of result and mask?
// result = 0, mask = 1
// C. What is the test condition for mask?
// mask != 0
// D. How does mask get updated?
// mask <<= n
// E. How does result get updated?
// result |= (x & mask)
// F. Fill in all the missing parts of the C code.

long loop(long x, long n) {
  long result = 0;
  long mask;
  for (mask = 1; mask != 0; mask <<= n) {
    result |= (x & mask);
  }

  return result;
}
