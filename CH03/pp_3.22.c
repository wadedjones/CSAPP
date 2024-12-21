/* A. What is the maximum value of n for which we can represent n! with a 32-bit
 * int?
 *
 *  B. What about for a 64-bit long?
 *
 */

#include <stdio.h>

int n_int_factorial(void) {
  int result = 1;
  int temp = result;
  int n = 1;
  int x = result;
  do {
    temp *= n + 1;
    result *= n;
    printf("%d. result: %d, temp: %d\n", n, result, temp);
    x = result / n;
    printf("x: %d\n", x);
    n++;
  } while (temp >= result);
  return n - 1;
}

int check_fac(int n) {
  int result = 1;
  for (int i = n; i > 0; i--) {
    result *= n;
  }
  return result;
}

long n_long_factorial(void) {
  long result = 1;
  long temp = result;
  long n = 1;
  do {
    temp = result;
    result *= n;
    n++;
  } while (result >= temp);
  return n -= 2;
}

long check_fac_long(long n) {
  long result = 1;
  for (long i = n; i > 0; i--) {
    result *= n;
  }
  return result;
}

int main(void) {
  int n = n_int_factorial();
  int check = check_fac(n + 1);
  long x = n_long_factorial();
  printf("n: %d\n", n);
  printf("check: %d\n", check);
  printf("nlong: %ld\n", x);
  return 0;
}
