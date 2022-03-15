#include <stdio.h>

int sequence() {
    printf("The program will calculate the sum of the sequence for the given number n\n");
    printf("The sequence is 1/1 + 1/2 + 1/3 + ... + 1 / n\n");
    double n;
    printf("n = ");
    scanf("%lg", &n);
    double sum = 1.0;
    double k = 2.0;

    while (k != n) {
        sum = sum + 1.0 / k;
        k++;
    }

    printf("\nSum = %lg\n", sum);
    return 0;
}
