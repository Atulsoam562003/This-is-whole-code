#include <stdio.h>
void main()
{
    int numbers[10];
    int odd = 0, even = 0;
    printf("Enter the values of the array~~~~~~~~~~~\n");
    for (int i = 0; i < 10; i++)
    {
        printf("The number at index %d of the array is:\t", i);
        scanf("%d", &numbers[i]);

        if (numbers[i] % 2 == 0)
        {
            even++;
        }
        else
            odd++;
    }
    printf("The total no of ODD integers is %d\n", odd);
    printf("The total no of EVEN integers is %d\n", even);
}