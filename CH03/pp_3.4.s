	.file	"pp_3.4.c"
# GNU C17 (GCC) version 14.1.1 20240522 (x86_64-pc-linux-gnu)
#	compiled by GNU C version 14.1.1 20240522, GMP version 6.3.0, MPFR version 4.2.1, MPC version 1.3.1, isl version isl-0.26-GMP

# GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
# options passed: -mtune=generic -march=x86-64 -O0
	.text
	.globl	pp_char_int
	.type	pp_char_int, @function
pp_char_int:
.LFB0:
	.cfi_startproc
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)	# sp, sp
	movq	%rsi, -16(%rbp)	# dp, dp
# pp_3.4.c:3: void pp_char_int(char *sp, int *dp) { *dp = (int)*sp; }
	movq	-8(%rbp), %rax	# sp, tmp100
	movzbl	(%rax), %eax	# *sp_4(D), _1
# pp_3.4.c:3: void pp_char_int(char *sp, int *dp) { *dp = (int)*sp; }
	movsbl	%al, %edx	# _1, _2
# pp_3.4.c:3: void pp_char_int(char *sp, int *dp) { *dp = (int)*sp; }
	movq	-16(%rbp), %rax	# dp, tmp101
	movl	%edx, (%rax)	# _2, *dp_5(D)
# pp_3.4.c:3: void pp_char_int(char *sp, int *dp) { *dp = (int)*sp; }
	nop	
	popq	%rbp	#
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE0:
	.size	pp_char_int, .-pp_char_int
	.globl	pp_char_unsigned
	.type	pp_char_unsigned, @function
pp_char_unsigned:
.LFB1:
	.cfi_startproc
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)	# sp, sp
	movq	%rsi, -16(%rbp)	# dp, dp
# pp_3.4.c:4: void pp_char_unsigned(char *sp, unsigned *dp) { *dp = (unsigned)*sp; }
	movq	-8(%rbp), %rax	# sp, tmp100
	movzbl	(%rax), %eax	# *sp_4(D), _1
# pp_3.4.c:4: void pp_char_unsigned(char *sp, unsigned *dp) { *dp = (unsigned)*sp; }
	movsbl	%al, %edx	# _1, _2
# pp_3.4.c:4: void pp_char_unsigned(char *sp, unsigned *dp) { *dp = (unsigned)*sp; }
	movq	-16(%rbp), %rax	# dp, tmp101
	movl	%edx, (%rax)	# _2, *dp_5(D)
# pp_3.4.c:4: void pp_char_unsigned(char *sp, unsigned *dp) { *dp = (unsigned)*sp; }
	nop	
	popq	%rbp	#
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE1:
	.size	pp_char_unsigned, .-pp_char_unsigned
	.globl	pp_unsigned_char_long
	.type	pp_unsigned_char_long, @function
pp_unsigned_char_long:
.LFB2:
	.cfi_startproc
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)	# sp, sp
	movq	%rsi, -16(%rbp)	# dp, dp
# pp_3.4.c:5: void pp_unsigned_char_long(unsigned char *sp, long *dp) { *dp = (long)*sp; }
	movq	-8(%rbp), %rax	# sp, tmp100
	movzbl	(%rax), %eax	# *sp_4(D), _1
# pp_3.4.c:5: void pp_unsigned_char_long(unsigned char *sp, long *dp) { *dp = (long)*sp; }
	movzbl	%al, %edx	# _1, _2
# pp_3.4.c:5: void pp_unsigned_char_long(unsigned char *sp, long *dp) { *dp = (long)*sp; }
	movq	-16(%rbp), %rax	# dp, tmp101
	movq	%rdx, (%rax)	# _2, *dp_5(D)
# pp_3.4.c:5: void pp_unsigned_char_long(unsigned char *sp, long *dp) { *dp = (long)*sp; }
	nop	
	popq	%rbp	#
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE2:
	.size	pp_unsigned_char_long, .-pp_unsigned_char_long
	.globl	pp_int_char
	.type	pp_int_char, @function
pp_int_char:
.LFB3:
	.cfi_startproc
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)	# sp, sp
	movq	%rsi, -16(%rbp)	# dp, dp
# pp_3.4.c:6: void pp_int_char(int *sp, char *dp) { *dp = (char)*sp; }
	movq	-8(%rbp), %rax	# sp, tmp100
	movl	(%rax), %eax	# *sp_4(D), _1
# pp_3.4.c:6: void pp_int_char(int *sp, char *dp) { *dp = (char)*sp; }
	movl	%eax, %edx	# _1, _2
# pp_3.4.c:6: void pp_int_char(int *sp, char *dp) { *dp = (char)*sp; }
	movq	-16(%rbp), %rax	# dp, tmp101
	movb	%dl, (%rax)	# _2, *dp_5(D)
# pp_3.4.c:6: void pp_int_char(int *sp, char *dp) { *dp = (char)*sp; }
	nop	
	popq	%rbp	#
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE3:
	.size	pp_int_char, .-pp_int_char
	.globl	pp_unsigned_unsigned_char
	.type	pp_unsigned_unsigned_char, @function
pp_unsigned_unsigned_char:
.LFB4:
	.cfi_startproc
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)	# sp, sp
	movq	%rsi, -16(%rbp)	# dp, dp
# pp_3.4.c:8:   *dp = (unsigned char)*sp;
	movq	-8(%rbp), %rax	# sp, tmp100
	movl	(%rax), %eax	# *sp_4(D), _1
# pp_3.4.c:8:   *dp = (unsigned char)*sp;
	movl	%eax, %edx	# _1, _2
# pp_3.4.c:8:   *dp = (unsigned char)*sp;
	movq	-16(%rbp), %rax	# dp, tmp101
	movb	%dl, (%rax)	# _2, *dp_5(D)
# pp_3.4.c:9: }
	nop	
	popq	%rbp	#
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE4:
	.size	pp_unsigned_unsigned_char, .-pp_unsigned_unsigned_char
	.globl	pp_char_short
	.type	pp_char_short, @function
pp_char_short:
.LFB5:
	.cfi_startproc
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)	# sp, sp
	movq	%rsi, -16(%rbp)	# dp, dp
# pp_3.4.c:10: void pp_char_short(char *sp, short *dp) { *dp = (short)*sp; }
	movq	-8(%rbp), %rax	# sp, tmp100
	movzbl	(%rax), %eax	# *sp_4(D), _1
# pp_3.4.c:10: void pp_char_short(char *sp, short *dp) { *dp = (short)*sp; }
	movsbw	%al, %dx	# _1, _2
# pp_3.4.c:10: void pp_char_short(char *sp, short *dp) { *dp = (short)*sp; }
	movq	-16(%rbp), %rax	# dp, tmp101
	movw	%dx, (%rax)	# _2, *dp_5(D)
# pp_3.4.c:10: void pp_char_short(char *sp, short *dp) { *dp = (short)*sp; }
	nop	
	popq	%rbp	#
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE5:
	.size	pp_char_short, .-pp_char_short
	.ident	"GCC: (GNU) 14.1.1 20240522"
	.section	.note.GNU-stack,"",@progbits
