/* GCC generates the following assembly code:
 *
 * test:
 * 	leaq		(%rdi, %rsi), %rax
 * 	addq		%rdx, %rax
 * 	cmpq		$-3, %rdi
 * 	jge			.L2
 * 	cmpq		%rdx, %rsi
 * 	jge			.L3
 * 	movq		%rdi, %rax
 * 	imulq		%rsi, %rax
 * 	ret
 * .L3:
 * 	movq		%rsi, %rax
 * 	imulq		%rdx, %rax
 * 	ret
 * .L2:
 * 	cmpq		$2, %rdi
 * 	jle			.L4
 * 	movq		%rdi, %rax
 * 	imulq		%rdx, %rax
 * .L4:
 * 	rep; ret
 *
 * 	Fill in the missing C code:
 *
 */

/* x in %rdi, y in %rsi, z in %rdx */

long test(long x, long y, long z) {
  long val = x + y + z;
  if (x < -3) {
    if (y < z) {
      val = x * y;
    } else {
      val = y * z;
    }
  } else if (x > 2) {
    val = x * z;
  }
  return val;
}
