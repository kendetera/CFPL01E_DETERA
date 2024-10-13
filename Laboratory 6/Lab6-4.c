#include <stdio.h>

void EquiGrade(int grade);

int main()
{
    int grade;

    printf("Enter grade: ");
    scanf("%d", &grade);

    EquiGrade(grade);

    return 0;
}

void EquiGrade(int grade)
{
    if (grade >= 90)
    {
        printf("A! - Excellent\n");
    }
    else if (75 <= grade < 90)
    {
        printf("B! - Good\n");
    }
    else
    {
        printf("C! - Poor\n");
    }
}
