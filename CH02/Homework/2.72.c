/* You are given the task of writing a function that will copy an integer val
 * into a buffer buf, but it should do so only if enough space is available in
 * the buffer. Here is the (buggy) code you write:
 *
 * void copy_int(int val, void *buf, int maxbytes) {
 * 	if (maxbytes - sizeof(val) >= 0)
 * 		memcpy(buf, (void *)&val, sizeof(val));
 * }
 *
 * A. Explain why the conditional test in the code always succeeds. Hint: The
 * sizeof operator returns a value of type size_t.
 * B. Show how you can rewrite the conditional test to make it work properly.
 */

// A. An int (maxbytes) subtracting unsigned int (val) always results in a value
// greater than 0.
// B. See below:

#include <assert.h>
#include <stdlib.h>
#include <string.h>

void copy_int(int val, void *buf, int maxbytes) {
  if (maxbytes >= (int)sizeof(val))
    memcpy(buf, (void *)&val, sizeof(val));
}

int main(void) {
  int maxbytes = sizeof(int) * 10;
  void *buf = malloc(sizeof(maxbytes));

  int val = 0x12345678;
  copy_int(val, buf, maxbytes);
  assert(*(int *)buf == val);

  val = 0xAABBCCDD;
  copy_int(val, buf, 0);
  assert(*(int *)buf != val);

  // free(buf);

  return 0;
}
