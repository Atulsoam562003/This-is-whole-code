#include <stdio.h>
void main()
{
   int matrix[3][3], transpose[3][3];
   printf("Enter the numbers in the matrix\n ");
   for (int i = 0; i < 3; i++)
   {
      for (int j = 0; j < 3; j++)
      {
         printf("enter the number at (%d,%d) position of the matrix:", i + 1, j + 1);
         scanf("%d", &matrix[i][j]);
      }
   }
   printf("The matrix you entered is :\n");
   for (int i = 0; i < 3; i++)
   {
      for (int j = 0; j < 3; j++)
      {
         printf("%d\t", matrix[i][j]);
      }
      printf("\n");
   }
   //Transposing the matrix
   for (int i = 0; i < 3; i++)
   {
      for (int j = 0; j < 3; j++)
      {
            transpose[j][i]=matrix[i][j];
      }
   }
   // printing the transpose matrix
   for (int i = 0; i < 3; i++)
   {
      for (int j = 0; j < 3; j++)
      {  
         printf("%d\t", transpose[i][j]);
      }
      printf("\n");
   }
   // or we could have just printed it by using a for loop and printing the array matrix by changing external loop with internal for loop and changing the and matrix[col][row]
}
// instead of doing it like done in this program
