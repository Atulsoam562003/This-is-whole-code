#include <stdio.h>
int main()
{
    typedef unsigned long ul;
    //   THE SYNTAX OF TYPEDEF KEYWORD IS
    // typedef <old_name> <alias_name>;
    ul l1, l2, l4;
    typedef int i;
    i a1 = 0, y = 56;
    printf("value of a1 is %d\n", a1);
    //   int *a,b;
    typedef int *intptr;
    intptr a, b;
    a = &y;
    b = &y;
    return 0;
}
