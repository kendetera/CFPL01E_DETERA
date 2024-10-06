#include <stdio.h>

void main()
{
    int num, i;

    printf("Enter a number: ");
    scanf("%d", &num);

    for (i = 1; i <= num; i++)
    {
        printf("%d ", num);
    }
}
