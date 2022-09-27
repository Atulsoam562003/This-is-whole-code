#include <stdio.h>
#include <string.h>
struct stud_details
{
    int id;
    char name[36];
    int marks;
    char fav_char;
};/*Akash,Atul, Soam;*/

int main()
{
    struct stud_details Akash, Atul, S;
    Akash.id = 1; 
    Atul.id = 2;
    S.id = 3;
    Akash.marks = 10;
    Atul.marks = 9;
    S.marks = 5;
    Akash.fav_char = 'a';
    Atul.fav_char = 't';
    S.fav_char = 's';

    // Akash.name = "Akash";/*LINE NO 22,23 ,24 WILL THROW ERROR BECAUSE WE USE STRCPY TO ASSIGN STRING VALUES. */
    // Atul.name ="Atul";
    // Soam.name ="Soam";
    strcpy(Akash.name, "Akash Soam");
    strcpy(Atul.name, "Atul Soam");
    strcpy(S.name, "soam");

    printf("The id, marks, fav_char, full name of Akash is %d, %d, %c, %s\n", Akash.id, Akash.marks, Akash.fav_char, Akash.name);
    printf("The id, marks, fav_char, full name of Atul is %d, %d, %c, %s\n", Atul.id, Atul.marks, Atul.fav_char, Atul.name);
    printf("The id, marks, fav_char, full name of Soam is %d, %d, %c, %s\n", S.id, S.marks, S.fav_char, S.name);

    return 0;
}
