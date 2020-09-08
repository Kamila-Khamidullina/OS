#include <stdio.h>
#include <stdlib.h>
int main(){
    for (int i = 0; i < 3; i++)
        fork();
    sleep(5);
    return 0;
}

/*
If fork is called 3 times, we see 2^3 processes.
If fork is called 5 times - 2^5 processes.
That happens because new process is a child of the old one.
*/
