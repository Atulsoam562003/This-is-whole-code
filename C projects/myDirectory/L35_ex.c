#include<stdio.h>
#include<string.h>
int main()
{
    char Str1[30];
    char Str2[30];
    char Str3[]=" is a friend of ";
    char Str4[100];
    printf("Please enter the first string\n");
    scanf("%s", &Str1);
    printf("Please enter the second string\n");
    scanf("%s",&Str2);
    strcat(Str1,Str3);
    strcat(Str1,Str2);
    strcpy(Str4,Str1);
    printf("%s",Str4);
    return 0;
}
