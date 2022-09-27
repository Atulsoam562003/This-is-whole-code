#include <stdio.h>
#include <stdlib.h>

// Dynamic memory allocation
// ABC Pvt ltd. manages employee records of other companies
// employee id can be of any length and it can contain any character
// for three employees,you have to take length of employee id as an input in an int length ,then you have to take employee id as an input and display it on the screen
// store the employee id in a character array which is allocated dynamically
// you are allowed to create only one character array dynamically

// employee 1:
// Enter no of characters in your eId
// 64
// dynamically allocate the character array.
// then, take input from the user.

// employee 2:
// Enter no of characters in your eId
//
// dynamically allocate the character array.
// then, take input from the user.

// employee 3:
// Enter no of characters in your eId
// 40
// dynamically allocate the character array.
// then, take input from the user.
int main()
{
    int i = 1;
    char a, b;
    char *ptr;
    while (i <= 3)
    {
        int length;
        printf("Welcome employee no %d\n", i);
        printf("Enter the no of digits in your employee id\n");
        scanf("%d", &length);
        getchar();
        printf("Enter the value of a \n");
        scanf("%c", &a);
        getchar();
        printf("Enter the value of b \n");
        scanf("%c", &b);
        ptr = (char *)malloc((length + 1) * sizeof(char));
        printf("Enter your EMPid:\n");
        scanf("%s", ptr);
        printf("Your id is %s\n", ptr);
        i++;
        free(ptr);
    }

    return 0;
}
