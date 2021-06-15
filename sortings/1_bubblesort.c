#include <stdlib.h>
#include <stdio.h>

int main()
{
    // int a[10] = {3, 5, 7, 2, 0, 10, 1, 4, 9, 8};
    int a[10] = {10,9,8,7,6,5,4,3,2,1};
    int i, j, temp;
    for (i = 0; i < 9; i++)
        for (j = 0; j < 10 - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    for (i = 0; i < 10; i++)
        printf("%d  ", a[i]);
    
    printf("\n");
    
    return 0;
}