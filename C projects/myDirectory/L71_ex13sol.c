#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char  *argv[])
{

    // you have to create a command line utility to add/subtract/divide/multiply two numbers. First command line argument of your c program must be the operation. The next two being the two numbers. For example:

    // command.c add 45 5
    // 50

    int num1, num2;
    char * operation;
    operation = (argv[1]);
    num1 = atoi(argv[2]);
    num2 = atoi(argv[3]);

    if (strcmp(operation, "add") == 0)
    {
        printf("%d\n", num1 + num2);
    }
    else if (strcmp(operation, "subtract") == 0)
    {
        printf("%d\n", num1 - num2);
    }
    else if (strcmp(operation, "multiply") == 0)
    {
        printf("%d\n", num1 * num2);
    }
    else if (strcmp(operation, "divide") == 0)
    {
        printf("%d\n", num1 / num2);
    }

    return 0;
}
