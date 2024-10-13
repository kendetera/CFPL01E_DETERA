#include <stdio.h>

float findSmallest(float a, float b, float c);

int main()
{
    float num1, num2, num3, smallest;

    printf("Enter three floating-point numbers:\n");
    scanf("%f %f %f", &num1, &num2, &num3);
    
    smallest = findSmallest(num1, num2, num3);

    printf("The smallest number is: %.2f\n", smallest);

    return 0;
}

float findSmallest(float a, float b, float c)
{
    float smallest = a;

    if (b < smallest)
    {
        smallest = b;
    }
    if (c < smallest)
    {
        smallest = c;
    }

    return smallest;
}