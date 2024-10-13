#include <stdio.h>

int input();
int computeSquare(int num);
void displayResult(int num, int square);

int main()
{
    int n = input();
    for (int i = 1; i <= n; i++)
    {
        int square = computeSquare(i);
        displayResult(i, square);
    }
}

int input()
{
    int num;

    printf("Enter an integer: ");
    scanf("%d", &num);
    return num;
}

int computeSquare(int num)
{
    return num * num;
}

void displayResult(int num, int square)
{
    printf("The square of %d is %d\n", num, square);
}
