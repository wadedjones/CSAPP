#include <stdint.h>
#include <stdio.h>

int32_t fun1(unsigned word) { return (int32_t)((word << 24) >> 24); }

int32_t fun2(unsigned word) { return ((int32_t)word << 24) >> 24; }

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len) {
  int i;
  for (i = 0; i < len; i++) {
    printf(" %.2x", start[i]);
  }
  printf("\n");
}
void show_bytes_little_end(byte_pointer start, size_t len) {
  int i;
  for (i = len - 1; i >= 0; i--) {
    printf(" %.2x", start[i]);
  }
  printf("\n");
}

int main(void) {
  int32_t n1 = 0x00000076;
  int32_t n2 = 0x87654321;
  int32_t n3 = 0x000000C9;
  int32_t n4 = 0xEDCBA987;

  int32_t a1 = 0;
  int32_t a2 = 0;
  int32_t a3 = 0;
  int32_t a4 = 0;

  a1 = fun1(n1);
  a2 = fun1(n2);
  a3 = fun1(n3);
  a4 = fun1(n4);
  printf("1 - fun1: \t");
  show_bytes((byte_pointer)&a1, sizeof(int32_t));
  printf("2 - fun1: \t");
  show_bytes((byte_pointer)&a2, sizeof(int32_t));
  printf("3 - fun1: \t");
  show_bytes((byte_pointer)&a3, sizeof(int32_t));
  printf("4 - fun1: \t");
  show_bytes((byte_pointer)&a4, sizeof(int32_t));

  a1 = fun2(n1);
  a2 = fun2(n2);
  a3 = fun2(n3);
  a4 = fun2(n4);
  printf("1 - fun2: \t");
  show_bytes((byte_pointer)&a1, sizeof(int32_t));
  printf("2 - fun2: \t");
  show_bytes((byte_pointer)&a2, sizeof(int32_t));
  printf("3 - fun2: \t");
  show_bytes((byte_pointer)&a3, sizeof(int32_t));
  printf("4 - fun2: \t");
  show_bytes((byte_pointer)&a4, sizeof(int32_t));

  printf("1 - fun2: \t");
  show_bytes_little_end((byte_pointer)&a1, sizeof(int32_t));
  printf("2 - fun2: \t");
  show_bytes_little_end((byte_pointer)&a2, sizeof(int32_t));
  printf("3 - fun2: \t");
  show_bytes_little_end((byte_pointer)&a3, sizeof(int32_t));
  printf("4 - fun2: \t");
  show_bytes_little_end((byte_pointer)&a4, sizeof(int32_t));
}
