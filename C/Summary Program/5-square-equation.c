#include <math.h>
#include <stdio.h>

int calculate(double a, double b, double c, double *x1, double *x2) {
    double delta = b * b - 4 * a * c;

    if (delta < 0.0) return 0;
    if (delta == 0.0) {
        *x1 = -b / (a * 2);
        return 1;
    }

    delta = sqrt(delta);
    *x1 = (-b - delta) / (a * 2);
    *x2 = (-b + delta) / (a * 2);

    return 2;
}

int square_equation() {
    double a, b, c;
    double x1, x2;

    printf("Give a, b, and c for an equation of the form ax ^ 2 + bx + c = 0\n");
    printf("a = ");
    scanf("%lg", &a);
    printf("b = ");
    scanf("%lg", &b);
    printf("c = ");
    scanf("%lg", &c);

    int n = calculate(a, b, c, &x1, &x2);

    if (n == 0) {
        printf("Lack of elements\n");
        return 0;
    }
    if (n == 1) {
        printf("One solution x0 = %g\n", x1);
        return 1;
    }
    printf("Two solutions x1 = %g, x2 = %g\n", x1, x2);
    return 2;
}
