/* In the following code, we have ommitted definitions of M and N: */

#define M 1 // 1 is dummy for errors
#define N 1 // 1 is dummy for erros

int arith(int x, int y) {
  int result = 0;
  result = x * M + y / N;
  return result;
}

/* We compiled this code for particular values of M and N. The compiler
 * optimized the multiplication and division using the methods we have
 * discussed. the following is a translation of the generated machine code back
 * into C: */

int optarith(int x, int y) {
  int t = x;
  x <<= 5;
  x -= t;
  if (y < 0)
    y += 7;
  y >>= 3; // arithmetic shift
  return x + y;
}

/* What are the values of M and N? */
/* M == 31, N == 8 */
