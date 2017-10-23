// Practice functions

#include <stdio.h>

float average(float x, float y)
{
    return (x + y) / 2;
}

int main(void)
{

    float x, y, z;

    printf("Enter three numbers: ");
    scanf("%f %f %f", &x, &y, &z);

    printf("Average of %.2f and %.2f: %.2f\n", x, y, average(x, y));
    printf("Average of %.2f and %.2f: %.2f\n", x, z, average(x, z));
    printf("Average of %.2f and %.2f: %.2f\n", y, z, average(y, z));

    return 0;
}
