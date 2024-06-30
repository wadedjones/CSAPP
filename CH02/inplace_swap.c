#include <stdio.h>

void inplace_swap(int *x, int *y);
void reverse_array(int a[], int cnt);

int main(void) {
  int a[] = {1, 2, 3, 4, 5};
  int b[] = {1, 2, 3, 4};

  printf("a: \n");
  for (int i = 0; i < 5; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");

  reverse_array(a, 5);

  for (int i = 0; i < 5; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");

  printf("b: \n");
  for (int i = 0; i < 4; i++) {
    printf("%d ", b[i]);
  }
  printf("\n");

  reverse_array(b, 4);

  for (int i = 0; i < 4; i++) {
    printf("%d ", b[i]);
  }
  printf("\n");
  return 0;
}

void inplace_swap(int *x, int *y) {
  *y = *x ^ *y;
  *x = *x ^ *y;
  *y = *x ^ *y;
}

void reverse_array(int a[], int cnt) {
  int first, last;
  for (first = 0, last = cnt - 1; first < last; first++, last--) {
    inplace_swap(&a[first], &a[last]);
  }
}
