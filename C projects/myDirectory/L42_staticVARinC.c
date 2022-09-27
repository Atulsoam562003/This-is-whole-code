#include <stdio.h>
int func1(int i1)
{
    static int myvar = 0;
    printf("The value of myvar is %d\n", myvar);
    myvar++;
    return i1 + myvar;
}
int main()
{
    int b = 344;
    int val = func1(b);
    printf("\n");
    val = func1(b); /* In the result of this line the value in the val variable is not 0 again because a static variable preserves the value and is not initialised again*/
    val = func1(b); /* In the result of this line the value in the val variable is not 0 again because a static variable preserves the value and is not initialised again*/
    val = func1(b); /* In the result of this line the value in the val variable is not 0 again because a static variable preserves the value and is not initialised again*/
    val = func1(b); /* In the result of this line the value in the val variable is not 0 again because a static variable preserves the value and is not initialised again*/

    return 0;
}
