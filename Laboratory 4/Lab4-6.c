#include <stdio.h>

void main()
{
    int i, sum = 0;

    for (i = 3; i <= 1000; i+=3)
    {
        sum += i;
    }
    printf("The sum of all numbers divisible by 3 from 1 to 1000 is: %d\n", sum);
}
