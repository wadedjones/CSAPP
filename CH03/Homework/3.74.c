#include <assert.h>

typedef enum {NEG, ZERO, POS, NAN} range_type;

extern range_type find_range(float x);

int main(void) {
	assert(NAN == find_range(0.0/0.0));
	assert(NEG == find_range(-1.23));
	assert(ZERO == find_range(0.0));
	assert(POS == find_range(3.14));
	return 0;
}
