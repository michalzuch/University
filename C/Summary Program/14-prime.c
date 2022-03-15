#include <stdio.h>
#include <stdlib.h>

void prime() {
    int n;

    printf("Check if the given number is a prime number\n");
    printf("Enter a number: \n");
    scanf("%u", &n);

    if (n < 2) {
        printf("The number %d is not a prime number\n", n);
        exit(0);
    } else {
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                printf("The number %d is not a prime number\n", n);
                exit(0);
            }
        }
    }
    printf("The number %d is a prime number\n", n);
}
