#include <stdio.h>

int main()
{
    int arr[20], i, sum = 0;

    printf("Enter 20 integers:\n");
    for (i = 0; i < 20; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("The even numbers in the array are:\n");
    for (i = 1; i < 20; i += 2)
    {
        if (arr[i] % 2 == 0)
        {
            printf("%d\n", arr[i]);
            sum += arr[i];
        }
    }
    printf("The sum of all even numbers are: %d\n", sum);

    return 0;
}