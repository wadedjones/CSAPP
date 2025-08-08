
#include <stdio.h>

void *__real_malloc(size_t size);
void __real_free(void *ptr);

/* malloc wrapper function */
void *__wrap_malloc(size_t size) {
	void *ptr = __real_malloc(size);
	printf("malloc(%d) = %p\n", (int)size, ptr);
	return ptr;
}

/* free wrapper function */
void __wrap_free(void *ptr) {
	__real_free(ptr);
	printf("free(%p)\n", ptr);
}
