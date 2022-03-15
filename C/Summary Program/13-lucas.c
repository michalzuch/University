#include<stdio.h>

int lucas() {
    printf("Provide an element in the string\n");
    int n;
    scanf("%d", &n);

    if (n == 0)
        printf("\n%d element of the Lucas Sequence is 2\n", n);
    else if (n == 1)
        printf("\n%d element of the Lucas Sequence is 1\n", n);
    else {
        int f1 = 2;
        int f2 = 1;
        int temp;
        for (int i = 1; i < n; i++) {
            temp = f1 + f2;
            f1 = f2;
            f2 = temp;
        }
        printf("\n%d element of the Lucas Sequence is %d\n", n, f2);
    }

    return 0;
}
