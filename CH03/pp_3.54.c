/* complete the C function */

// funct2:
// 	vcvtsi2ss		%edi, %xmm2, %xmm2 --> convert int x to float
// 	vmulss			%xmm1, %xmm2, %xmm1 --> multiply x * y
// 	vunpcklps		%xmm1, %xmm1, %xmm1 --> unpack single precision
// 	vcvtps2pd		%xmm1, %xmm2 --> convert y to double, store in
// xmm2 	vcvtsi2sdq	%rsi, %xmm1, %xmm1 --> convert long to double
// vdivsd %xmm1, %xmm0, %xmm0 --> divide w/z 	vsubsd			%xmm0,
// %xmm2, %xmm0 --> y - w 	ret
//

double funct2(double w, int x, float y, long z) {
  // stop formatting weird
  return (y * x) - (w / z);
}
