#include <stdio.h>

int sum(int a, int b)
{
    return a + b;
}
int subtract(int a, int b)
{
    return a - b;
}
// creating callback functions
// implies passing a function in another function's arguments using function pointers concept
void greetHelloAndExecute(int (*funcptr)(int, int)) //in the argument of this function you can see it demands a function pointer. so in main function we have to give arguments of any function pointers.
{
    printf("Hello User\n");
    printf("The sum of 4 and 5 is %d\n", funcptr(4, 5));
}

void greetGmAndExecute(int (*fptr)(int, int))
{
    printf("Good Morning User\n");
    printf("The value of 6-2 is %d\n", fptr(6, 2));
}
int main()
{
    // declaring a function pointer
    int (*functionPtr)(int, int);
    int (*functionPtr2)(int, int);
    functionPtr = sum;
    functionPtr2 = subtract;

    greetHelloAndExecute(functionPtr);
    greetGmAndExecute(functionPtr2);

    return 0;
}
