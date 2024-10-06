#include <stdio.h>

void bubbleSort(int arr[], int n)
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1; j++)
        {
            if (arr[j] < arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int numbers[3];

    printf("Enter three numbers: \n");
    for (int i = 0; i < 3; i++)
    {
        printf("Number %d: ", i + 1);
        scanf("%d", &numbers[i]);
    }

    bubbleSort(numbers, 3);

    printf("Numbers in descending order: ");
    for (int i = 0; i < 3; i++)
    {
        printf("%d ", numbers[i]);
    }
    
return 0;

}
