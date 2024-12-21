/* A function fun_b has the following structure:
 *
 * long fun_b(unsigned long x) {
 * 	long val = 0;
 * 	long i;
 * 	for (...;...;...) {
 * 		.
 * 		.
 * 		.
 * 	}
 * 	return val;
 * }
 *
 * The GCC compiler generates the following assembly:
 *
 * fun_b:
 * 	movl	$64, %edx
 * 	movl	$0, %eax
 * .L10:
 * 	movq	%rdi, %rcx  // move x into rcx
 * 	andl	$1, %ecx		// x & 0x1 (in ecx)
 * 	addq	%rax, %rax  // doubling val ie. val << 1
 * 	orq		%rcx, %rax  // val | rcx
 * 	shrq	%rdi        // x >>= 0x1
 * 	subq	$1, %rdx    // i--
 * 	jne		.L10        // i != 0
 * 	rep;  ret
 *
 * A. Use the assembly code version to reverse engineer the C code.
 *
 * B. Explain why there is neither an initial test before the loop nor an
 * initial jump to the test portion of the loop.
 *
 * Answer: I is initialized immediately to 64, so a test isn't necessary
 *
 * C. Describe in English what this function computes
 *
 * Answer: The function reverses the bits in x
 *
 */

long fun_b(unsigned long x) {
  long val = 0;
  long i;
  for (i = 64; i > 0; i--) {
    val = (val << 1) | (x & 0x1);
    x >>= 1;
  }
  return val;
}
