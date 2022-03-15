#include <stdio.h>
#include "7-system-2x2f.h"

int system_2x2() {
    double a[2][2], b[2], x[2];

    printf("Give a 2x2 equation of the form ax + by = c:\n");
    scanf("%lgx%lgy=%lg", &a[0][0], &a[0][1], &b[0]);
    scanf("%lgx%lgy=%lg", &a[1][0], &a[1][1], &b[1]);

    int n = sol2(a, b, x);

    if (n == 0) {
        printf("The system is contradictory\n");
        return 0;
    }

    if (n == 1) {
        printf("There is one solution: x=%g y=%g\n", x[0], x[1]);
        double r[2];
        checking2(a, b, x, r);
        printf("\nVerification:\n");
        printf("r[0] = %g \nr[1] = %g\n", r[0], r[1]);
        return 1;
    }

    printf("There are infinitely many solutions\n");
    return 2;
}
