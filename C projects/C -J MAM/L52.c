#include <stdio.h>
void main()
{
    int arr1[7], arr2[7], arr3[7];
    printf("Enter the values of array 1\n");
    for (int i = 0; i < 7; i++)
    {
        printf("The value of elment at index no %d of array 1 is :  ", i);
        scanf("%d", &arr1[i]);
    }
    printf("Enter the values of array 2\n");
    for (int i = 0; i < 7; i++)
    {
        printf("The value of elment at index no %d of array 2 is :  ", i);
        scanf("%d", &arr2[i]);
    }
    for (int i = 0; i < 7; i++)
    {
        arr3[i] = arr1[i] + arr2[i];
    }
    for (int i = 0; i < 7; i++)
    {
        printf("The value of elment at index no %d of array 3 is : %d\n ", i, arr3[i]);
    }
}