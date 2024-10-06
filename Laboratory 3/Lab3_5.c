#include <stdio.h>

int main()
{
    int a, b, c, d, e;
    int highest, lowest;

    printf("Enter five numbers:\n");
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);

    if (a > b && a > c && a > d && a > e)
    {
        highest = a;
    }
    else if (b > a && b > c && b > d && b > e)
    {
        highest = b;
    }
    else if (c > a && c > b && c > d && c > e)
    {
        highest = c;
    }
    else if (d > a && d > b && d > c && d > e)
    {
        highest = d;
    }
    else
    {
        highest = e;
    }

    if (a < b && a < c && a < d && a < e)
    {
        lowest = a;
    }
    else if (b < a && b < c && b < d && b < e)
    {
        lowest = b;
    }
    else if (c < a && c < b && c < d && c < e)
    {
        lowest = c;
    }
    else if (d < a && d < b && d < c && d < e)
    {
        lowest = d;
    }
    else
    {
        lowest = e;
    }

    printf("The highest number is: %d\n", highest);
    printf("The lowest number is: %d\n", lowest);

    return 0;
}
