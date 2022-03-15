#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <unistd.h>
#include "procinfo.h"

// UID	-	userID
// GID	-	groupID
// PID	-	process ID
// PPID	-	parent PID
// PGID	-	process group ID

int procinfo(const char* proc_name){
    printf("name: %11s | "
        "UID %d | "
        "GID %d | "
        "PID %d | "
        "PPID %d | "
        "PGID %d\n"
        "PGID %d\n"
        "PGID %d\n",
        proc_name, getuid(), getgid(), getpid(), getppid(), getpgid(getpid()), getpgid(0), getpgrp());
    return 0;
}
