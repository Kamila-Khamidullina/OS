#include <stdio.h>

void change(int* a, int* b){
    int c = *a;
    int d = *b;
    *a = d;
    *b = c;
}

int main() {
    int a, b;
    printf("Enter two numbers\n");
    scanf("%d", &a);
    scanf("%d", &b);
    change(&a, &b);
    printf("%d\n", a);
    printf("%d\n", b);

    return 0;
}
