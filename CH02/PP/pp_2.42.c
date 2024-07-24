/* Write a function - div16 - that returns x/16 for int arg x
 * may not use division, multiplication, modulus, conditionals, comparison, or
 * loops. Using 32-bit integer
 */

int div16(int x) {
  int bias = (x >> 31) & 0xf; // & 0xf == y - 1
  return (x + bias) >> 4;
}
