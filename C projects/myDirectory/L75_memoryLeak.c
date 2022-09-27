#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i = 0, a;
    int *i2;
    while (i < 45555)
    {
        printf("Welcome to the second last lecture\n");
        i2 = malloc(34444 * sizeof(int));
        if (i % 100 == 0)
        {
            getchar();
        }
        i++;
        free(i2);//without this we will encounter a situation of memory leak
    }
    return 0;
}
