#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <semaphore.h>
#include <wait.h>
#include <sys/types.h>

#include "sem.h"
#include "shmem.h"

#define NELE 20  // Buffer element size (bytes)
#define NBUF 5   // The number of elements in the buffer
#define SHMEMSIZE 1024

void remove_resources(void);

const char* sem_prod = "/sem_prod";
const char* sem_cons = "/sem_cons";
const char* shared_memory = "/shared_memory";
int value;

typedef char towar;

semid semaphoreProd;
semid semaphoreCons;
int sharedMemory;

int main(void) {
    // Producer semaphore
    semaphoreProd = semCreate(sem_prod, NBUF);

    // Consumer semaphore
    semaphoreCons = semCreate(sem_cons, 0);

    // Shared Memory
    sharedMemory = shmCreate(shared_memory, SHMEMSIZE);

    atexit(remove_resources);

    // PRODUCER
    switch(fork()) {
        case -1:
            printf("fork() error\n");
            exit(EXIT_FAILURE);
        case 0:
            if ((execl("./producer.x", "producer.x", NULL)) == -1) {
                perror("execl() error");
                exit(EXIT_FAILURE);
            }
            break;
        default:
            break;
    }
    
    // CONSUMER
    switch(fork()) {
        case -1:
            printf("fork() error\n");
            exit(EXIT_FAILURE);
        case 0:
            if ((execl("./consumer.x", "consumer.x", NULL)) == -1) {
                perror("execl() error");
                exit(EXIT_FAILURE);
            }
            break;
        default:
            break;
    }
    wait(NULL);
    wait(NULL);

    return 0;
}

void remove_resources(void) {
    semRemove(sem_prod);
    semRemove(sem_cons);
    shmRm(shared_memory);
}