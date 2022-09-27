#include <stdio.h>
void main()
{
    int matrix1[3][3], matrix2[3][2], resultMatrix[3][2], sum = 0;
    printf("Enter the values in matrix1\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("Enter the values at index no %d,%d of matrix 1 is :\t", i, j);
            scanf("%d", &matrix1[i][j]);
        }
    }
    printf("\n\n");

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("Enter the values at index no %d,%d of matrix 2 is :\t", i, j);
            scanf("%d", &matrix2[i][j]);
        }
    }
    printf("\n\n");
    // now multiplying the two matrices..............
    printf("multiplying the two matrices..............\n\n");

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                sum += matrix1[i][j] * matrix2[i][j];
            }
            resultMatrix[i][j] = sum;
            sum = 0;
        }
    }

    // printing the result...............
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("value at index no (%d,%d) of RESULT is %d \n", i, j, resultMatrix[i][j]);
        }
    }
}