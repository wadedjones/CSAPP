	.file	"hello2.c"
# GNU C17 (GCC) version 14.1.1 20240522 (x86_64-pc-linux-gnu)
#	compiled by GNU C version 14.1.1 20240522, GMP version 6.3.0, MPFR version 4.2.1, MPC version 1.3.1, isl version isl-0.26-GMP

# GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
# options passed: -masm=att -mtune=generic -march=x86-64 -Og
	.text
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"hello, world\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	subq	$8, %rsp	#,
	.cfi_def_cfa_offset 16
# hello2.c:4:     write(1, "hello, world\n", 13);
	movl	$13, %edx	#,
	leaq	.LC0(%rip), %rsi	#, tmp99
	movl	$1, %edi	#,
	call	write@PLT	#
# hello2.c:5:     _exit(0);
	movl	$0, %edi	#,
	call	_exit@PLT	#
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (GNU) 14.1.1 20240522"
	.section	.note.GNU-stack,"",@progbits
