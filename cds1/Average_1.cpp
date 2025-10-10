#include <stdio.h>
int main()
{
    float a, b;

    scanf("%f %f", &a, &b);
    float avg = ((3.5 * a) + (b * 7.5)) / 11;
    printf("MEDIA = %.5f\n", avg);
    return 0;
}