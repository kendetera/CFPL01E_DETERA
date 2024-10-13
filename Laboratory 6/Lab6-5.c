#include <stdio.h>

float convert(float kilometers);

int main()
{
    float kilometers, meters;

    printf("Enter number in kilometers: ");
    scanf("%f", &kilometers);

    meters = convert(kilometers);

    printf("%.2f kilometers is equal to %.2f meters\n", kilometers, meters);

    return 0;
}

float convert(float kilometers)
{
    return kilometers * 1000;
}