#include <stdio.h>

void main()
{
    int n, i;

    printf("Enter a number: ");
    scanf("%d", &n);

    printf("The first %d odd numbers are: ", n);
    for (i = 1; i <= n; i++)
    {
        printf("%d ", 2 * i - 1);
    }
}
