/* A function fun_a has the following overall structure:
 * long fun_a(unsigned long x) {
 * 	long val = 0;
 * 	while ( ... ) {
 * 		.
 * 		.
 * 		.
 * 	}
 * 	return ...;
 * }
 *
 * gcc generates the following assembly:
 *
 * fun_a:
 * 	movl	$0, %eax		// move 0 into rax
 * 	jmp		.L5
 * .L6:
 * 	xorq	%rdi, %rax	// rax ^= x
 * 	shrq	%rdi				// x >> 1
 * .L5:
 * 	testq	%rdi, %rdi	// test x
 * 	jne		.L6					// x != 0 ?
 * 	andl	$1, %eax		// rax &= 1
 * 	ret
 *
 * A. Determine what loop translation method was used.
 * Jump to middle
 *
 * B. Use the assembly-code version to fill in the missing parts of the C code.
 * I think I did it?
 *
 * C. Describe in English what this function computes.
 * Code computes the parity of x. Returns 1 if there is an odd
 * number of 1's in x and 0 if there is an even number.
 *
 */

long fun_a(unsigned long x) {
  long val = 0;
  while (x) {
    val ^= x;
    x >>= 1;
  }

  return val & 1;
}
