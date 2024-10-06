#include <stdio.h>

int main(){

    float work, rate, salary, bonus;

    printf("Enter hours worked for the week:\n");
    scanf("%f", &work);

    printf("Enter the hourly rate:\n");
    scanf("%f", &rate);

    salary = work * rate;

    if (work > 45)
    {
        bonus = 500;
    }
    else if (work > 40 && work <= 45)
    {
        bonus = 250;
    }
    else if (work > 35 && work <= 40)
    {
        bonus = 150;
    }
    
    salary += bonus;

    printf("The basic salary is %.2f pesos.\n", salary - bonus);
    printf("The bonus is %.2f pesos.\n", bonus );
    printf("The total salary including bonus is %.2f pesos.\n", salary);

    return 0;
}
