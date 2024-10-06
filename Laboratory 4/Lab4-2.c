#include <stdio.h>

void main() {
    int num, i, sum = 0;

    printf("Enter a number: ");
    scanf("%d", &num);

    for(i = 1; i <= num; i++) {
        sum += i; 
    }

    printf("The sum of all numbers from 1 to %d is: %d", num, sum);
}
