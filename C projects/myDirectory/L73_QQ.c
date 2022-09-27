#include <stdio.h>
int average(int a, int b)
{
    return (a + b) / 2;
}
void greetGeAndExecute(int (*fptr)(int, int))
{
    printf("Good Evening User\n");
    printf("The average of 2 and 76 is % d\n", fptr(2,76));
}
int main()
{
    int (*functionptr)(int, int);
    functionptr = average;
    greetGeAndExecute(functionptr);
    return 0;
}