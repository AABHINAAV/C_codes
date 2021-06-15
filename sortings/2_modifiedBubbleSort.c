#include<stdio.h>
#include<stdlib.h>
int main()
{
    int a[] = {3, 5, 7, 2, 0, 10, 1, 4, 9, 8};
    int i,j,n=10,temp,flag;

    for(i=0; i<n-1; i++)
    {
        flag = 0;
        for(j=0; j<n-i-1; j++)
        {
            if(a[j]>a[j+1])
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                flag = 1;
            }
        }
        if(flag == 0)
        {
            printf("rounds : %d", i);
            break;
        }
    }

    printf("\n");
    for(i=0; i<n; i++)
    {
        printf("%d  ", a[i]);
    }
    printf("\n");

    return 0;
}