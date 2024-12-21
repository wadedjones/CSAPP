/* With the following struct declaration and assembly code, complete the C
 * function */

/* fun:
 * 	movl		$0, %eax
 * 	jmp			.L2
 * .L3:
 * 	addq		(%rdi), %rax
 * 	movq		8(%rdi), %rdi
 * .L2:
 * 	testq		%rdi, %rdi
 * 	jne			.L3
 * 	rep; ret
 *
 */

struct ELE {
  long v;
  struct ELE *p;
};

long fun(struct ELE *ptr) {
  long result = 0;
  while (ptr->v != 0) {
    result += ptr->v;
    ptr = ptr->p;
  }
  return result;
}
