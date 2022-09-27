#include <stdlib.h>
#include <stdio.h>
#include <time.h>
void main()
{
    int number, guess, nguesses = 1;
    srand(time(0));
    number = rand() % 100 + 1; // it will generate number between 1 to 100
    // printf("the number is %d\n", number);
    // keep running the loop until the number is guessed
    do
    {
        printf("guess the number between 1 to 100\n");
        scanf("%d", &guess);
        if (guess > number)
        {
            printf("Lower number please\n");
        }
        else if (guess < number)
        {
            printf("Heigher number please\n");
        }
        else
        {
            printf("You gussed it in %d attempts\n", nguesses);
        }
getchar();
        nguesses++;
    } while (guess != number);
}