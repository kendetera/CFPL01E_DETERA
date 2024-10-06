#include <stdio.h>

int main()
{
    float temperature;

    printf("Enter temperature: ");
    scanf("%f", &temperature);

    if (temperature < 20)
    {
        printf("IT'S COLD!\n");
    }
    else if (temperature > 30)
    {
        printf("IT'S HOT!\n");
    }
    else
    {
        printf("IT'S COOL CLIMATE!\n");
    }

    return 0;
}
