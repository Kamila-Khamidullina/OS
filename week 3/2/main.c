#include <stdio.h>

void bubble_sort(int* array, int n){
    int swap;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n - i; j++)
            if (*(array + j) > *(array + j + 1)){
                swap = *(array + j);
                *(array + j) = *(array + j + 1);
                *(array + j + 1) = swap;
            }
}

int main() {
    int n;
    printf("Enter the number of integers:");
    scanf("%d", &n);
    int array[n];
    printf("Enter the array:");
    for (int i = 0; i < n; i++)
        scanf("%d", &(array[i]));
    bubble_sort(array, n);
    printf("Sorted array:");
    for (int i = 0; i < n; i++)
        printf(" %d", *(array + i));
    return 0;
}
