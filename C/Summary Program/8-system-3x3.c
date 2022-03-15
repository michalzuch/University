#include <stdio.h>
#include "8-system-3x3f.h"

int system_3x3() {
    double a[3][3], b[3], x[3];

    printf("Give the 3x3 equilibrium system of the form ax + by + cz = d:\n");
    scanf("%lgx%lgy%lgz=%lg", &a[0][0], &a[0][1], &a[0][2], &b[0]);
    scanf("%lgx%lgy%lgz=%lg", &a[1][0], &a[1][1], &a[1][2], &b[1]);
    scanf("%lgx%lgy%lgz=%lg", &a[2][0], &a[2][1], &a[2][2], &b[2]);
    int n = sol3(a, b, x);

    if (n == 0) {
        printf("The layout has no unequivocal solution\n");
        return 0;
    }

    if (n == 1) {
        printf("There is one solution: x = %g y = %g z = %g\n", x[0], x[1], x[2]);
        double r[3];
        checking3(a, b, x, r);
        printf("\nVerification:\n");
        printf("r[0] = %g \nr[1] = %g \nr[2] = %g\n", r[0], r[1], r[2]);
        return 1;
    }
    printf("There are infinitely many solutions\n");
    return 2;
}
