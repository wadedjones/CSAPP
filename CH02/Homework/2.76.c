/* The library function calloc has the following declaration:
 *
 * void *calloc(size_t nmemb, size_t size);
 *
 * According to the library documentation, "The calloc function allocates memory
 * for an array of nmemb elements of size bytes each. The memory is set to zero.
 * If nmemb or size is zero, then calloc returns NULL."
 *
 * Write an implementation of calloc that performs the allocation by a call to
 * malloc and sets the memory to zero via memset. Your code should not have any
 * vulnerabilities due to arithmetic overflow, and it should work correctly
 * regardless of the number of bits used to represent data of type size_t.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *my_calloc(size_t nmemb, size_t size) {
  if (nmemb == 0 || size == 0) {
    return NULL;
  }
  size_t buf_size = nmemb * size;
  // check for overflow
  if (buf_size < nmemb || buf_size < size) {
    return NULL;
  }
  void *result = malloc(buf_size);
  memset(result, 0, buf_size);
  if (result == NULL) {
    free(result);
    return NULL;
  }
  return result;
}

int main(void) {
  int *x = my_calloc(20, sizeof(int));

  for (int i = 0; i < 20; i++) {
    printf("%d\n", *(x + i));
  }

  free(x);
  return 0;
}
