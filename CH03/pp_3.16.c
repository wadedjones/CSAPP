/* When given the C code below, gcc genereates the following assembly code:
 *
 * cond:
 * 	testq		%rsi, %rsi		// p
 * 	je			.L1
 * // jump if p equal to zero cmpq		%rdi, (%rsi)	// p:a jge
 * .L1						// jump if p > a movq
 * %rdi, (%rsi)	// *p = a .L1: rep; ret
 *
 * A. Write a goto version in C
 * B. Explain why the assembly code has two conditional branches
 *
 */

void cond(long a, long *p) {
  if (p && a > *p)
    *p = a;
}

/* A. */

void cond_goto(long a, long *p) {
  if (!p)
    goto end;
  if (*p >= a)
    goto end;
  *p = a;
end:
  return;
}

/* B. */

// We're testing if p is not zero AND if a is greater than p
