#include <stdio.h>
#include "9-zadanie2.h"

int system_4x4() {
    double a[4][4], b[4], x[4], d[4];

    printf("Give the equilibrium system 4x4:\n");
    scanf("%lgx%lgy%lgz%lgu=%lg", &a[0][0], &a[0][1], &a[0][2], &a[0][3], &b[0]);
    scanf("%lgx%lgy%lgz%lgu=%lg", &a[1][0], &a[1][1], &a[1][2], &a[1][3], &b[1]);
    scanf("%lgx%lgy%lgz%lgu=%lg", &a[2][0], &a[2][1], &a[2][2], &a[2][3], &b[2]);
    scanf("%lgx%lgy%lgz%lgu=%lg", &a[3][0], &a[3][1], &a[3][2], &a[3][3], &b[3]);

    int n = sol4(a, b, x, d);

    if (n == 0) {
        printf("The layout has no unequivocal solution\n");
        return 0;
    }

    if (n == 1) {
        printf("There is one solution: x = %g, y = %g, z = %g, u = %g\n", x[0], x[1], x[2], x[3]);

        double r[4];
        checking4(a, b, x, d, r);

        printf("\nVerification:\n");
        printf("r[0] = %g \n r[1] = %g \n r[2] = %g \n r[3] = %g\n", r[0], r[1], r[2], r[3]);
    }
    return 1;
}
