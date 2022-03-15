#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include "procinfo.h"


// Function declarations
int switch_case_chooser(const char*);

// The declarations of the error handlers
void arguments_number_error(int);
void invalid_argument_error(void);
void my_sighandler(int);
void signal_exceptions(int);

int main(int argc, char* argv[]) {
    // Checking program input data
    arguments_number_error(argc);
    int signal_number = atoi(argv[2]);
    signal_exceptions(signal_number);

    // Information about the process
    procinfo(argv[0]);

    // Signal handling
    switch (switch_case_chooser(argv[1]))
    {
    case -1:
        invalid_argument_error();
        exit(EXIT_FAILURE);
    case 1: // d
        if(signal(signal_number, SIG_DFL) == SIG_ERR) {
            perror("Signal function has encountered error with default operation.");
            exit(EXIT_FAILURE);
        }
        pause();
        break;
    case 2: // i
        if (signal(signal_number, SIG_IGN) == SIG_ERR) {
            perror("Signal function has encountered error with ignoring operation.");
            exit(EXIT_FAILURE);
        }
        pause();
        break;
    case 3: // p
        if(signal(signal_number, my_sighandler) == SIG_ERR) {
            perror("Signal function has encountered error.");
            exit(EXIT_FAILURE);
        }
        pause();
        break;
    default:
        break;
    }
}

// FUNCTIONS

int switch_case_chooser(const char* letter) {
    if (strcmp(letter, "d") == 0) {
        return 1;
    } else {
        if (strcmp(letter, "i") == 0) {
            return 2;
        } else {
            if (strcmp(letter, "p") == 0) {
                return 3;
            } else {
                return -1;
            }
        }
    }
}

void my_sighandler(int signal) {
    printf("\nIntercepted signal: %d\n", signal);
}

// ERRORS

void arguments_number_error(int num_arguments) {
    if (num_arguments != 3) {
        printf("Invalid number of arguments. Correct usage: ./handling.x <action type> <signal number>\n");
        exit(EXIT_FAILURE);
    }
}

void signal_exceptions(int signal_number) {
    if (signal_number == 9 || signal_number == 19) {
        printf("Signal cannot be handled.\n");
        exit(EXIT_FAILURE);
    }
}

void invalid_argument_error(void) {
    printf("\n");
    printf("Invalid argument. Possible arguments:\n");
    printf("d - default operation\n");
    printf("i - ignore signal\n");
    printf("p - signal interception and self-handling\n");
    printf("\n");
}
