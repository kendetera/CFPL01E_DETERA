#include <stdio.h>

int main()
{
    int month, day, year;

    const char *monthNames[] = {
        "Invalid", "January", "February", "March", "April",
        "May", "June", "July", "August", "September", "October",
        "November", "December"};

    printf("Enter month (1-12): ");
    scanf("%d", &month);

    printf("Enter day (1-31): ");
    scanf("%d", &day);

    printf("Enter year (e.g, 1999): ");
    scanf("%d", &year);

    if (month < 1 && month > 12)
    {
        printf("Invalid month\n");
    }
    else
    {
        printf("%s %d, %d\n", monthNames[month], day, year);
    }

    return 0;
}
