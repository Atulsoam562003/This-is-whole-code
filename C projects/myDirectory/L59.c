#include <stdio.h>
// #include "L51_ex9.c"
#define PI 3.14
#define square(num) num*num



int main()
{
    float var = PI;
    printf("The value of PI is %f\n", var);
    printf("tell me the radius of the circle\n");
    int r;
    scanf("%d",&r);
    printf("The area of this circle is %f\n", square(r)*PI);

    return 0;
}
