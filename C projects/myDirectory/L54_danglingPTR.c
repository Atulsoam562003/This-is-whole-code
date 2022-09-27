#include <stdio.h>
#include <stdlib.h>
int *funcDangling()
{
    int a, b, sum;
    sum = a + b;
    return &sum;
}
int main()
{ //case1: de-allocation of a memory block
    int *ptr = (int *)malloc(7 * sizeof(int));
    ptr[0] = 1;
    ptr[1] = 12;
    ptr[2] = 123;
    ptr[3] = 1234;
    free(ptr); //ptr is a dangling pointer now

    // case2: function returning local variable address
    int *dangPtr = funcDangling(); //since sum is a local variable to funcDangling,it will get destroyed in main function and hence dangPtr is now a dangling pointer

    // case3: if a variable goes out of scope
    int *danglingPtr3;
    {
        int a = 35;
        danglingPtr3 = &a;
    }
// from now onwards variable a gets out of scope and from nowonwards danglingPtr3 is a dangling pointer
    return 0;
}
