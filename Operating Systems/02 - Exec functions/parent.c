#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "procinfo.h"

int main(int argc, char* argv[]) {
	
	/* Changing the name of the process to "parent" */
	strcpy(argv[0], "parent");
	procinfo(argv[0]);

	int i;
	for(i = 0; i < 3; i++) {
		switch (fork()) {
			case -1:
				perror("fork() errror");
				exit(1);
			case 0:
				/* Changing the name of the process to "child" */
				strcpy(argv[0], "child");
				execv("./posterior.x", &argv[0]);
				perror("execv() error");
				sleep(1);
				break;
			default:
				break;
			}
		}
	while(wait(NULL) > 0);
	return 0;
}
