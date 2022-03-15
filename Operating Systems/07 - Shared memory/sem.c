#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <semaphore.h>
#include "sem.h"

// typedef sem_t *semid;

// Creates a semaphore with initial value val.
semid semCreate(const char *name, int val) {
    printf("Creating semaphore...\n");
    name = "/semaphore";
    sem_t *sem = sem_open(name, O_CREAT | O_EXCL, 0666, val);
    if(sem == NULL) {
        perror("Error while creating a semaphore");
        exit(EXIT_FAILURE);
    }
    printf("Semaphore created.\n");

    return sem;
}

// Removes a semaphore.
void semRemove(const char *name) {
    printf("Removing semaphore...\n");
    if (sem_unlink(name) == -1) {
        perror("Error while removing semaphore");
        exit(EXIT_FAILURE);
    }
    printf("Semaphore removed.\n");
}

// Accesses an existing semaphore.
semid semOpen(const char *name) {
    printf("Accessing semaphore...\n");
    sem_t *sem = sem_open(name, 0);
    if(sem == NULL) {
        perror("Error while opening semaphore");
        exit(EXIT_FAILURE);
    }
    printf("Semaphore opened.\n");

    return sem;
}

// Closes the semaphore on the given process.
void semClose(semid sem) {
    printf("Closing semaphore...\n");
    if (sem_close(sem) == -1) {
        perror("Error while closing semaphore");
        exit(EXIT_FAILURE);
    }
    printf("Semaphore closed\n");
}

// Drop semaphore: decrease the value of the semaphore by 1 or wait.
void semP(semid sem) {
    printf("Dropping semaphore...\n");
    if (sem_wait(sem) == -1) {
        perror("Error while dropping semaphore");
        exit(EXIT_FAILURE);
    }
    printf("Semaphore dropped.\n");
}

// Lift the semaphore: Increase the value of the semaphore by 1 or resume the waiting process.
void semV(semid sem) {
    printf("Lifting semaphore...\n");
    if (sem_post(sem) == -1) {
        perror("Error while lifting semaphore");
        exit(EXIT_FAILURE);
    }
    printf("Semaphore lifted.\n");
}

// The function prints information about the value of the semaphore, possibly,
// if the system allows such a possibility, also about the number of waiting processes.
void semInfo(semid sem, int sem_val) {
    printf("Getting the values...\n");
    if (sem_getvalue(sem, &sem_val) == -1) {
        perror("Error while getting semaphore's value");
        exit(EXIT_FAILURE);
    }
    printf("Semaphore's value: %d\n", sem_val);
}