#include <stdio.h>
void main()
{
    int matrix[3][3], sumR, sumC;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("Enter the value of elment at index no (%d,%d) of the 2D array:\t", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
    printf("Printing the sum of each row and column.......................\n\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            sumC = sumR = 0;
            sumC += matrix[i][j];
            sumR += matrix[j][i];
        }
        printf("sum of the elements of row= %d \n sum of the elements of column= %d\n", sumR, sumC);
    }
}