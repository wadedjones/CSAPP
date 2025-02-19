/* modify combine5 to unroll the loop by a factor of k=5 */

typedef long data_t;

typedef struct vec_rec {
	long len;
	data_t *data;
} vec_rec;

#define IDENT 1
#define OP *

void combine5_mod(vec_rec *v, data_t *dest) {
	long i;
	long len = v->len;
	long limit = len - 4;
	data_t *data = v->data;
	data_t acc = IDENT;

	/* combine 5 elements at a time */
	for (i = 0; i < limit; i += 5) {
		acc = (((((acc OP data[i]) OP data[i + 1]) OP data[i + 2]) OP data[i + 3]) OP data[i + 4]);
	}

	for (; i < len; i++) {
		acc = acc OP data[i];
	}
	*dest = acc;
}
