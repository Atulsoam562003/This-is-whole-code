#include <stdio.h>
void changevalue(int *a, int *b)
{
    *a = *b;
}
int main()
{
    int i = 1,j;
    printf("The value of i initially is %d\n", i);
    printf("Enter the value you want i to take\n");
    scanf("%d",&j);
    changevalue(&i,&j);
    printf("The value of i now is %d\n", i);

    return 0;
}
 /*
 QUICK QUIZ
 ask for two nos from user and make their new values as sum and difference between them
 {using call by reference}
 */