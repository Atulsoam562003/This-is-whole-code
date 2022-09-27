/*You manage a travel agency and you want your n=3 drivers to input their following detail:
1.Name
2. Driving license no
3.Route
4. Kms
Your program should be able to take n=3 as input and your drivers will start inputting their details one by one.

Your program should be able to print details of the drivers in a suitable fashion.
USE STRUCTURES
*/
#include <stdio.h>
#include <string.h>

typedef struct DRIVERdetails
{
    char name[30];
    int dno;
    char route[100];
    int kms;
} SD;

int main()
{
    SD d1, d2, d3;
    char named1[30], named2[30], named3[30];
    char route1[100], route2[100], route3[100];
    printf("DRIVER NO 1 PLEASE INPUT YOUR DETAILS:\n");
    printf("YOUR FIRST NAME:\n");
    // gets(d1.name);
    scanf("%s", d1.name); //scanf will create problems while taking spaces in the string
    printf("YOUR DRIVING LICENSE NO:\n");
    scanf("%d", &d1.dno);
    printf("ROUTE THROUGH WHICH YOU'LL TRAVEL:\n");
    // gets(d1.route);
    scanf("%s", &d1.route); //scanf will create problems while taking spaces in the string
    printf("no of kilometers you have driven this vehicle:\n");
    scanf("%d", &d1.kms);

    printf("THANKS FOR ENTERING THE DETAILS\n");
    printf("\n");

    strcpy(named1, d1.name);
    strcpy(route1, d1.route);
    printf("The name of the driver is %s\n", named1);
    // printf("The name of the driver is %s\n", d1.name);
    printf("The DLno of the driver is %d\n", d1.dno);
    printf("The route to be travelled by the driver is %s\n", route1);
    printf("The no of kilometers travelled by the driver is %d\n", d1.kms);

    printf("\n");
    printf("\n");
    printf("DRIVER NO 2 PLEASE INPUT YOUR DETAILS:\n");
    printf("YOUR FIRST NAME:\n");
    // gets(d2.name);
    scanf("%s", d2.name); //scanf will create problems while taking spaces in the string
    printf("YOUR DRIVING LICENSE NO:\n");
    scanf("%d", &d2.dno);
    printf("ROUTE THROUGH WHICH YOU'LL TRAVEL:\n");
    // gets(d1.route);
    scanf("%s", &d2.route); //scanf will create problems while taking spaces in the string
    printf("no of kilometers you have driven this vehicle:\n");
    scanf("%d", &d2.kms);

    printf("THANKS FOR ENTERING THE DETAILS\n");
    printf("\n");

    strcpy(named2, d2.name);
    strcpy(route2, d2.route);
    printf("The name of the driver is %s\n", named2);
    // printf("The name of the driver is %s\n", d2.name);
    printf("The DLno of the driver is %d\n", d2.dno);
    printf("The route to be travelled by the driver is %s\n", route2);
    printf("The no of kilometers travelled by the driver is %d\n", d2.kms);

    printf("\n");
    printf("\n");
    printf("DRIVER NO 3 PLEASE INPUT YOUR DETAILS:\n");
    printf("YOUR FIRST NAME:\n");
    // gets(d1.name);
    scanf("%s", d3.name); //scanf will create problems while tak3ng spaces in the string
    printf("YOUR DRIVING LICENSE NO:\n");
    scanf("%d", &d3.dno);
    printf("ROUTE THROUGH WHICH YOU'LL TRAVEL:\n");
    // gets(d1.route);
    scanf("%s", &d3.route); //scanf will create problems while taking spaces in the string
    printf("no of kilometers you have driven this vehicle:\n");
    scanf("%d", &d3.kms);

    printf("THANKS FOR ENTERING THE DETAILS\n");
    printf("\n");

    strcpy(named3, d3.name);
    strcpy(route3, d3.route);
    printf("The name of the driver is %s\n", named3);
    // printf("The name of the driver is %s\n", d3.name);
    printf("The DLno of the driver is %d\n", d3.dno);
    printf("The route to be travelled by the driver is %s\n", route3);
    printf("The no of kilometers travelled by the driver is %d\n", d3.kms);

    return 0;
}
