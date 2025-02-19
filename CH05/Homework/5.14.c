/* Write a version of inner product (problem 5.13) that uses 6 x 1 loop
 * unrolling */

typedef long data_t;

typedef struct vec_rec {
    long len;
    data_t *data;
} vec_rec;

/* 5.13 version */
void inner4(vec_rec *u, vec_rec *v, data_t *dest) {
    long i;
    long len = u->len;
    data_t *udata = u->data;
    data_t *vdata = v->data;
    data_t sum = (data_t)0;

    for (i = 0; i < len; i++) {
        sum = sum + udata[i] * vdata[i];
    }
    *dest = sum;
}

/* 6 x 1 loop unrolling */
void inner6x1(vec_rec *u, vec_rec *v, data_t *dest) {
    long i;
    long len = u->len;
    long limit = len - 5;
    data_t *udata = u->data;
    data_t *vdata = v->data;
    data_t sum = (data_t)0;

    for (i = 0; i < limit; i += 6) {
        sum = sum + (udata[i] * vdata[i]) + (udata[i + 1] * vdata[i + 1]) +
              (udata[i + 2] * vdata[i + 2]) + (udata[i + 3] * vdata[i + 3]) +
              (udata[i + 4] * vdata[i + 4]) + (udata[i + 5] * vdata[i + 5]);
    }

    for (; i < len; i++) {
        sum = sum + udata[i] * vdata[i];
    }
    *dest = sum;
}
