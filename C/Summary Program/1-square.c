#include <stdio.h>

int square() {
    double a;

    printf("Enter the number 'a' you want to square\n");
    printf("a = ");
    scanf("%lg", &a);
    printf("\n%g^2=%g\n", a, a * a);

    return 0;
}
