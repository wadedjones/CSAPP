void switch_eg_impl(long x, long n, long *dest) {
  static void *jt[7] = {&&locA, &&locDef, &&locB, &&locC,
                        &&locD, &&locDef, &&locD};

  unsigned long index = n - 100;
  long val;

  if (index > 6)
    goto locDef;

  goto *jt[index];

locA:
  val = x * 13;
  goto done;
locB:
locC:
locD:
locDef:
done:
  *dest = val;
}
