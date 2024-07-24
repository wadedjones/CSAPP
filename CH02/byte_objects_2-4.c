#include <stdio.h>
#include <string.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len) {
  int i;
  for (i = 0; i < len; i++) {
    printf(" %.2x", start[i]);
  }
  printf("\n");
}

void show_int(int x) { show_bytes((byte_pointer)&x, sizeof(int)); }

void show_float(float x) { show_bytes((byte_pointer)&x, sizeof(float)); }

void show_pointer(void *x) { show_bytes((byte_pointer)&x, sizeof(void *)); }

void test_show_bytes(int val) {
  int ival = val;
  float fval = (float)ival;
  int *pval = &ival;
  show_int(ival);
  show_float(fval);
  show_pointer(pval);
}

int main(void) {
  // test_show_bytes(12345);
  // int val = 0x87654321;
  // byte_pointer valp = (byte_pointer)&val;
  // show_bytes(valp, 1);
  // show_bytes(valp, 2);
  // show_bytes(valp, 3);
  // char *s = "abcdef";
  // show_bytes((byte_pointer)s, strlen(s) + 1);

  // short x = 12345;
  // short mx = -x;
  //
  // show_bytes((byte_pointer)&x, sizeof(short));
  // show_bytes((byte_pointer)&mx, sizeof(short));

  short sx = -12345;
  unsigned short usx = sx;
  int x = sx;
  unsigned ux = usx;

  printf("sx  = %d:\t", sx);
  show_bytes((byte_pointer)&sx, sizeof(short));
  printf("usx = %u:\t", usx);
  show_bytes((byte_pointer)&usx, sizeof(unsigned short));
  printf("x   = %d:\t", x);
  show_bytes((byte_pointer)&x, sizeof(int));
  printf("ux  = %u:\t", ux);
  show_bytes((byte_pointer)&ux, sizeof(unsigned));

  return 0;
}
