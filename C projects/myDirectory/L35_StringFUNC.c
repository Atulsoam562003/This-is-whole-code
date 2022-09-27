#include <stdio.h>
#include <string.h>
int main()
{
  char characterARRAY1[] = "Akash";
  char characterARRAY2[] = "Soam";
  char s3[30];

  printf("The length of the string1 is %d\n", strlen(characterARRAY1));
  // puts(strlen(characterARRAY1));/*this line of code is wrong because puts is used to print STRING not integer.
  puts(strrev(characterARRAY1)); /* this code will change the value of string1 fo the system also, you can verify it when the line of code written below and in line 11 will run*/
  printf("The system has reversed the value of string1 for the system also, SEE , new string1 is %s\n", characterARRAY1);
  printf("The reverse of string1 again is %s\n", strrev(characterARRAY1));
 // puts(strcat(characterARRAY1, characterARRAY2));

  // char s3=strcat(characterARRAY1, characterARRAY2);/*This line will show an error as s3 cannot be declared like this because s3 is still a character array and is not made a string yet. Thus we have to write the following code:*/
  strcpy(s3, strcat(characterARRAY1, characterARRAY2));
  printf("copied value at string s3 now is %s\n",s3);
 int i= strcmp(characterARRAY1,characterARRAY2);
 printf("the difference between string1 and string2 by strcmp func is %d\n", i);

  return 0;
}
/*allow user to enter two strings and concatinate them saying that 
-str1 is a friend of str2 */
