#include <stdio.h>

float findLargest(float a, float b, float c);

int main()
{
    float num1, num2, num3, largest;

    printf("Enter three floating-point numbers:\n");
    scanf("%f %f %f", &num1, &num2, &num3);
    
    largest = findLargest(num1, num2, num3);

    printf("The largest number is: %.2f\n", largest);

    return 0;
}

float findLargest(float a, float b, float c)
{
    float largest = a;

    if (b > largest)
    {
        largest = b;
    }
    if (c > largest)
    {
        largest = c;
    }

    return largest;
}