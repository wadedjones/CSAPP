/* write C code for the following assembly code
 *
 * decode1:
 * 	movq (%rdi), %r8
 * 	movq (%rsi), %rcx
 * 	movq (%rdx), %rax
 * 	movq %r8, (%rsi)
 * 	movq %rcx, (%rdx)
 * 	movq %rax, (%rdi)
 */

void decode1(long *xp, long *yp, long *zp) {
  long temp1 = *xp;
  long temp2 = *yp;
  long temp3 = *zp;
  *yp = temp1;
  *zp = temp2;
  *xp = temp3;
}
