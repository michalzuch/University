#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "shmem.h"
#define SHM_BUF_SIZE 64

int arguments_entry_operations(int amount, const char* letter);
int case_chooser(const char* letter);
void possible_arguments(void);
void how_to_use(void);

int main(int argc, const char* argv[]) {

	const char name[] = "/shared_memory";
	char *ptr;
	int fd;
	int size;
	int reading;
	int writing;
	int choose_case;

	choose_case = arguments_entry_operations(argc, argv[1]);

	switch(choose_case) {
		case -1:
			printf("Invalid argument.\n");
			possible_arguments();
			exit(EXIT_FAILURE);
		case 1:
			size = atoi(argv[2]);
			fd = shmCreate(name, size);
			size = shmSize(fd);
			break;
		case 2:
			shmRm(name);
			break;
		case 3:
			fd = shmOpen(name);
			size = shmSize(fd);
			ptr = shmMap(fd, size);
			printf("Shared memory: %s\n", ptr);
			break;
		case 4:
			fd = shmOpen(name);
			size = shmSize(fd);
			ptr = shmMap(fd, size);
			while ((reading = read(STDIN_FILENO, ptr, SHM_BUF_SIZE)) > 0) {
					if (reading == -1) { perror("Reading from shared memory failed"); }
				writing = write(fd, ptr, reading);
					if (writing == -1) { perror("Writing to terminal fialed"); }
			}
			break;
		case 5:
			fd = shmOpen(name);
			size = shmSize(fd);
			shmInfo(fd);
			break;
		case 6:
			how_to_use();
			break;
		default:
			break;
	}

	return 0;
}

// ERRORS, MESSAGES
void possible_arguments(void) {
	printf(
		"Possible arguments:\n"
		"c - create a shared memory of *size* bytes\n"
		"d - delete shared memory\n"
		"r - print data from shared memory\n"
		"w - copy the input to the shared memory\n"
		"i - print info about shared memory\n"
		"*empty* - print info of app usage\n"
	);
}

void how_to_use(void) {
	printf("HOW TO USE APP\n");
	printf("shmuse.x takes one argument.\n");
	possible_arguments();
	printf("In case 'c' there is another argument size for\n"
	"setting size of shared memory.\n");
}

// FUNCTIONS
int case_chooser(const char* letter) {
    if (strcmp(letter, "d") == 0) {
        return 2;
    } else {
        if (strcmp(letter, "r") == 0) {
            return 3;
        } else {
            if (strcmp(letter, "w") == 0) {
                return 4;
            } else {
                if (strcmp(letter, "i") == 0) {
                return 5;
            } else {
				return -1; }
			}
		}
	}
}

int arguments_entry_operations(int amount, const char* letter) {
	if (amount > 3) {
		printf("Too many arguments!\n");
		exit(EXIT_FAILURE);
	} else {
		switch(amount) {
			case 1:
				return 6;
			case 2:
				return case_chooser(letter);
			case 3:
				return 1;
			default:
				return -1;
		}
	}
}