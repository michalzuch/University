#include<stdio.h>

int fibonacci() {
    printf("Provide an element in the string\n");
    int n;
    scanf("%d", &n);

    if (n <= 2)
        printf("\n%d an element of the Fibonacci Sequence is 1\n", n);
    else {
        int f1 = 1;
        int f2 = 1;
        int temp;
        for (int i = 3; i <= n; i++) {
            temp = f1 + f2;
            f1 = f2;
            f2 = temp;
        }

        printf("\n%d an element of the Fibonacci Sequence is %d\n", n, f2);
    }

    return 0;
}
