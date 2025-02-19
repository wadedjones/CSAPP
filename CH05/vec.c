#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "clock.h"

typedef long data_t;

typedef struct vec_rec {
	long len;
	data_t *data;
} vec_rec;

#define IDENT 1
#define OP *

/* create a vector of specified length */
vec_rec *new_vec(long len) {
	vec_rec *result = malloc(sizeof(*result));
	data_t *data = NULL;
	if (!result) {
		return NULL;
	}
	if (len > 0) {
		data = calloc(len, sizeof(data_t));
		if (!data) {
			free((void *)result);
			return NULL;
		}
	}
	result->data = data;
	return result;
}

/* Retrive vec element and store at dest
* Return 0 (out of bounds) or 1 (success)
* This function is rather unnecessary
*/
int get_vec_element(vec_rec *v, long index, data_t *dest) {
	if (index < 0 || index >= v->len) {
		return 0;
	}
	*dest = v->data[index];
	return 1;
}

/* get start of data element */
data_t *get_vec_start(vec_rec *v) {
	return v->data;
}

long vec_len(vec_rec *v) {
	return v->len;
}

/* different combine functions with faster optimizations */

void combine1(vec_rec *v, data_t *dest) {
	long i;
	*dest = IDENT;
	for (i = 0; i < vec_len(v); i++) {
		data_t val;
		get_vec_element(v, i, &val);
		*dest = *dest OP val;
	}
}

/* move func call vec_len out of loop */
void combine2(vec_rec *v, data_t *dest) {
	long i;
	long len = vec_len(v);

	*dest = IDENT;

	for (i = 0; i < len; i++) {
		data_t val;
		get_vec_element(v, i, &val);
		*dest = *dest OP val;
	}
}

/* remove unnecessary call to get_vec_element */
void combine3(vec_rec *v, data_t *dest) {
	long i;
	long len = vec_len(v);
	data_t *data = get_vec_start(v);

	*dest = IDENT;
	for (i = 0; i < len; i++) {
		*dest = *dest OP data[i];
	}
}

/* Accumulate result in local variable */
void combine4(vec_rec *v, data_t *dest) {
	long i;
	long len = vec_len(v);
	data_t *data = get_vec_start(v);
	data_t tmp_num = IDENT;

	for (i = 0; i < len; i++) {
		tmp_num = tmp_num OP data[i];
	}
	*dest = tmp_num;
}

/* Include bounds check in loop */
void combine4b(vec_rec *v, data_t *dest) {
	long i;
	long len = vec_len(v);
	data_t acc = IDENT;

	for (i = 0; i < len; i++) {
		if (i >= 0 && i < v->len) {
			acc = acc OP v->data[i];
		}
	}
	*dest = acc;
}

/* 2 x 1 loop unrolling */
void combine5(vec_rec *v, data_t *dest) {
	long i;
	long length = vec_len(v);
	long limit = length - 1;
	data_t *data = get_vec_start(v);
	data_t acc = IDENT;

	/* combine 2 elements at a time */
	for (i = 0; i < limit; i += 2) {
		acc = (acc OP data[i]) OP data[i + 1];
	}

	/* finish any remaining elements */
	for (; i < length; i++) {
		acc = acc OP data[i];
	}
	*dest = acc;
}

/* 2 x 2 loop unrolling */
void combine6(vec_rec *v, data_t *dest) {
	long i;
	long len = vec_len(v);
	long limit = len - 1;
	data_t *data = get_vec_start(v);
	data_t acc0 = IDENT;
	data_t acc1 = IDENT;

	/* combine 2 elements at a time */
	for (i = 0; i < limit; i+= 2) {
		acc0 = acc0 OP data[i];
		acc1 = acc1 OP data[i + 1];
	}

	/* finish remaining elements */
	for (; i < len; i++) {
		acc0 = acc0 OP data[i];
	}

	*dest = acc0 OP acc1;
}

/* 2 x 1a loop unrolling */
void combine7(vec_rec *v, data_t *dest) {
	long i;
	long len = vec_len(v);
	long limit = len - 1;
	data_t *data = get_vec_start(v);
	data_t acc = IDENT;

	/* combine two elements at the same time
	* diff parenthesis placement than combine5 */
	for (i = 0; i < limit; i++) {
		acc = acc OP (data[i] OP data[i + 1]);
	}

	/* finish remaining elements */
	for (; i < len; i++) {
		acc = acc OP data[i];
	}
	
	*dest = acc;
}

int main(void) {
	vec_rec *v = new_vec(100);
	data_t num;

	clock_t start, end;

	combine1(v, &num);

	combine7(v, &num);

}
