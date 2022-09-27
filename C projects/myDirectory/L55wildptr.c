#include<stdio.h>
#include<stdlib.h> 
int main()
{int a=545;
int*ptr;
// above written pointer is a wild pointer
// *ptr=234; this is not a good thing to do . by this statement we are allowing compiler to store 234 as a value at the garbage address which is randomly selected by the ptr pointer
ptr=&a;
// now pointer is a not a wild pointer
printf("The value of a is %d\n", *ptr);

    
    return 0;
}
