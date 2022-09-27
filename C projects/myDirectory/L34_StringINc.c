#include <stdio.h>
#include <string.h>
void printstr(char s[])
{
  int i = 0;
  while (s[i] != '\0')
  {
    printf("%c", s[i]);
    i++;
  }
}

int main()
{
  // char String[]={'A','k','a','s','h','\0'};
  // char String[]="Akash";
  printf("Please enter a String\n");
  char String[50];
  gets(String);
  printstr(String);
  printf("This is using printf--> %s", String);
  return 0;
}
