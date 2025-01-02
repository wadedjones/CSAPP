// funct3:
// 	vmovss		(%rdx), %xmm1
// 	vcvtsi2sd	(%rdi), %xmm2, %xmm2
// 	vucomisd	%xmm2, %xmm0
// 	jbe				.L8
// 	vcvtsi2ssq	%rsi, %xmm0, %xmm0
// 	vmulss		%xmm1, %xmm0, %xmm1
// 	vunpcklps	%xmm1, %xmm1, %xmm1
// 	vcvtps2pd	%xmm1, %xmm0
// 	ret
// .L8:
// 	vaddss		%xmm1, %xmm1, %xmm1
// 	vcvtsi2ssq	%rsi, %xmm0, %xmm0
// 	vaddss		%xmm1, %xmm0, %xmm0
// 	vunpcklps	%xmm0, %xmm0, %xmm0
// 	vcvtps2pd	%xmm0, %xmm0
// 	ret

double funct3(int *ap, double b, long c, float *dp) {
  // mov dp into xmm1
  // mov and convert ap into xmm2
  // cmp *ap and b
  // if a < b
  // mov and convert c into xmm0
  // xmm1/dp *= xmm0/c
  // convert dp to double and return
  int a = *ap;
  float d = *dp;
  if (a < b) {
    return c * d;
  }
  printf("%d", a);
  // *dp += *dp
  // mov and convert c into xmm0
  // *dp += c
  // convert dp to double and return
  return (2 * d) + c;
}
