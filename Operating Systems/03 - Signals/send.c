#define _POSIX_SOURCE
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, const char* argv[]) {

    int fork_var = fork();
    switch(fork_var) {
        case -1:
            perror("fork() error");
            exit(-1);
        case 0:
            execl("./handling.x", "handling.x", argv[1], argv[2], NULL);
            break;
        default:
            sleep(2);
            if (kill(fork_var,0) == -1) {
                printf("Process does not exist.");
                exit(EXIT_FAILURE);
            }
            kill(fork_var, atoi(argv[2]));
            printf("Process terminated.\n");
            break;
    }
}