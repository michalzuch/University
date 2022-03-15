#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "procinfo.h"

int main(int argc, char* argv[]) {
	
	/* Changing the name of the process to "parent" */
	strcpy(argv[0], "parent");
	procinfo(argv[0]);

	int child_counter = 0;
	int i;
	
	
	for(i = 0; i < 3; i++) {
		int var_fork = fork();
		switch (var_fork) {
			case -1:
				perror("fork() errror");
				exit(1);
			case 0:
				/* Changing the name of the process to "child" */
				strcpy(argv[0], "child");
				procinfo(argv[0]);
				child_counter = 0;
				break;
			default:
				child_counter++;
				break;
			}
		if (child_counter != 0) {
			break;
		}
	}
	for(i = 0; i < child_counter; i++) {
		wait(NULL);
	}
	return 0;
}
