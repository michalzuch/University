#define _POSIX_C_SOURCE 200809L
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

int switch_fork(int argc, char* argv[]);
void arguments_number_error(int);

int main(int argc, char* argv[]) {

    arguments_number_error(argc);

    int var_fork = fork();
    int send_signal = atoi(argv[2]);

    switch (var_fork) {
    case -1:
        perror("fork() error");
        exit(EXIT_FAILURE);
    case 0:
        setpgid(var_fork, 0);
        signal(send_signal, SIG_IGN);
        switch_fork(argc, argv);
        break;
    default:
        sleep(5);
        if (kill(-getpgid(var_fork),0) == -1) {
                printf("Process does not exist.");
                exit(EXIT_FAILURE);
            }
        kill(-var_fork, send_signal);
        wait(NULL);
        break;
    }
    
    return 0;
}

int switch_fork(int argc, char* argv[]) {

	int i;
    int process_end;
    int child_status;
	int child_counter = 0;

	for(i = 0; i < 3; i++) {
		switch (fork()) {
			case -1:
				perror("inner fork() errror");
				exit(1);
			case 0:
				child_counter = 0;
                execl("./handling.x", "handling.x", argv[1], argv[2], NULL);
                sleep(1);
				break;
			default:
				child_counter++;
                sleep(1);
				break;
			}
		if (child_counter == 0) {
			break;
		}
	}

    i = 0;

	while(i < child_counter) {
        process_end = wait(&child_status);
        printf("Process %d terminated\n", process_end);
        i++;
	}

	return 0;
}

void arguments_number_error(int num_arguments) {
    if (num_arguments != 3) {
        printf("Invalid number of arguments. Correct usage: ./group.x <action type> <signal number>\n");
        exit(EXIT_FAILURE);
    }
}