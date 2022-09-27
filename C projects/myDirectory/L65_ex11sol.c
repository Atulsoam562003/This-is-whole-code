#include <stdio.h>
#include <stdlib.h>

// program to check whether a number is palindrome or not
int isPalindrome(int num)
{
    int reversed = 0;
    int originalnumber=num;
    // lets reverse the no.
    while (num != 0)
    {
        reversed = reversed * 10 + num % 10;
        num = num / 10;
    }
    printf("The reversed number is %d\n", reversed);
    if (originalnumber== reversed)
    {
        return 1;
    }
    else
        return 0;
}
int main()
{
    int number;
    printf("Enter a no to check whether a no is palindrome or not\n");
    scanf("%d", &number);
    //your task is to implement this function
    if (isPalindrome(number))
    {
        printf("This number is a palindrome\n");
    }
    else
    {
        printf("This number is NOT a palindrome\n");
    }

    return 0;
}
