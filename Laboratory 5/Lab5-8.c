#include <stdio.h>

int main()
{
    int arr[20], i, sum = 0;
    float average;

    printf("Enter 20 integers:\n");
    for (i = 0; i < 20; i++)
    {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    average = sum / 20.0;

    printf("The average of the elements is: %.2f\n", average);

    return 0;
}