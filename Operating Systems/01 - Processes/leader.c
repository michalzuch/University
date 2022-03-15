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

	int i;
	for(i = 0; i < 3; i++) {
		int var_fork = fork();
		switch (var_fork) {
			case -1:
				perror("fork() errror");
				exit(1);
			case 0:
				/* Leader of your own group */
				setpgid(var_fork, 0);
				/* Changing the name of the process to "child" */
				strcpy(argv[0], "child");
				procinfo(argv[0]);
				sleep(1);
				break;
			default:
				break;
			}
		}
	while(wait(NULL) > 0);
	return 0;
}
