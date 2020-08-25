#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int width = 2*n - 1;
    int middle = (2*n - 2) / 2;
    int cur_width = 0;
    for (int line = 1; line <= n; line++){
        cur_width = 2*line - 1;
        int star_part = (cur_width - 1) / 2;
        int space_part = (middle - star_part);
        for (int j = 1; j <= space_part; j++)
            printf(" ");
        for (int j = 1; j <= star_part; j++)
            printf("*");
        printf("*");
        for (int j = 1; j <= star_part; j++)
            printf("*");
        for (int j = 1; j <= space_part; j++)
            printf(" ");
        printf("\n");
    }
    return 0;
}
