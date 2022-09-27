#include <stdio.h>
//  #include<stdlib.h>
int main()
{
    FILE *ptr = NULL;
    char string[100]="This content was produced by writing a code in lecture 64.c";

    
    // ptr = fopen("myfile.txt", "r");
    // fscanf(ptr, "%s", string);
    // printf("The content of this file before first space is %s\n", string);



//************Writing a file************
 ptr = fopen("myfile.txt", "a");
    
    fprintf(ptr, "%s", string);
    return 0;
}
