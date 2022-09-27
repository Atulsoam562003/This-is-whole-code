#include <stdio.h>
int main()
{
    int i;
    double km, mile, inch, foot, cm, p, kg, m;
    printf("choose the type of conversion:\n");
    printf(" 1.kms to miles\n 2.inches to foot\n 3.cms to inches\n 4.pound to kgs\n 5.inches to meters\n");
    printf("ENTER 0 TO QUIT\n");
    scanf("%d", &i);
    {
        while (i != 0)

            goto AKASH;
    }

AKASH:
    switch (i)
    {
    case 1:
        printf("YOU CHOSE -kms to miles\n");
        printf("Enter the amount in km:     ");
        scanf("%lf", &km);
        mile = 1.61 * km;
        printf("%lf miles", mile);
        break;
    case 2:
        printf("YOU CHOSE -inches to foot\n");
        printf("Enter the amount in inches:     ");
        scanf("%lf", &inch);
        foot = 12 * inch;
        printf("%lf feet", foot);
        break;
    case 3:
        printf("YOU CHOSE -cms to inches\n");
        printf("Enter the amount in cm:     ");
        scanf("%lf", &cm);
        inch = 2.54 * cm;
        printf("%lf inches", inch);
        break;
    case 4:
        printf("YOU CHOSE -pound to kgs\n");
        printf("Enter the amount in pound:      ");
        scanf("%lf", &p);
        kg = p / 0.45;
        printf("%lf kgs", kg);
        break;
    case 5:
        printf("YOU CHOSE -inches to meters\n");
        printf("Enter the amount in inches:     ");
        scanf("%lf", &inch);
        m = inch / 0.025;
        printf("%lf meters", m);
        break;
    case 0:
        printf("THANKS\n");
        break;

    default:
        printf("OOPS! not an option \a \a \n");
        break;
    }
    return 0;
}
