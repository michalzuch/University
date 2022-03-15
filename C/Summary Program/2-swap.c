#include <stdio.h>

void replace(double *a, double *b) {
    double c = *a;
    *a = *b;
    *b = c;
}

int swap() {
    double a, b;

    printf("Enter the numbers you want to replace in the format: a b\n");
    scanf("%lg %lg", &a, &b);

    replace(&a, &b);
    printf("\n%lg %lg\n", a, b);

    return 0;
}
