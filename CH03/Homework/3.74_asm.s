	.global find_range

find_range:
	vxorps		%xmm1, %xmm1, %xmm1
	vucomiss	%xmm1, %xmm0
	setz			%al
	setb			%cl
	movzbq		%cl, %rcx
	movzbq		%al, %rax
	leaq			-3(%rax,%rcx,2), %rax 
	// setb -3 + (0) + (1 * 2) = -1
	// setz -3 + (1) + (0 * 2) = -2
	// abov -3 + (0) + (0 * 0) = -3
	notq			%rax
	//3 or 2 or 1
	movq			$3, %rcx
	cmovp			%rcx, %rax
	retq
