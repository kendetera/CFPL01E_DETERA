#include <stdio.h>

void main()
{
    int arr[10], i, smallest;

    printf("Enter 10 integers:\n");
    for (i = 0; i < 10; i++)
    {
        scanf("%d", &arr[i]);
    }

    smallest = arr[0];

    for (i = 1; i < 10; i++)
    {
        if (arr[i] < smallest)
        {
            smallest = arr[i];
        }
    }

    printf("The smallest element in the array is %d\n", smallest);
}