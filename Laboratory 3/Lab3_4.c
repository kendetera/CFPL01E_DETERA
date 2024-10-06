#include <stdio.h>

int main()
{
    int years;
    float salary, bonus;

    printf("Enter years of service: ");
    scanf("%d", &years);

    printf("Enter salary: ");
    scanf("%f", &salary);

    if (years == 1)
    {
        bonus = 0.10 * salary;
    }
    else if (years >= 2 && years <= 5)
    {
        bonus = 0.20 * salary;
    }
    else if (years > 5 && years <= 10)
    {
        bonus = 0.50 * salary;
    }
    else if (years >= 11)
    {
        bonus = 0.75 * salary;
    }
    else
    {
        printf("Invalid number of years of service.\n");
        return 1;
    }

    printf("Salary: %.2f\n", salary);
    printf("Bonus: %.2f\n", bonus);

    return 0;
}
