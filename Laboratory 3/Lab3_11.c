#include <stdio.h>

int main()
{
    char name[100];
    float midtermGrade, minorB, finalExam, finalGrade, equivalentGrade;

    printf("Enter the student's name: ");
    scanf("%[^\n]%*c", name);

    printf("Enter the midterm grade: ");
    scanf("%f", &midtermGrade);

    printf("Enter the minor B grade: ");
    scanf("%f", &minorB);

    printf("Enter the final exam grade: ");
    scanf("%f", &finalExam);

    finalGrade = (0.30 * midtermGrade) + (0.10 * minorB) + (0.60 * finalExam);

    if (finalGrade >= 98 && finalGrade <= 100)
    {
        equivalentGrade = 4.00;
    }
    else if (finalGrade >= 95 && finalGrade <= 97)
    {
        equivalentGrade = 3.75;
    }
    else if (finalGrade >= 92 && finalGrade <= 94)
    {
        equivalentGrade = 3.50;
    }
    else if (finalGrade >= 89 && finalGrade <= 91)
    {
        equivalentGrade = 3.25;
    }
    else if (finalGrade >= 86 && finalGrade <= 88)
    {
        equivalentGrade = 3.00;
    }
    else if (finalGrade >= 83 && finalGrade <= 85)
    {
        equivalentGrade = 2.75;
    }
    else if (finalGrade >= 80 && finalGrade <= 82)
    {
        equivalentGrade = 2.50;
    }
    else if (finalGrade >= 77 && finalGrade <= 79)
    {
        equivalentGrade = 2.25;
    }
    else if (finalGrade >= 74 && finalGrade <= 76)
    {
        equivalentGrade = 2.00;
    }
    else if (finalGrade >= 71 && finalGrade <= 73)
    {
        equivalentGrade = 1.75;
    }
    else if (finalGrade >= 68 && finalGrade <= 70)
    {
        equivalentGrade = 1.50;
    }
    else if (finalGrade >= 64 && finalGrade <= 67)
    {
        equivalentGrade = 1.25;
    }
    else if (finalGrade >= 60 && finalGrade <= 63)
    {
        equivalentGrade = 1.00;
    }
    else
    {
        equivalentGrade = 0.00;
    }

    printf("Student Name: %s\n", name);
    printf("Final Grade: %.2f\n", finalGrade);
    printf("Equivalent Grade: %.2f\n", equivalentGrade);

    return 0;
}
