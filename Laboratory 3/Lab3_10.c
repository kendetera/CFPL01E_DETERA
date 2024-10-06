#include <stdio.h>

int main()
{
    char size;
    float price, discount = 0;

    printf("Enter the shirt size.\nL for Large, X for Extra Large): ");
    scanf(" %c", &size);

    printf("Enter the price of the shirt: ");
    scanf("%f", &price);

    if (size == 'X' || size == 'x')
    {
        if (price > 500)
        {
            discount = 100;
        }
    }
    // Check for L size and price greater than 400
    else if (size == 'L' || size == 'l')
    {
        if (price > 400)
        {
            discount = 50;
        }
    }

    if (discount > 0)
    {
        printf("You get a discount of %.2f pesos!\n", discount);
    }
    else
    {
        printf("No discount applicable.\n");
    }

    return 0;
}
