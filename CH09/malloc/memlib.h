#ifndef H_MEMLIB_H

#include <stdio.h>

void mem_init(void);
void *mem_sbrk(int incr);
int mm_init(void);
void *mm_malloc(size_t size);
void mm_free(void *ptr);

#endif
