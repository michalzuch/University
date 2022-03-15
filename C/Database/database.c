#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct data {
    char name[15];
    char surname[21];
    int age;
    double salary;
};

int n = 0;
struct data a[100];

int menu();
void read_from_file();
void print_table();
int sort_options(char);
int sort(int);
void add_record();
void remove_record();
void export_to_file();
int compare_names();
int compare_surnames();
int compare_age();
int compare_salary();


int main() {
    while (1)
        switch (menu()) {
            case 1:
                system("clear");
                read_from_file();
                break;
            case 2:
                system("clear");
                print_table();
                break;
            case 3:
                system("clear");
                printf("Choose sort option: \n");
                char choice;
                scanf("%s", &choice);
                int temp = sort_options(choice);
                sort(temp);
                break;
            case 4:
                system("clear");
                add_record();
                break;
            case 5:
                system("clear");
                remove_record();
                break;
            case 6:
                system("clear");
                export_to_file();
                break;
            case 7:
                system("clear");
                exit(0);
            default:
                system("clear");
                printf("Option does not exist\n");
                printf("\n");
        }
}


int menu(void) {
    printf("1. Load data from the file 'database.txt' into the table.\n");
    printf("2. Display the data as a table.\n");
    printf("3. Sort data:\n");
    printf("    a) surname name age salary\n");
    printf("    b) name surname age salary\n");
    printf("    c) age surname name salary\n");
    printf("    d) salary surname name age\n");
    printf("4. Add a record to the data.\n");
    printf("5. Delete record from data.\n");
    printf("6. Save the data to a file.\n");
    printf("7. Exit.\n");
    printf("\nChoose an option: \n");

    int chosen_option = 7;
    scanf("%d", &chosen_option);
    return chosen_option;
}

int sort_options(char choice) {
    if (choice == 'a') return 1;
    if (choice == 'b') return 2;
    if (choice == 'c') return 3;
    if (choice == 'd') return 4;
    return 0;
}

void read_from_file() {

    FILE *fin = fopen("database.txt", "r");

    if (!fin) {
        printf("Error opening file for reading.\n");
        exit(-1);
    }

    while (fscanf(fin, "%s %s %d %lf", a[n].name, a[n].surname, &a[n].age, &a[n].salary) == 4) n++;
    printf("%d registers have been read.\n", n);
    printf("\n");
    fclose(fin);
}

void print_table() {
    printf("+----+-----------------+-----------------------+------+---------------+\n");
    printf("| no.| NAME            | SURNAME               |  AGE | SALARY        |\n");
    printf("+----+-----------------+-----------------------+------+---------------+\n");
    for (int k = 0; k < n; k++) {
        printf("| %2d | %-15s | %-21s | %4d | %15.2lf |\n", k + 1, a[k].name, a[k].surname, a[k].age, a[k].salary);
    }
    printf("+----+-----------------+-----------------------+------+---------------+\n");
    printf("\n");
}

int sort(int temp) {
    switch (temp) {
        case 1:
            qsort((void *) a, n, sizeof(struct data), compare_salary);
            qsort((void *) a, n, sizeof(struct data), compare_age);
            qsort((void *) a, n, sizeof(struct data), compare_names);
            qsort((void *) a, n, sizeof(struct data), compare_surnames);
            break;
        case 2:
            qsort((void *) a, n, sizeof(struct data), compare_salary);
            qsort((void *) a, n, sizeof(struct data), compare_age);
            qsort((void *) a, n, sizeof(struct data), compare_surnames);
            qsort((void *) a, n, sizeof(struct data), compare_names);
            break;
        case 3:
            qsort((void *) a, n, sizeof(struct data), compare_salary);
            qsort((void *) a, n, sizeof(struct data), compare_names);
            qsort((void *) a, n, sizeof(struct data), compare_surnames);
            qsort((void *) a, n, sizeof(struct data), compare_age);
            break;
        case 4:
            qsort((void *) a, n, sizeof(struct data), compare_age);
            qsort((void *) a, n, sizeof(struct data), compare_names);
            qsort((void *) a, n, sizeof(struct data), compare_surnames);
            qsort((void *) a, n, sizeof(struct data), compare_salary);
            break;
        default:
            printf("\nOption does not exist.\n");
            printf("\n");
    }
    printf("\n");
}

void add_record() {
    printf("Enter the name: \n");
    scanf("%s", a[n].name);
    printf("Enter the surname: \n");
    scanf("%s", a[n].surname);
    printf("Enter the age: \n");
    scanf("%d", &a[n].age);
    printf("Enter the salary: \n");
    scanf("%lf", &a[n].salary);
    n++;
    printf("\n");
}

void remove_record() {
    printf("Enter the number of the line to be deleted.\n");
    int temp;
    scanf("%d", &temp);
    temp--;
    if (temp > n) {
        printf("There is no such line.\n");
    } else {
        for (temp; temp < n; temp++) {
            strncpy(a[temp].name, a[temp + 1].name, 15);
            strncpy(a[temp].surname, a[temp + 1].surname, 21);
            a[temp].age = a[temp + 1].age;
            a[temp].salary = a[temp + 1].salary;
        }
        n--;
    }
}

void export_to_file() {
    FILE *fout = fopen("export.txt", "w");
    if (!fout) {
        printf("Writing file open error.\n");
        exit(-1);
    }
    for (int k = 0; k < n; k++)
        fprintf(fout, "%s %s %d %lf\n", a[k].name, a[k].surname, a[k].age, a[k].salary);
    fclose(fout);
    printf("Exported to export.txt.\n");
    printf("\n");
}

int intcmp(int a, int b) {
    if ((int) a == (int) b) return 0;
    if ((int) a > (int) b) return 1;
    if ((int) a < (int) b) return -1;
}

int compare_names(const void *p1, const void *p2) {
    struct data d1 = *(struct data *) p1;
    struct data d2 = *(struct data *) p2;
    int return_value = strcmp(d1.name, d2.name);
    return return_value;
}

int compare_surnames(const void *p1, const void *p2) {
    struct data d1 = *(struct data *) p1;
    struct data d2 = *(struct data *) p2;
    int return_value = strcmp(d1.surname, d2.surname);
    return return_value;
}

int compare_age(const void *p1, const void *p2) {
    struct data d1 = *(struct data *) p1;
    struct data d2 = *(struct data *) p2;
    int return_value = intcmp(d1.age, d2.age);
    return return_value;
}

int compare_salary(const void *p1, const void *p2) {
    struct data d1 = *(struct data *) p1;
    struct data d2 = *(struct data *) p2;
    int return_value = intcmp(d1.salary, d2.salary);
    return return_value;
}
