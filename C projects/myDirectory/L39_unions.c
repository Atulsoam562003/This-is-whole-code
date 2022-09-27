#include <stdio.h>
#include <string.h>
// struct student
// {
//     int id;
//     int marks;
//     char fav_char;
//     char name[30];
// };

union student
{
    int id;
    int marks;
    char fav_char;
    char name[30];
};


// int main()
// {
//     struct student s1;
//     s1.id = 1;
//     s1.marks = 100;
//     s1.fav_char = 'a';
//     strcpy(s1.name, "Akash Soam");
//     printf("The id is %d\n", s1.id);
//     printf("The marks is %d\n", s1.marks);
//     printf("The fav_char is %c\n", s1.fav_char);
//     printf("The name is %s\n", s1.name);
//     return 0;
// }
int main()
{
    union student s1;
    s1.id = 1;
    s1.marks = 100;
    s1.fav_char = 'a';
    strcpy(s1.name, "Akash Soam");
    printf("The id is %d\n", s1.id);
    printf("The name is %s\n", s1.name);
    printf("The fav_char is %c\n", s1.fav_char);
    printf("The marks is %d\n", s1.marks);
    return 0;
}

