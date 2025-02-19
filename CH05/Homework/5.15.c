/* Write a version of inner product (problem 5.13) that uses 6 x 6 loop
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

/* 6 x 6 loop unrolling */
void inner6x1(vec_rec *u, vec_rec *v, data_t *dest) {
    long i;
    long len = u->len;
    long limit = len - 5;
    data_t *udata = u->data;
    data_t *vdata = v->data;
    data_t acc0 = 0;
    data_t acc1 = 0;
    data_t acc2 = 0;
    data_t acc3 = 0;
    data_t acc4 = 0;
    data_t acc5 = 0;

    for (i = 0; i < limit; i += 6) {
        acc0 = acc0 + (udata[i] * vdata[i]);
        acc1 = acc1 + (udata[i + 1] * vdata[i + 1]);
        acc2 = acc2 + (udata[i + 2] * vdata[i + 2]);
        acc3 = acc3 + (udata[i + 3] * vdata[i + 3]);
        acc4 = acc4 + (udata[i + 4] * vdata[i + 4]);
        acc5 = acc5 + (udata[i + 5] * vdata[i + 5]);
    }

    for (; i < len; i++) {
        acc0 = acc0 + (udata[i] * vdata[i]);
    }
    *dest = acc0 + acc1 + acc2 + acc3 + acc4 + acc5;
}
