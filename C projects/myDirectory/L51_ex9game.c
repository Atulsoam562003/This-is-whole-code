#include <stdio.h>
#include <string.h>
#include <time.h>
// create rock, paper and scissors game
// Player1:rock
// Player2:(computer):scissors -->player1 gets one point
// write a c program to allow user to play this game three times with computer.lock the scores of the computer and the player.
// Display the name of the winner at the end
// (you have to display name of the player during the game. Take users name as an input from the user)

int generateRandomNumber(int n)
{
    srand(time(NULL)); //srand takes seed as an input and is defined in stdlib.h
    return rand() % n;
}

int main()
{
    int compscore = 0, yourscore = 0;
    char namestr[30];

    printf("WELCOME USER\n");
    printf("PLEASE ENTER YOUR NAME:\n");
    printf("\n");
    scanf("%s", namestr);
    printf("your name is %s\n", namestr);
    // printf("The random no between 0 to 2 is %d\n", generateRandomNumber(3));

    for (int rounds = 0; rounds < 3; rounds++)
    {
        printf("your turn.....\n");
        printf("\n");
        printf("press \n 0 for rock \n 1 for paper \n 2 for scissors\n");

        int i;
        scanf("%d", &i);
        switch (i)
        {
        case 0:
            printf("%s : ~~~ROCK\n", namestr);
            break;
        case 1:
            printf("%s : ~~~PAPER\n", namestr);
            break;
        case 2:
            printf("%s : ~~~SCISSORS\n", namestr);
            break;

        default:
            printf("NOT A VALID INPUT , you should enter 1/2/3\n");
            break;
        }

        int compno = generateRandomNumber(3);
        printf("Computer chose %d\n", compno);
        switch (generateRandomNumber(3))
        {
        case 0:
            printf("COMP: \t ~~~~~ROCK\n");
            break;
        case 1:
            printf("COMP: \t ~~~~~ PAPER\n");
            break;
        case 2:
            printf("COMP: \t ~~~~~ SCISSORS\n");
        }
        if (i == 0 && compno == 1)
        {
            printf("computer wins this round\n and computer score is %d\n", ++compscore);
        }
        else if (i == 0 && compno == 2)
        {
            printf("%s wins this round\n and %s's score is %d\n", namestr, namestr, ++yourscore);
        }
        else if (i == 0 && compno == 0)
        {
            printf("This is a draw\n");
        }
        else if (i == 1 && compno == 1)
        {
            printf("This is a draw\n");
        }
        else if (i == 1 && compno == 1)
        {
            printf("This is a draw\n");
        }
        else if (i == 1 && compno == 0)
        {
            printf("%s wins this round\n and %s's score is %d\n", namestr, namestr, ++yourscore);
        }
        else if (i == 1 && compno == 2)
        {
            printf("computer wins this round\n and computer score is %d\n", ++compscore);
        }
        else if (i == 2 && compno == 0)
        {
            printf("computer wins this round\n and computer score is %d\n", ++compscore);
        }
        else if (i == 2 && compno == 1)
        {
            printf("%s wins this round\n and %s's score is %d\n", namestr, namestr, ++yourscore);
        }
        printf("\n");
        printf("\n");
        printf("\n");
    }

    if (compscore == 3)
    {
        printf("COMP WINS \n\n score of %s is %d\n and the score of computer is %d\n", namestr, yourscore, compscore);
    }
    else if (yourscore == 3)
    {
        printf("%s  WINS \n\n score of %s is %d\n and the score of computer is %d\n", namestr, namestr, yourscore, compscore);
    }

    return 0;
}
