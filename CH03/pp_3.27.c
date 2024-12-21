/* Write goto code for fact_for based on first transforming it to a while loop
 * and then applying the guarded-do transformation */

/* For Loop implementation */

long fact_for(long n) {
  long result = 1;
  for (long i = 2; i <= n; i++) {
    result *= i;
  }
  return result;
}

/* while loop implementation */

long fact_for_while(long n) {
  long result = 1;
  long i = 2;
  while (i <= n) {
    result *= i;
    i++;
  }
  return result;
}

/* goto while guarded-do implementation */

long fact_for_while_goto(long n) {
  long result = 1;
  long i = 2;
  if (n <= 1) {
    goto done;
  }
loop:
  result *= i;
  i++;
  if (i <= n) {
    goto loop;
  }
done:
  return result;
}
