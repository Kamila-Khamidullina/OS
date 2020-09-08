#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t flag = fork();
    pid_t pid = getpid();
    if (flag == 0)
        printf("Hello from child [%d - %d]\n", pid, 10);
    else
        printf("Hello from parent [%d - %d]\n", pid, 10);
    return 0;
}

/*
Fork is a systemcall which creates a new process.
Child and parent have different PIDs.
Fork returns zero to child-process and the PID of a child to the parent-process.
*/
