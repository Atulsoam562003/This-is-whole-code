#include <stdio.h>
int sum(int a, int b, int d) /*this line is declaring the sum[also this is a with argument and with return value type function]*/
{
    return a + b + d; //this line is defining the sum
}
// [now a with argument and without return value type function]
void printstar(int n)
{
    for (int i = 0; i < n; i++)

        printf("%c", '*');
}
// [now a without argument and with return value type function]
int takenumber()
{
    int num;
    printf("Enter a number:");
    scanf("%d", &num);
    return num;
}
int main()
{
    int a, b, c, d, s, e;
    a = 5;
    b = 7;
    d = 8;
    // c = sum(a, b, d); //this line is calling the function
    // printf("The sum is %d\n", c);
    // printf("Enter the number of stars you want\n");
    // scanf("%d", &s);
    // printstar(s);
    e = takenumber();
    printf("The number is %d \n", e);

    return 0;
}
