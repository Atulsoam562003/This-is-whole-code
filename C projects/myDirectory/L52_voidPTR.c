#include<stdio.h>
#include<string.h>
int main()
{int a=43;
float b=8.765;
void *ptr;
ptr=&a;
printf("The value of a is %d\n", *((int*)ptr)    );//we could only dereference void pointer after typecasting
 ptr=&b;   
printf("The value of a is %f\n", *((float*)ptr)    );
    return 0;
}
