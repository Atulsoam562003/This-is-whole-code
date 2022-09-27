#include <stdio.h>

int main()
{
    int a = 45;
    // int *p = &a;
    int *p = NULL;
    if (p != NULL)
    {
        printf("The address alloted to the pointer is %d\n", p);
    }
    else
    {
        printf("The pointer is a null pointer and it cannot be dereferenced\n");
    }

    return 0;
}
