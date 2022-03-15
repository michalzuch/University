#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double factorial2(unsigned n) {
    double s = 1.0;
    int i;
    for (i = 1; i <= n; i++) s *= i;
    return s;
}

double Factorial1(unsigned n) {
    if (n == 0)
        return 1.0;
    return n * factorial2((n - 1));
}

double NS(unsigned n, unsigned k) {
    if (n < k) {
        printf("Newton symbol: n < k!\n");
        exit(0);
    }
    return factorial2(n) / factorial2(k) / factorial2(n - k);
}

/* checking Newton's double name formula */
double left(double a, double b, unsigned n) {
    return pow(a + b, n);
}

double right(double a, double b, unsigned n) {
    double s = 0.0;
    unsigned k;
    for (k = 0; k <= n; k++) s += NS(n, k) * pow(a, n - k) * pow(b, k);
    return s;
}

int newton() {
    unsigned n;
    unsigned k;
    double a, b;

    printf("Enter the number 'n' of the Newton Symbol\n");
    printf("n = ");
    scanf("%d", &n);
    printf("Enter the number 'k' of the Newton symbol\n");
    printf("k = ");
    scanf("%d", &k);

    printf("\nNS(%d,%d) = %g\n", n, k, NS(n, k));

    printf("\nVerification\n");
    printf("(a + b)^n = NS(n, 0) * a^n * b^0 + NS(n, 1) * a^(n - 1) * b^1 + ... + NS(n, n) * a^0 * b^n\n");
    printf("Enter a\n");
    printf("a = ");
    scanf("%lg", &a);
    printf("Enter b\n");
    printf("b = ");
    scanf("%lg", &b);
    printf("L = %g =? %g = P\n", left(a, b, n), right(a, b, n));

    return 0;
}

int factorial() {
    unsigned n;

    printf("Enter the number n whose factorial you want to calculate\n");
    printf("n = ");
    scanf("%d", &n);
    printf("\n%d! = %g\n", n, Factorial1(n));

    return 0;
}
