#include <stdio.h>
int funcTOseeM1ofpassingARRAYS(int RANDOMarray[])
{
    for (int i = 0; i < 4; i++)
    {
        printf("The element at %d index of the array is %d\n", i, RANDOMarray[i]);
    }
    RANDOMarray[0] = 123456789; /* This shows that in method 1 of passing arrays in functions (by directly declaring array as a parameter in function , the change in any data of array in function gets reflected in main function  VERY IMPORTANT*/
    return 0;
}

int funcTOseeM2passingarrays(int *p)
{
    for (int i = 0; i < 4; i++)
    {
        printf("The element at %d index of the array is %d\n", i, p[i]);
        /*or we could have used :
        printf("The element at %d index of the array is %d\n", i, *(p +i));
        */
        p[2] = 123456789;
    }
}
void funcTOtryON2dARRAYS(int newARRAY[2][4])
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("The element at %d,%d index of the array is %d\n", i, j, newARRAY[i][j]);
        }
    }
    newARRAY[1][2] = 123456789;
}

int main()
{
    int arr[] = {10, 20, 30, 40};
    int arr_2d[2][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}};
    // printf("The value at index 0 of the array is %d\n", arr[0]);
    // funcTOseeM1ofpassingARRAYS(arr);
    // printf("The value at index 0 of the array is %d\n", arr[0]);
    // funcTOseeM2passingarrays(arr);
    funcTOtryON2dARRAYS(arr_2d);
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("The element at %d,%d index of the array is %d\n", i, j, arr_2d[i][j]);
        }
    }

    return 0;
}
