/* fill in the missing C code using this assembly:
 *
 * a in %rsi, b in %rdi, c in %rcx
 *
 * switcher:
 * 	cmpq		$7, %rdi					compare
 * b:7 ja			.L2
 * jump if b > 7 jmp			*.L4(,%rdi,8) .section		.rodata
 * .L7:
 * 	xorq		$15, %rsi					 a ^=
 * 0xF movq		%rsi, %rdx				 move a into rdx
 * .L3:
 * 	leaq		112(%rdx), %rdi 	 a += 112, val = a;
 * 	jmp			.L6
 * .L5:
 * 	leaq		(%rdx,%rsi), %rdi  val = b, b += val + a;
 * 	salq		$2, %rdi					 b <<=
 * 2; jmp			.L6 .L2: movq		%rsi, %rdi
 * val = a; .L6: movq		%rdi, (%rcx)			 *dest = val;
 * 	ret
 *
 *  (Jump table)
 *
 *  .L4:
 *  	.quad		.L3
 *  	.quad		.L2
 *  	.quad		.L5
 *  	.quad		.L2
 *  	.quad		.L6
 *  	.quad		.L7
 *  	.quad		.L2
 *  	.quad		.L5
 *
 */

// a in %rdi, b in %rsi, c in %rdx, d in %rcx

void switcher(long a, long b, long c, long *dest) {
  long val;
  switch (a) {
  case 5:
    c = b ^ 15;
  case 0:
    val = c + 112;
    break;
  case 2:
  case 7:
    val = (c + b) << 2;
    break;
  case 4:
    val = a;
    break;
  default:
    val = b;
  }
  *dest = val;
}
