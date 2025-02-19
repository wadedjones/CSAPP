### Practice Problem 5.3

Consider the following functions:
```c
long min(long x, long y) { return x < y ? x : y; }
long max(long x, long y) { return x < y ? y : x; }
void incr(long *xp, long v) { *xp += v; }
long square(long x) { return x * x; }
```

The following three code fragments call these functions:
```c
// A
for (i = min(x, y); i < max(x, y); incr(&i, 1))
        t += square(i);

// B
for (i = max(x, y) - 1; i >= min(x, y); incr(&i, -1))
        t += square(i);

// C
long low = min(x, y);
long high = max(x, y);
for (i = low; i < high; incr(&i, 1))
    t += square(i);
```

x = 10, y = 100

Code    min     max     incr    square
A.      1       91      90      90
B.      91      1       90      90
C.      1       1       90      90
