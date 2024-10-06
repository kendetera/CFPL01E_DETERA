#include <stdio.h>

int main()
{
    int arr[10], i;

    printf("Enter 10 integers:\n");
    for (i = 0; i < 10; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Even positioned elements are:\n");
    for (i = 1; i < 10; i +=2)
    {
        printf("%d\n", arr[i]);
    }

    return 0;
}
