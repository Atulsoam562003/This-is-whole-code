#include <stdio.h>
#include <string.h>
// PRINT AN ARRAY, WHICH IS ASKED FROM THE USER, BEFORE AND AFTER REVERSING IT
void arrayREV(int *ptr)
{int j=0;
    for (int i = 0; i < 8; i=8-j)
    {
      j++;
    }
}

int main()
{
    int arr[8];
    for (int i = 0; i < 8; i++)
    {
        printf("The %d element of the array should be:   \n", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("Thanks for providing the values\n");
    for (int j = 0; j < 8; j++)
    {
        printf("The element of array at index %d is %d\n", j + 1, arr[j]);
    }

    arrayREV(&arr);

    for (int j = 0; j < 8; j++)
    {
        printf("The NEW ASSIGNED element of array at index %d is %d\n", j + 1, arr[j]);
    }
    return 0;
}
