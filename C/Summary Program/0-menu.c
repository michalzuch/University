#include <stdio.h>
#include <stdlib.h>

int menu() {
    printf("\nPrograms made during classes\n");
    printf("1. The square of the number\n");
    printf("2. Swap numbers in places\n");
    printf("3. Factorial\n");
    printf("4. Binomial theorem\n");
    printf("5. Quadratic real equation\n");
    printf("6. Quadratic complex equation\n");
    printf("7. System of equations 2x2\n");
    printf("8. System of equations 3x3\n");
    printf("9. System of 4x4 equations (task 2 from the test)\n");
    printf("10. Task 1 of the test\n");
    printf("\nAdditional programs\n");
    printf("11. Sequence 1/n\n");
    printf("12. Fibonacci sequence\n");
    printf("13. Lucas sequence\n");
    printf("14. Check if the number is prime\n");
    printf("15. Simple calculator\n");
    printf("\n16. Exit\n");

    printf("\nChoose an option: ");

    int n = 16;
    scanf("%d", &n);

    return n;
}

/* import of functions from other programs */
int square();
int swap();
int factorial();
int newton();
int square_equation();
int complex_equation();
int system_2x2();
int system_3x3();
int system_4x4();
int task1();
int sequence();
int fibonacci();
int lucas();
int prime();
int calculator();

int main() {
    while (1)
        switch (menu()) {
            case 1:
                printf("\n");
                square();
                break;
            case 2:
                printf("\n");
                swap();
                break;
            case 3:
                printf("\n");
                factorial();
                break;
            case 4:
                printf("\n");
                newton();
                break;
            case 5:
                printf("\n");
                square_equation();
                break;
            case 6:
                printf("\n");
                complex_equation();
                break;
            case 7:
                printf("\n");
                system_2x2();
                break;
            case 8:
                printf("\n");
                system_3x3();
                break;
            case 9:
                printf("\n");
                system_4x4();
                break;
            case 10:
                printf("\n");
                task1();
                break;
            case 11:
                printf("\n");
                sequence();
                break;
            case 12:
                printf("\n");
                fibonacci();
                break;
            case 13:
                printf("\n");
                lucas();
                break;
            case 14:
                printf("\n");
                prime();
                break;
            case 15:
                printf("\n");
                calculator();
                break;
            case 16:
                exit(0);
            default:
                printf("\nOption does not exist.\n");
        }
}
