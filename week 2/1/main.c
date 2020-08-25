#include <stdio.h>
#include <limits.h>
#include <float.h>

int integer_var;
float float_var;
double double_var;

int main() {
    integer_var = INT_MAX;
    float_var = FLT_MAX;
    double_var = DBL_MAX;

    printf("Integer\n");
    printf("Size: %lu", sizeof(integer_var));
    printf(", value: %d\n", integer_var);

    printf("Float\n");
    printf("Size: %lu", sizeof(float_var));
    printf(", value: %f\n", float_var);

    printf("Double\n");
    printf("Size: %lu", sizeof(double_var));
    printf(", value: %g\n", double_var);
    return 0;
}
