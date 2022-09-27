#include <stdio.h>
int main()
{
    int n,a=0;
    printf("Enter the no\n");
    scanf("%d", &n);

    while(a<n)
    {
        for (int i = 1; i <= n; i++)
        {
            printf("%c", '*');
        }
        printf("\n");
        a++;
    }
    return 0;
}
