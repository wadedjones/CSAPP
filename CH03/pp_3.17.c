/* An alternate rule for translating if statements into goto code is as follows:
 *
 * t = test-expr
 * if (t)
 * 	goto true;
 * else-statement
 * goto done;
 * true:
 * 	then-statement
 * done:
 *
 * A. Rewrite the goto version of absdiff_se based on this alternate rule.
 * B. Can you think of any reasons for choosing one rule over the other?
 *
 */

long lt_cnt = 0;
long ge_cnt = 0;

long absdiff_se(long x, long y) {
  long result;
  if (x < y) {
    lt_cnt++;
    result = y - x;
  } else {
    ge_cnt++;
    result = x - y;
  }
  return result;
}

/* A. */

long my_absdiff_se(long x, long y) {
  long result;
  if (x < y) {
    goto then;
  }
  ge_cnt++;
  result = x - y;
  return result;

then:
  lt_cnt++;
  result = y - x;
  return result;
}

/* B. */

// No idea why you would choose goto statments at all to be honest.
