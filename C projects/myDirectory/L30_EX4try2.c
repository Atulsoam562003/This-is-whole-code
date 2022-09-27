// Take input from the user and ask the user to choose 0 for triangular star pattern and 1 for reverse triangular star pattern
// Then print the pattern accordingly
/* 
*
**
***
****
THIS WAS TRIANGULAR STAR PATTERN 

****
***
**
*
THIS WAS REVERSE TRIANGULAR STAR PATTERN 
*/
#include <stdio.h>
int starpattern(int n)
{
    for (int i = 1; i <= n; i++)
    {
        printf("%c",'*');
    }
    
}
int main()
{
    printf("PRESS 0 FOR TRIANGULAR STAR PATTERN \n PRESS 1 FOR REVERSE TRIANGULAR STAR PATTERN \n");
    int a, s;
    scanf("%d", &a);
    if (a == 1)
    {
        printf("YOU CHOSE REVERSE TRIANGULAR STAR PATTERN \n");
    }
    else
    {
        if (a == 0)
        {
            printf("YOU CHOSE FOR TRIANGULAR STAR PATTERN\n ");
            printf("Enter the number of stars in the last line of your star pattern\n");
            scanf("%d", &s);
            int e = 1;
            while (e <= s)
            {
               starpattern(e);
                // printf("%c\n", '*');
                e++;
            }
           
        }
        else
        {
            printf("OOPS!!! NOT AN OPTION \a");
        }
    }

    return 0;
}
