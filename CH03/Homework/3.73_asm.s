	.global find_range

find_range:
	vxorps		%xmm1, %xmm1, %xmm1
	vucomiss	%xmm1, %xmm0
	jp	nan
	jb	neg
	jz	zero
	movq	$2, %rax
	retq
nan:
	movq	$3, %rax
	retq
neg:
	xorq	%rax, %rax
	retq
zero:
	movq	$1, %rax
	retq
