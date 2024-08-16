#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int x = random();
  int y = random();

  unsigned ux = (unsigned)x;
  unsigned uy = (unsigned)y;

  // A.
  printf("x = %d, y = %d\n", x, y);
  printf("A: %d\n", (x < y) == (-x > -y));
  printf("B: %d\n", ((x + y) << 4) + y - x == 17 * y + 15 * x);
  printf("C: %d\n", ~x + ~y + 1 == ~(x + y));
  printf("D: %d\n", (ux - uy) == -(unsigned)(y - x));
  printf("E: %d\n", ((x >> 2) << 2) <= x);

  x = random();
  y = random();
  printf("x = %d, y = %d\n", x, y);
  printf("A: %d\n", (x < y) == (-x > -y));
  printf("B: %d\n", ((x + y) << 4) + y - x == 17 * y + 15 * x);
  printf("C: %d\n", ~x + ~y + 1 == ~(x + y));
  printf("D: %d\n", (ux - uy) == -(unsigned)(y - x));
  printf("E: %d\n", ((x >> 2) << 2) <= x);

  x = random();
  y = random();
  printf("x = %d, y = %d\n", x, y);
  printf("A: %d\n", (x < y) == (-x > -y));
  printf("B: %d\n", ((x + y) << 4) + y - x == 17 * y + 15 * x);
  printf("C: %d\n", ~x + ~y + 1 == ~(x + y));
  printf("D: %d\n", (ux - uy) == -(unsigned)(y - x));
  printf("E: %d\n", ((x >> 2) << 2) <= x);

  x = random();
  y = random();
  printf("x = %d, y = %d\n", x, y);
  printf("A: %d\n", (x < y) == (-x > -y));
  printf("B: %d\n", ((x + y) << 4) + y - x == 17 * y + 15 * x);
  printf("C: %d\n", ~x + ~y + 1 == ~(x + y));
  printf("D: %d\n", (ux - uy) == -(unsigned)(y - x));
  printf("E: %d\n", ((x >> 2) << 2) <= x);

  x = random();
  y = random();
  printf("x = %d, y = %d\n", x, y);
  printf("A: %d\n", (x < y) == (-x > -y));
  printf("B: %d\n", ((x + y) << 4) + y - x == 17 * y + 15 * x);
  printf("C: %d\n", ~x + ~y + 1 == ~(x + y));
  printf("D: %d\n", (ux - uy) == -(unsigned)(y - x));
  printf("E: %d\n", ((x >> 2) << 2) <= x);

  int a = 0;
  int b = 0;
  int c = 0;
  int d = 0;
  int e = 0;
  int count = 0;

  for (x = 1, y = 100; x < 100; x++, y--) {
    a += (x < y) == (-x > -y);
    b += ((x + y) << 4) + y - x == 17 * y + 15 * x;
    c += ~x + ~y + 1 == ~(x + y);
    d += (ux - uy) == -(unsigned)(y - x);
    e += ((x >> 2) << 2) <= x;
    count++;
  }

  printf("count: %d\n", count);
  printf("a: %d\n", a);
  printf("b: %d\n", b);
  printf("c: %d\n", c);
  printf("d: %d\n", d);
  printf("e: %d\n", e);

  return 0;
}
