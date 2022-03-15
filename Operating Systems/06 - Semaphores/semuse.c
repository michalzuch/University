#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <string.h>
#include "sem.h"

void arguments_error(int arguments);
int switch_case_chooser(const char* letter);
void invalid_argument();
void make_clean(void);
const char* name = "/semaphore";

// typedef sem_t *semid;

int main(int argc, const char* argv[]) {
    arguments_error(argc);
    int input = switch_case_chooser(argv[1]);

    semid semaphore_id;

    switch(input) {
        // ERROR
        case -1:
            invalid_argument();
            exit(EXIT_FAILURE);
        // INITIALIZE
        case 1:
            semaphore_id = semCreate(name, 1);
            break;
        // REMOVE
        case 2:
            semRemove(name);
            break;
        // PASSERING
        case 3:
            semaphore_id = semOpen(name);
            semP(semaphore_id);
            semInfo(semaphore_id, sem_val);
            break;
        // VRIJGAVE
        case 4:
            semaphore_id = semOpen(name);
            semV(semaphore_id);
            semInfo(semaphore_id, sem_val);
            break;
        // QUERY
        case 5:
            semaphore_id = semOpen(name);
            semInfo(semaphore_id, sem_val);
            break;
        default:
            break;
    }
}

void arguments_error(int arguments) {
    if (arguments != 2) {
        printf("Invalid use. There should be just one argument (operation pointer).\n");
        exit(EXIT_FAILURE);
    }
}

int switch_case_chooser(const char* letter) {
    if (strcmp(letter, "i") == 0) {
        return 1;
    } else {
        if (strcmp(letter, "r") == 0) {
            return 2;
        } else {
            if (strcmp(letter, "p") == 0) {
                return 3;
            } else {
                if (strcmp(letter, "v") == 0) {
                    return 4;
                } else {
                    if (strcmp(letter, "q") == 0) {
                        return 5;
                    } else {
                        return -1;
                    }
                }
            }
        }
    }
}

void invalid_argument() {
    printf("\n");
    printf("Inavlid argument.\n");
    printf("i - initialize semaphore and print info\n");
    printf("r - remove semaphore\n");
    printf("p - leave semaphore and print info (passering)\n");
    printf("v - lift semaphore and print info (vrijgave)\n");
    printf("q - print info (query)\n");
    printf("\n");
}