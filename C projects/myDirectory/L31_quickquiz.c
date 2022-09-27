#include <stdio.h>
void assignvalue(int *a, int *b)
{
    int originalA = *a;
    int originalB = *b;
    *a = originalA + originalB;
    *b = originalA - originalB;
    return;
}
int main()
{
    int i1, i2;
    printf("Enter the first no\n");
    scanf("%d", &i1);
    printf("Enter the second no\n");
    scanf("%d", &i2);
    assignvalue(&i1,&i2);
    printf("The new assigned values are %d and %d\n", i1,i2);

    return 0;
}
