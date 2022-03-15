#include <stdio.h>
#include <math.h>

double left_side(double x, int n) {
    int k;
    double L;
    for (k = 1; k <= n; k++)
        L = L + (1 / pow(2, k) * tan(x / pow(2, k)));
    return L;
}

double right_side(double x, int n) {
    return 1 / pow(2, n) * (1.0 / tan(x / pow(2, n))) - (1.0 / tan(x));
}

int task1() {
    double x;
    int n;

    printf("Enter the range of n:");
    scanf("%d", &n);
    printf("Give the real number x:");
    scanf("%lg", &x);
    printf("\n");
    printf("Right side = %f\n", right_side(x, n));
    printf("Left side = %f\n", left_side(x, n));
    return 0;
}
