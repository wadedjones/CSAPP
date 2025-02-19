/* Implement a more efficient version of memset */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Basic implementation: */
void *basic_memset(void *s, int c, size_t n) {
    size_t cnt = 0;
    unsigned char *schar = s;
    while (cnt < n) {
        *schar++ = (unsigned char)c;
        cnt++;
    }
    return s;
}

/* My memset */
void *my_memset(void *s, int c, size_t n) {
    /* align to K */
    size_t K = sizeof(unsigned long);
    size_t cnt = 0;
    unsigned long *schar = s;
    while (cnt < n) {
        if ((size_t)schar % K == 0) {
            break;
        }
        *schar++ = (unsigned char)c;
        cnt++;
    }

    /* set K chars one time */
    unsigned long *slong = (unsigned long *)schar;
    size_t rest = n - cnt;
    size_t loop = rest / K;
    size_t tail = rest % K;

    for (size_t i = 0; i < loop; i++) {
        *slong++ = c;
    }

    /* pad the tail */
    unsigned char *tailchar = (unsigned char *)slong;
    for (size_t i = 0; i < tail; i++) {
        *tailchar++ = (unsigned char)c;
    }
    return s;
}

int main(void) {
    size_t space = sizeof(char) * 60000;
    void *basic = malloc(space);
    void *effective = malloc(space);

    basic_memset(basic, 0, space);
    my_memset(effective, 0, space);

    assert(memcmp(basic, effective, space) == 0);

	free(basic);
	free(effective);

    return 0;
}
