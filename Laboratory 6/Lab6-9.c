#include <stdio.h>

int reverseDigits(int num);

int main()
{
    int number;

    printf("Enter a 5-digit integer: ");
    scanf("%d", &number);

    if (number < 10000 || number > 99999)
    {
        printf("Error: Please enter a valid 5-digit integer.\n");
    }
    else
    {
        int reversedNumber = reverseDigits(number);
        printf("Reversed number: %d\n", reversedNumber);
    }

    return 0;
}

int reverseDigits(int num)
{
    int reversed = 0;

    while (num > 0)
    {
        reversed = reversed * 10 + (num % 10);
        num /= 10;
    }

    return reversed;
}
