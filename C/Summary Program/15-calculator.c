#include <stdio.h>

int calculator() {
    printf("Actions available:\n");
    printf("a + b\n");
    printf("a - b\n");
    printf("a * b\n");
    printf("a / b\n");
    printf("Enter the action you want to perform as shown above.\n");
    double a, b;
    char x;
    scanf("%lg %s %lg", &a, &x, &b);
    if (x == '+')
        printf("%lg\n", a + b);
    else if (x == '-')
        printf("%lg\n", a - b);
    else if (x == '*')
        printf("%lg\n", a * b);
    else if (x == '/')
        printf("%lg\n", a / b);
    return 0;
}
