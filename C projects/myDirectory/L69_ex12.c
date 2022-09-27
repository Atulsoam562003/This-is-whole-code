#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *replaceWord(const char *str, const char *oldword, const char *newword)
{
    char *resultstring;
    int i, count = 0;
    int newWordlength = strlen(newword);
    int oldWordlength = strlen(oldword);

    // Lets count the number of times old word comes in the string
    for (i = 0; str[i] != '\0'; i++)
    {
        if (strstr(&str[i], oldword) == &str[i])
        {
            count++;

            // jump over this word
            i = i + oldWordlength - 1;
        }
    }
    // making a new string to fit in the replaced words
    resultstring = (char *)malloc(i + count * (newWordlength - oldWordlength) + 1);

    i = 0;
    while (*str)
    {
        // compare the substring with the result
        if (strstr(str, oldword) == str)
        {
            strcpy(&resultstring[i], newword);
            i += newWordlength;
            str += oldWordlength;
        }
        else
        {
            resultstring[i] = *str;
            i += 1;
            str += 1;
        }
    }
    resultstring[i] = '\0';
    return resultstring;
}

int main()
{
    FILE *ptr = NULL;
    ptr = fopen("bill.txt", "r");
    FILE *ptr2 = NULL;
    ptr2 = fopen("genbill.txt", "w");

    char str [200];
    fgets(str, 200, ptr);
    printf("The given bill template was ~~~~~~~~~ %s\n", str);

    // call the replaceword function and print the new str

    char *newstr;
    newstr = replaceWord(str, "{{name}}", "Akash");
    newstr = replaceWord(newstr, "{{item}}", "Table fan");
    newstr = replaceWord(newstr, "{{outlet}}", "Ram Hanuman fan outlet");

    printf("The bill template after calling the replace function is ~~~~~%s\n", newstr);
    fprintf(ptr2, "%s", newstr);
    fclose(ptr);
    fclose(ptr2);

    return 0;
}
