/* A. What value does rfun store in the callee-saved register %rbx?
 *
 * B. Fill in the missing expressions in the C Code shown.
 *
 * Assembly of rfun:
 *
 * rfun:
 * 	pushq		%rbx
 * 	movq		%rdi, %rbx
 * 	movl		$0, %eax
 * 	testq		%rdi, %rdi
 * 	je			.L2
 * 	shrq		$2, %rdi
 * 	call		rfun
 * 	addq		%rbx, %rax
 * .L2:
 * 	popq		%rbx
 * 	ret
 *
 */

long rfun(unsigned long x) {
  if (x == 0) {
    return 0;
  }
  unsigned long nx = x >> 2;
  long rv = rfun(nx);
  return x + rv;
}
