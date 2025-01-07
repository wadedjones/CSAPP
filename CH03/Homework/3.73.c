/* Write a function find range */
#include <assert.h>
#include <stdio.h>

typedef enum {NEG, ZERO, POS, OTHER} range_type;

extern range_type find_range(float n);

int main(void) {
	assert(OTHER == find_range(0.0/0.0));
	assert(NEG == find_range(-2.5));
	assert(ZERO == find_range(0.0));
	assert(POS == find_range(1.8));
	printf("completed\n");
	return 0;
}
