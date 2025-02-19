Continuing with polynomials, let's add Horner's method. the idea is to repeatedly factor out the powers of x to get the following equation:
$$a_0 + x(a_1 + x(a_2 + ... + x(a_{n-1} + xa_n) ...)$$

Using Horner's method on the poly function:

```c
double polyh(double a[], double x, long degree) {
    long i;
    double result = a[degree];
    for (i = degree - 1; i >= 0; i--) {
        result = a[i] + x * result;
    }
    return result;
}
```

A. For degree n, how many additions and how many multiplications does this code perform?
n mult and n addition.

B. On our reference machine, with the arithmetic operations having the latencies shown in Figure 5.12, we measure the CPE for this function to be 8.00. Explain how this CPE arises based on the data dependencies formed between iterations due to the operations implementing line 7 of the function.

We must first multiply by x (5 cycles) THEN add it to a\[i\] (3 cycles) for a total of 8.

C. Explain how the function shown in Practice Problem 5.5 can run faster, even though it requires more operations.

Only a single multiplication occurs along the critical path per iteration.
