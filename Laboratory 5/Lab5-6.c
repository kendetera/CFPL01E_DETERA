#include <stdio.h>

int main()
{
    int arr[10], i, j, temp;

    printf("Enter 10 integers:\n");
    for (i = 0; i < 10; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    printf("The sorted array in ascending order is:\n");
    for (i = 0; i < 10; i++)
    {
        printf("%d\n", arr[i]);
    }

    return 0;
}