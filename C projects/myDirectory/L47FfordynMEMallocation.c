#include <stdio.h>
#include <stdlib.h> //

int main()
{
    // // use of malloc
    // int *ptr;
    // int n;
    // printf("Enter the size of array you want to create\n");
    // scanf("%d",&n);
    // ptr = (int *)malloc(n * sizeof(int));
    // for (int i = 0; i < n; i++)
    // {
    //     printf("Enter the value no %d of this array\n", i);
    //     scanf("%d", &ptr[i]);
    // }
    // for (int i = 0; i < n; i++)
    // {
    //     printf("The value of element at index %d of the array is %d\n",i, ptr[i]);
    // }

    // use of calloc
    int *ptr;
    int n;
    printf("Enter the size of array you want to create\n");
    scanf("%d", &n);
    ptr = (int *)calloc(n, sizeof(int));
    for (int i = 0; i < n; i++)
    {
        printf("Enter the value no %d of this array\n", i);
        scanf("%d", &ptr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        printf("The value of element at index %d of the array is %d\n", i, ptr[i]);
    }

    // use of realloc
    
    printf("Enter the size of array you want to create\n");
    scanf("%d", &n);
    ptr = (int *)realloc(ptr, n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        printf("Enter the value no %d of this array\n", i);
        scanf("%d", &ptr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        printf("The value of element at index %d of the array is %d\n", i, ptr[i]);
    }
    return 0;
    free(ptr);
}
