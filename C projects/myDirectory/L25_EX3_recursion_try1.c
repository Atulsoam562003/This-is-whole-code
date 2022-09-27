#include <stdio.h>
int fibRECURSIVE(int num)
{
    if (num == 1 || num == 2)
    {
        return num-1;
    }
    else
    {
        return fibRECURSIVE(num - 1) + fibRECURSIVE(num - 2);
    }
}
int main()
{
    int i;
    printf("tell me which element of fibonacci series you want: \n ");
    scanf("%d", &i);
    printf("The %d element of fibonacci series is %d\n", i, fibRECURSIVE(i));
    return 0;
}

// fib_recursive(int n) :
// if (n == 2 || n == 1)
// return n
// else : return fib_recursive(n - 1) + fib_recursive(n - 2);
