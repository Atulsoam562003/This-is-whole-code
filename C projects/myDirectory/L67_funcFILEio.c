#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *ptr = NULL;

    // ptr = fopen("myfile.txt", "r");
    // char c = fgetc(ptr);
    // printf("The character I read is %c\n", c);
    // c = fgetc(ptr);
    // printf("The character I read is %c\n", c);
    // c = fgetc(ptr);
    // printf("The character I read is %c\n", c);

    // char str[28];
    // fgets(str, 20, ptr);
    // printf("The fixed string which I read is %s\n", str);

    // ptr = fopen("myfile.txt", "w");
    // fputc('h', ptr);
    // //  char str[40];//these two lines will throw an error
    // //  const str ="this content is from lecture 67.c";
    // fputs(" this is produced by lec 67.c",ptr);

    //   ptr = fopen("myfile.txt", "r+");
    // fputc('h', ptr);
    // //  char str[40];//these two lines will throw an error
    // //  const str ="this content is from lecture 67.c";
    // fputs(" this is produced by lec 67.c",ptr);

    //  ptr = fopen("myfile.txt", "w+");
    //     fputc('h', ptr);
    //     //  char str[40];//these two lines will throw an error
    //     //  const str ="this content is from lecture 67.c";
    //     fputs(" this is produced by lec 67.c",ptr);

    ptr = fopen("myfile.txt", "a+");
    fputc('h', ptr);
    //  char str[40];//these two lines will throw an error
    //  const str ="this content is from lecture 67.c";
    fputs(" this is produced by lec 67.c", ptr);

    fclose(ptr);

    return 0;
}
