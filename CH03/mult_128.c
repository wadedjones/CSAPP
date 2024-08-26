/* example program for multiplying two 64-bit numbers to get a 128-bit number,
 * and produce assembly code to examine */

#include <inttypes.h>

typedef unsigned __int128 uint128_t;

void store_uprod(uint128_t *dest, uint64_t x, uint64_t y) {
  *dest = x * (uint128_t)y;
}
