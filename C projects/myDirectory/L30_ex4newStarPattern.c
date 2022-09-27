#include <stdio.h>
int REVstarpattern(int rows)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j <= rows - 1 - i; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}

int main()
{
    int r;
    printf("THIS IS A REVERSE TRIANGULAR STAR PATTERN APPLICATION\n");
    printf("how many rows do you want?\n");
    scanf("%d", &r);
    REVstarpattern(r);
    return 0;
}
