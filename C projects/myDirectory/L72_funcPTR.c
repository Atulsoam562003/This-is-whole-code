#include <stdio.h>
#include <stdlib.h>
int sum(int a, int b)
{
    return a + b;
}
void greet()
{
    printf("The function is written to check working of FUNCION POINTERS\n");
}
int main()
{
    printf("The sum of 3 and 6 is %d\n", sum(3, 6)); //written for testing the function.
    int (*funcPtr)(int, int);//declaring a function pointer  // this line of code means that the pointer funcPtr can point on a function which returns int value and takes two int as arguments.

    funcPtr = &sum;//alloting address to a function pointer
    int n = (*funcPtr)(10, 6);// dereferencing a function pointer
    printf("The value of n is %d\n", n);

    return 0;
}