#include <stdio.h>
int main()
{
    printf("Lets learn about pointers\n");
    int a = 5;
    int *pointerA = &a;
    printf("The value of a is %d\n", a);
    // instead of the above written line we could also write
    // printf("The value of a is %d\n", *pointerA);(this line can also be called as we are dereferencing our pointerA)
    // if we would have required the address of a we could have written the below written code:
    // printf("The address of a is %p\n", pointerA);
    // since the pointerA is also a variable so it is also occupying space in memory thus it must have an address also.So for address of pointerA we can write the below written code:
    printf("The address of pointer to a (here, pointerA) is %p\n", &pointerA);
    // for printing address of variable a we can write the following code":
    printf("The address of a is %p", &a);
    // for address in hexadecimal form we can use %x instead of %p
    return 0;
}
