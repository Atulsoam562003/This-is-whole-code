#include <stdio.h>
void arrayREV(int arr[])
{
    // SWAP i with no. of elements in array-i
    // BUT YOU HAVE TO DO IT TILL HALF OF THE ARRAY ONLY,otherwise changing one half of the values with the other and then changing other half of the array with the first will give us reverse of reverse=> same

    for (int i = 0; i < 3 /*or 7/2*/; i++)
    {
        int temp = arr[i];
        arr[i] = arr[6 - i];
        arr[6 - i] = temp;
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 67};
    for (int i = 0; i < 7; i++)
    {
        printf("initially the element at %d index of the array is %d\n", i + 1, arr[i]);
    }

    arrayREV(arr);
    for (int j = 0; j < 7; j++)
    {
        printf("AFTER THE DECLARATION OF FUNCTION the element at %d index of the array is %d\n", j + 1, arr[j]);
    }

    return 0;
}
