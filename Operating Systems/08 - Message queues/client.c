#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>

#include "msg.h"

#define MAX_FGETS 100

int math_operator(const char* symbol);
void exit_function(void);
void my_sighandler(int signal);
int pass_fd;

int main(void){
    
    atexit(exit_function);

    if(signal(SIGINT, my_sighandler) == SIG_ERR) {
            perror("Signal function has encountered error.");
            exit(EXIT_FAILURE);
    }

    int server;
    message msg;
    int pid = getpid();
    char equation[MAX_FGETS];

    //  Open client's descriptor
    char name[10];
    sprintf(name, "/%d", pid);
    int client = msgCreate(name);

    printf("Name       :%10s\n", name);
    printf("Descriptor :%10d\n", client);
    msgInfo(client);
    

    server = msgOpen(SERVER_NAME);
    msg.pid = pid;
    pass_fd = client;

    printf("What do you want to calculate?\n");
    while(fgets(equation, MAX_FGETS, stdin) == (void *)EOF) {
        break;
    }

    char *token;

    //  Get value a
    token = strtok(equation, " ");
    msg.a = atoi(token);

    //  Get type of operation
    token = strtok(NULL, " ");
    msg.o = math_operator(token);

    //  Get value b
    token = strtok(NULL, " ");
    msg.b = atoi(token);

    msgSend(server, &msg);
    sleep(rand()%10);
    msgRecv(client, &msg);
    sleep(rand()%10);
    printf("Result: %d\n", msg.result);
}

int math_operator(const char* symbol) {
    if (strcmp(symbol, "+") == 0) {
        return 1;
    } else {
        if (strcmp(symbol, "-") == 0) {
            return 2;
        } else {
            if (strcmp(symbol, "*") == 0) {
                return 3;
            } else {
                if (strcmp(symbol, "/") == 0) {
                    return 4;
                } else {
                    return -1;
                }
            }
        }
    }
}

void exit_function(void) {
    char name[10];
    int pid = getpid();
    sprintf(name, "/%d", pid);
    msgClose(pass_fd);
    msgRm(name);
}

void my_sighandler(int signal) {
    exit_function();
    _exit(EXIT_SUCCESS);
}