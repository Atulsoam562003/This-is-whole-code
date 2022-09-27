#include <stdio.h>
#include <string.h>
// make a parser
/*
input-
<span> This is a text which needs to be parsed </span>

output-
This is a text which needs to be parsed
*/
void parser(char *string)
{
    int in = 0; //variable to track whether we are inside the tag
    int index = 0;
    for (int i = 0; i < strlen(string); i++)
    {
        if (string[i] == '<')
        {
            in = 1;
            continue;
        }
        else if (string[i] == '>')
        {
            in = 0;
            continue;
        }
        if (in == 0)
        {
            string[index] = string[i];
            index++;
        }
        string[index] = '\0';
    }
    while (string[0] == ' ') // removing trailing spaces also
    {
        for (size_t i = 0; i < strlen(string); i++)
        {
            string[i] = string[i + 1];
        }
        // shift the string to the right
    }
    while (string[strlen(string) - 1] == ' ') //last character jav tak space h tab tak usse null character bana te jao. subscript index 0 matlab string ka first character and -1 isslite kia h for last character.
    {
        string[strlen(string) - 1] == '\0 ';
    }
}

int main()
{
    char string[] = " <a>         this is a heading   </a576>";
    parser(string);

    printf("The parsed string is ~~%s~~ ", string);

    return 0;
}
