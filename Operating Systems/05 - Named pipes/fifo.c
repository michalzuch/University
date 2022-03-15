#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/types.h>

void arguments_error(int arguments);
void remove_fifo(void);

int main(int argc, const char* argv[]) {
    arguments_error(argc);

    atexit(remove_fifo);

    mkfifo("fifo", 0666);

    // PRODUCER
    switch(fork()) {
        case -1:
            printf("fork() error\n");
            exit(EXIT_FAILURE);
        case 0:
            usleep(rand() % 100);
            if ((execl("./producer.x", "producer.x", argv[1], "fifo", NULL)) == -1) {
                perror("execl() error");
                _exit(EXIT_FAILURE);
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
            usleep(rand() % 100);
            if ((execl("./consumer.x", "consumer.x", argv[2], "fifo", NULL)) == -1) {
                perror("execl() error");
                _exit(EXIT_FAILURE);
            }
            break;
        default:
            break;
    }

    wait(NULL);
    wait(NULL);

    return 0;
}

void arguments_error(int arguemnts) {
    if (arguemnts != 3) {
        printf("Invalid usage. Scheme: ./fifo.x <storage> <clipboard>\n");
        _exit(EXIT_FAILURE);
    }
}

void remove_fifo(void) {
    unlink("fifo");
    printf("'fifo' removed.\n");
}