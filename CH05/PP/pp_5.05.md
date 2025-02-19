Suppose we wish to write a function to evaluate a polynomial, where a polynomial of degree $n$ is defined to have a set of coefficients.
$$a_0, + a_{1}x + a_{2}x^2 + ... + a_{n}x^n$$

Implemented by the following function:

```c
double poly(double a[], double x, long degree) {
    long i;
    double result = a[0];
    double xpwr = x;
    for (i = 1; i <= degree; i++) {
        result += a[i] * xpwr;
        xpwr = x * xpwr;
    }
    return result;
}
```

A. For degree $n$, how many additions and how many multiplications does this code perform?

2n multiplications and n additions.

B. On our reference machine, with arithmetic operations having the latencies shown in Figure 5.12, we measure the CPE for this function to be 5.00. Explain how this CPE arises based on the data dependencies formed between iterations due to the operations implementing lines 7-8 of the function.

Performance limiting computation is the `xpwr = x * xpwr`. Requires floating point multiplication (5 clock cycles). Updating result only requires 3 clock cycles (floating point addition)
