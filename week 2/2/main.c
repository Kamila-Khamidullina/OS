#include <stdio.h>
#include <string.h>

int main() {
    char String[100];
    printf("Enter a string \n");
    gets(String);
    int length = strlen(String);
    char Reversed[length];
    int old = length - 1;
    int new = 0;
    while(new < length){
        Reversed[new] = String[old];
        new++;
        old--;
    }
    printf("%s", Reversed);
    return 0;
}
