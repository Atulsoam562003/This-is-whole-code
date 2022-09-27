#include <stdio.h>
// void sum(); // this is function declaration

// void sum() // func definition
//     int a, b, sum;
//     printf("Enter two numbers\n");
//     scanf("%d\n %d\n", &a,&b);
// {
//     sum= a+b;
//     printf("The sum of the two numbers is %d\n", sum);
// }
// void main()
// {
//     sum(); //func calling
// }

char fun(){
    char c;
    printf("enter a character\n");
    scanf("%c", &c);
    
    return c;
}

void main()
{
    char ch;
    ch= fun();
    printf("character is %c\n", ch);
}