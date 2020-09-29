#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    printf("Enter the number of integers: ");
    scanf("%d", &N);
    int *array = malloc(N*sizeof(int));
    for (int i = 0; i < N; i++)
        array[i] = i;
    printf("The array:");
    for (int i = 0; i < N; i++)
        printf(" %d", array[i]);
    free(array);
    return 0;
}
