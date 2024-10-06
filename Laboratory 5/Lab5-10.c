#include <stdio.h>

int main()
{
    int arr[20], i, sum = 0;

    printf("Enter 20 integers:\n");
    for (i = 0; i < 20; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("The odd numbers in the array are:\n");
    for (i = 0; i < 20; i ++)
    {
        if (arr[i] % 2 != 0)
        {
            printf("%d\n", arr[i]);
            sum += arr[i];
        }
    }
    printf("The sum of all odd numbers are: %d\n", sum);

    return 0;
}