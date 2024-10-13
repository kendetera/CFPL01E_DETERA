#include <stdio.h>

unsigned long factorial(int n);

void main() {
    int n;
    unsigned long fact;

    printf("Enter a positive integer: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Factorial is not defined for negative numbers.\n");
    } else {
        fact = factorial(n);
        printf("Factorial of %d = %lu\n", n, fact);
    }
}

unsigned long factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}
