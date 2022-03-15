#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include "msg.h"

int calculator(int a, int o, int b);
void exit_function(void);
char *decoder(int operator);
void my_sighandler(int signal);
int pass_fd;

int main(void) {

    atexit(exit_function);

    if(signal(SIGINT, my_sighandler) == SIG_ERR) {
            perror("Signal function has encountered error.");
            exit(EXIT_FAILURE);
    }

    int server;
    server = msgCreate(SERVER_NAME);
    pass_fd = server;
    message msg;
    int pid;
    int result;
    int client;

    printf("Name       :%10s\n", SERVER_NAME);
    printf("Descriptor :%10d\n", server);
    msgInfo(server);

    while(1){
        sleep(rand()%10);
        msgRecv(server, &msg);

        pid = msg.pid;
        char name[10];
        sprintf(name, "/%d", pid);

        result = calculator(msg.a, msg.o, msg.b);
        msg.result = result;
        printf("%d %s %d = %d\n", msg.a, decoder(msg.o), msg.b, result);
        
        client = msgOpen(name);
        msgSend(client, &msg);
        sleep(rand()%10);
        msgClose(client);
    }
}

int calculator(int a, int o, int b) {
    switch(o) {
        case 1:
            return a + b;
        case 2:
            return a - b;
        case 3:
            return a * b;
        case 4:
            return a / b;
    }
    return -1;
}

void exit_function(void) {
    msgClose(pass_fd);
    msgRm(SERVER_NAME);
}

char *decoder(int operator) {
    if (operator == 1) {
        return "+";
    } else {
        if (operator == 2) {
            return "-";
        } else {
            if (operator == 3) {
                return "*";
            } else {
                if (operator == 4) {
                    return "/";
                }
            }
        }
    }
    return "f";
}

void my_sighandler(int signal) {
    exit_function();
    _exit(EXIT_SUCCESS);
}