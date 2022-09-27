#include <stdio.h>
void main()
{
    int stdmarks[5], sum, avg;
    printf("Enter the marks of each student:\n");
    for (int i = 0; i < 5; i++)
    {
        printf("The marks of student no %d is   :", i + 1);
        scanf("%d", &stdmarks[i]);
        sum += stdmarks[i];
    }
    avg = sum / 5;
    printf("The sum of the marks of the students is %d\n", sum);
    printf("The avg of the marks of the students is %d\n", avg);

}
