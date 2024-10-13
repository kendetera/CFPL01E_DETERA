#include <stdio.h>

int combination(int n, int m);

int main()
{
    int n, m;

    printf("Enter value of n: ");
    scanf("%d", &n);
    printf("Enter value of m: ");
    scanf("%d", &m);

    if (m > n)
    {
        printf("Invalid input! m must be less than or equal to n.\n");
    }
    else
    {
        printf("C(%d, %d) = %d\n", n, m, combination(n, m));
    }

    return 0;
}

int factorial(int num)
{
    int fact = 1;

    for (int i = 1; i <= num; i++)
    {
        fact *= i;
    }

    return fact;
}

int combination(int n, int m)
{
    return factorial(n) / (factorial(m) * factorial(n - m));
}
