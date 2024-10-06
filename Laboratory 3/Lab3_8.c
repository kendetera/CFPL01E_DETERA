#include <stdio.h>

int main()
{
    char choice;
    float s1, s2, s3, base, height, perimeter, area;

    printf("Do you want to compute for Perimeter (P) or Area (A)?\nEnter P for Perimeter, A for Area: ");
    scanf("%c", &choice);

    if (choice == 'P' || choice == 'p')
    {
        printf("Enter the length of the first side: ");
        scanf("%f", &s1);
        printf("Enter the length of the second side: ");
        scanf("%f", &s2);
        printf("Enter the length of the third side: ");
        scanf("%f", &s3);

        perimeter = s1 + s2 + s3;

        printf("The perimeter of the triangle is: %.2f\n", perimeter);
    }
    else if (choice == 'A' || choice == 'a')
    {
        printf("Enter the base of the triangle: ");
            scanf("%f", &base);
        printf("Enter the height of the triangle: ");
            scanf("%f", &height);

        area = (base * height) / 2;

        printf("The area of the triangle is: %.2f\n", area);
    }
    else
    {
        printf("Invalid choice. Please enter P for perimeter or A for area.\n");

        return 0;
    }
}
