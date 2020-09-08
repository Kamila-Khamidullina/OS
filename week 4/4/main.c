#include <stdio.h>
#include <stdlib.h>

void read_new(char *command){
    fgets(command, 10, stdin);
}

int main(){
    char command[100];
    while(1){
        printf("> ");
        read_new(command);
        system(command);
    }
}

