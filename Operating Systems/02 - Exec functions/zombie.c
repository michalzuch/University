#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main(void) {
    if (fork() == 0) {
        // child process
        exit(0);
    }
    sleep(60);
    exit(0);
}