#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "sem.h"

const char* name = "/semaphore";

void arguments_error(int arguments);
void exit_func(void);
void my_sighandler(int signal);


int main(int argc, const char* argv[]) {

    arguments_error(argc);
    int fork_amount = atoi(argv[2]);
    int sections = atoi(argv[3]);
    int waiter = 0;
    int i;

    atexit(exit_func);

    int fd_number = open("number.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
    if (fd_number == -1) {
        perror("Error while opening file 'number.txt'\n");
        exit(EXIT_FAILURE);
    }

    if (write(fd_number, "0", sizeof(char)) == -1) {
        perror("Error while writing to file 'number.txt'");
        exit(EXIT_FAILURE);
    }

    semid semaphore_id = semCreate(name, 1);
    printf("Semaphore's address: %p\n", (void *)semaphore_id);
    semInfo(semaphore_id, sem_val);

    if (signal(2, my_sighandler) == SIG_ERR) {
        perror("Error while handling the signal");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < fork_amount; i++) {
        switch (fork()) {
        case -1:
            perror("fork() error");
            exit(EXIT_FAILURE);
        case 0:
            if ((execl("./prog.x", "prog.x", argv[2], argv[3], NULL)) == -1) {
                perror("execl() error");
                exit(EXIT_FAILURE);
            }
            waiter = 0;
            break;
        default:
            waiter++;
            break;
        }
    }
    for(i = 0; i < waiter; i++) {
		wait(NULL);
	}

    // Verification
    FILE *fin;
    int number;
    if ( (fin = fopen("number.txt", "r")) == NULL) {
        perror("Error while opening number.txt");
        exit(EXIT_FAILURE);
    }
    int data_read = fscanf(fin, "%i", &number);
    if (data_read == -1) {
        perror("Error while reading data");
        exit(EXIT_FAILURE);
    }
    printf("file: %d, target: %d\n", number, (fork_amount * sections));

    close(fd_number);
}

void arguments_error(int arguments) {
    if (arguments != 4) {
        printf("Invalid use.\n Template: ./multiplier.x ./prog.x <number of processes> <number of critical sections of the process>\n");
        exit(EXIT_FAILURE);
    }
}

void exit_func(void) {
    semRemove(name);
}

void my_sighandler(int signal) {
    exit(EXIT_SUCCESS);
}