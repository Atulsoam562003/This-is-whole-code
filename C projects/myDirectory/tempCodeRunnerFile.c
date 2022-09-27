 if (c1 == r2)
    {
        printf("matrix multiplication is possible\n");
        int matrix1[r1][c1];
        int matrix2[r2][c2];
        for (int i = 0; i < r1; i++)
        {
            for (int j = 0; j < c1; j++)
            {
                printf("Enter the element at (%d,%d) position of matrix1:\n", i + 1, j + 1);
                scanf("%d", &matrix1[i][j]);
            }
        }
        for (int i = 0; i < r1; i++)
        {
            for (int j = 0; j < c1; j++)
            {
                printf("The element at (%d,%d) position of matrix1 is %d\n", i + 1, j + 1, matrix1[i][j]);
            }
        }

        printf("\n");
        printf("\n");

        for (int i = 0; i < r2; i++)
        {
            for (int j = 0; j < c2; j++)
            {
                printf("Enter the element at (%d,%d) position of matrix2:\n", i + 1, j + 1);
                scanf("%d", &matrix2[i][j]);
            }
        }
        for (int i = 0; i < r2; i++)
        {
            for (int j = 0; j < c2; j++)
            {
                printf("The element at (%d,%d) position of matrix2 is %d\n", i + 1, j + 1, matrix2[i][j]);
            }
        }
        printf("\n");
        printf("\n");

        // printf("multiplying the matrices............\n");
        // printf("\n");
        // printf("\n");

        // for (int i = 0; i < r1; i++)
        // {
        //     for (int j = 0; j < c2; j++)
        //     { //calculate result
        //         for (int k = 0; k < c1; k++)
        //         {
        //             sum += matrix1[i][k] * matrix2[k][j];
        //         }
        //         result[i][j] = sum;
        //         sum = 0;
        //     }
        // }
        // //printing the result matrix....
        // for (int i = 0; i < r1; i++)
        // {
        //     for (int j = 0; j < c2; j++)
        //     {
        //         //  printf("The element at (%d,%d) position of matrix2 is %d\n", i + 1, j + 1, result[i][j]);
        //         printf("%d \t", result[i][j]);
        //     }
        //     // printf("\n");
        // }
    }
    // else
    // {
    //     printf("SORRY!! matrix multiplication is NOT possible\n");
    // }