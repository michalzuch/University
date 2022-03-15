#include <stdio.h>
#include <complex.h>

void complex_solution(complex double a, complex double b, complex double c, complex double *z1, complex double *z2) {
    complex double delta = b * b - 4 * a * c;
    delta = csqrt(delta);
    *z1 = (-b - delta) / (2 * a);
    *z2 = (-b + delta) / (2 * a);
}

int complex_equation() {
    complex double a, b, c;
    double k, l, m;
    double kc, lc, mc;
    complex double z1, z2;

    printf("Give the numbers a, b, and c in the format x + yi\n");
    printf("a = ");
    scanf("%lg+%lgi", &k, &kc);
    a = CMPLX(k, kc);

    printf("b = ");
    scanf("%lg+%lgi", &l, &lc);
    b = CMPLX(l, lc);

    printf("c = ");
    scanf("%lg+%lgi", &m, &mc);
    c = CMPLX(m, mc);

    complex_solution(a, b, c, &z1, &z2);

    if (cimag(z1) == 0 && cimag(z2) == 0)
        printf("z1 = %g, z2 = %g\n", creal(z1), creal(z2));
    else
        printf("z1 = %g%+gi, z2 = %g%+gi\n", creal(z1), cimag(z1), creal(z2), cimag(z2));
    return 0;
}
