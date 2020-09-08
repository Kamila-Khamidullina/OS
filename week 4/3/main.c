#include <stdio.h>
#include <stdlib.h>

void read_new(char *command){
    scanf("%s", command);
}

int main(){
    char command[100];
    while(1){
        printf("> ");
        read_new(command);
        system(command);
    }
}

