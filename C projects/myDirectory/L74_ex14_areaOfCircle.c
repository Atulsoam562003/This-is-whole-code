#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define PI 3.14

float EucleadianDistance(int x1, int y1, int x2, int y2)
{
    int disSquare = (x1 - x2)*(x1 - x2)+(y1 - y2)*(y1 - y2);
    
    return sqrt(disSquare);
}

float areaOfCircle(int x1, int y1, int x2, int y2, float (*fptr)(int x1, int y1, int x2, int y2))
{
    return fptr( x1,  y1,  x2,  y2);
}
int main()
{
    // take x1, y1 and x2, y2 from the user using scanf
    // find the area of the circle
    int x1, x2, y1, y2;
    float dist;
    printf("Enter the value of first point:\n\n");
    printf("x1:\t");
    scanf("%d", &x1);
    printf("y1:\t");
    scanf("%d", &y1);
    printf("Enter the value of second point:\n\n");

    printf("x2:\t");
    scanf("%d", &x2);
    printf("y2:\t");
    scanf("%d", &y2);
    printf("acc to you the points are (%d,%d) and (%d,%d)\n\n", x1, y1, x2, y2);
    // int (*funcPtr)(int, int, int, int);
    // funcPtr =EucleadianDistance(x1, y1, x2, y2);
   dist = areaOfCircle(x1, y1, x2, y2, EucleadianDistance);
   printf("The distance between the points is %.3f\n", dist);
   printf("The area of the circle is %.3f\n\a", PI*dist);

    return 0;
}
