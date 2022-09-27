#include <stdio.h>
// #include <stdlib.h>
int main()
{
    //     // you have to fill in the values to a template letter.txt
    //     letter.txt looks something like this :
    //     Thanks [[name]] for purchasing [[item]] from our [[outlet]]
    //     Please visit our outlet again for any kind of problems.
    //     We plan to serve you again soon.

    // you have to read this file and replace these values:
    // name== Akash
    // item==Table fan
    // outlet == ram hanuman fan outlet

    // use file functions in c to accomplish the same

    FILE *LetterPTR = NULL;
    char string[100], name[39], item[20], outlet[100]="Ram Hanuman fan outlet";
    // LetterPTR= fopen("Letter.txt", "r");
    // fscanf(LetterPTR, "%s", string );
    // printf("the content we got while reading the file before the first space is %s\n", string); 
   printf("Enter the name of customer:\n");
   gets(name);
   printf("Enter the item he purchased:\n");
   gets(item);
   
    
    LetterPTR = fopen("Letter.txt", "w");
    fprintf(LetterPTR, "Thanks %s for purchasing %s from %s . Please visit %s again for any kind of problems. We plan to serve you again soon.", name, item, outlet, outlet );

    return 0;
}
