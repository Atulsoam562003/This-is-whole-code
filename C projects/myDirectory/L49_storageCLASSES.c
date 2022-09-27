#include <stdio.h>
int sum;
int myfunc(int a, int b)
{
    // int sum;
    sum = a + b;
    return sum;
}
int main()
{
    myfunc(3, 5);
    printf("The sum is %d\n", sum);
    return 0;
}
