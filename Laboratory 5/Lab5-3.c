#include <stdio.h>

int main()
{
    int arr[10], i, sum = 0;

    printf("Enter 10 integers:\n");
    for (i = 0; i < 10; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (i = 1; i < 10; i++)
    {
        if (arr[i] > 80)
        {
            sum += arr[i];
        }
    }

    printf("The sum of elements greater than 80 is %d\n", sum);

    return 0;
}