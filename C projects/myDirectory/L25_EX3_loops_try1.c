// BOTH THE APPROACH OF LECT 25  ARE BY MAKING FUNCTIONS 
#include <stdio.h>
int fib_ITERATIVE(int num)
{
    int a = 0;
    int b = 1;

    for (int i = 0; i < num - 1; i++)
    {
        b = a + b;
        a = b - a;
    }
    return a;
}

int main()
{
    int n;
    printf("Enter the position of element you want to receive fibonacci series for:\n");
    scanf("%d", &n);
    printf("The %d element of the fibonacci series is %d\n", n, fib_ITERATIVE(n));

    return 0;
}
