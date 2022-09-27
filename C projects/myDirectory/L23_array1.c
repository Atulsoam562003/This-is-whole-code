#include <stdio.h>
int main()
{
    // int marks[5] = {99,33,59,67,94};
    // marks[0]=99;
    // marks[1]=33;
    // marks[2]=59;
    // marks[3]=67;
    // marks[4]=94;
    // printf("The marks of first student are %d\n", marks[0]);

    // for (int i = 0; i <= 4; i++)
    // {
    //     printf("Enter the value of %d element of the array\n ",i );
    //     scanf("%d", &marks[i]);
    // }
    int marks[2][5] = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}};
    for (int i = 0; i <= 1; i++)
    {
        for (int j = 0; j <= 4; j++)
        {
            // printf("The value of the %d,%d element of the 2D array is: %d \n", i, j, marks[i][j]);
            printf("%d\t", marks[i][j]);
        }
        printf("\n");
        
    }
    return 0;
}
