#include <stdio.h>
#include <stdlib.h>

int main()
{
    // int a[10] = {3, 5, 7, 2, 0, 10, 1, 4, 9, 8};
    int a[6] = {20,13, 52, 95, 26, 38};
    int i, j, pos, min;
    for (i = 0; i < 6; i++)
    {
        pos = i;
        min = a[i];
        for (j = i; j < 6; j++)
        {
            if (a[j] < min)
            {
                pos = j;
                min = a[j];
            }
        }
        if (a[i] != min)
        {
            a[pos] = a[i];
            a[i] = min;
        }
        printf("iteration %d : ", i+1);
        for (int k = 0; k < 6; k++)
            printf("%d\t", a[k]);
        printf("\n");
    }
    // for (i = 0; i < 10; i++)
    //     printf("%d\n", a[i]);

    return 0;
}