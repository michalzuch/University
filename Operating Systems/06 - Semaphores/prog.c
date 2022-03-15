#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include "sem.h"

const char* name = "/semaphore";

int main(int argc, const char* argv[]) {
    FILE *fin;

    semid semaphore_id = semOpen(name);
    fin = fopen("number.txt", "r");
    int sections = atoi(argv[2]);
    int i;
    int number = 0;

    for (i = 0; i < sections; i++) {
        printf("Before the critical section\n");
        printf("PID: %d\n", getpid());
        semInfo(semaphore_id, sem_val);

        semP(semaphore_id);

        fin = fopen("number.txt", "r");
        int read_from_file = fscanf(fin, "%i", &number);
        if (read_from_file < 0) {
            perror("Error while reading from file.");
            exit(EXIT_FAILURE);
        }

        fclose(fin);
        number++;

        printf("            In the critical section\n");
        printf("            PID: %d\n", getpid());
        semInfo(semaphore_id, sem_val);
        printf("            number: %d\n", number);

        fin = fopen("number.txt", "w");
        fprintf(fin, "%d", number);
        fclose(fin);

        semV(semaphore_id);

        printf("After the critical section\n");
        printf("PID: %d\n", getpid());
        semInfo(semaphore_id, sem_val);
    }

    semClose(semaphore_id);

}