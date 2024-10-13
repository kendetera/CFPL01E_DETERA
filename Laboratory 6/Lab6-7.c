#include <stdio.h>

int even(int num);

int main()
{
    int numbers[5];

    printf("Enter 5 integers:\n");
    for (int i = 0; i < 5; i++)
    {
        printf("Number %d: ", i + 1);
        scanf("%d", &numbers[i]);
    }

    for (int i = 0; i < 5; i++)
    {
        if (even(numbers[i]))
        {
            printf("Number %d (%d) is even.\n", i + 1, numbers[i]);
        }
        else
        {
            printf("Number %d (%d) is odd.\n", i + 1, numbers[i]);
        }
    }

    return 0;
}

int even(int num)
{
    return num % 2 == 0;
}