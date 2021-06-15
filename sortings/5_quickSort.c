#include<stdlib.h>
#include<stdio.h>
void swap_elements(int a[], int x, int y)
{
    int temp = a[x];
    a[x] = a[y];
    a[y] = temp;
}
int Partition(int a[], int lb, int ub)
{
    int pivot = a[lb];
    int start = lb;
    int end = ub;

    while(start < end)
    {
        while(a[start] <= pivot)
        {
            start++;
        }
        while(a[end] > pivot)
        {
            end--;
        }
        if(start<end)
        {
            swap_elements(a, start, end);
        }
    }
    swap_elements(a, lb, end);
    return end;
}
void quickSort(int a[], int lb, int ub)
{
    if(lb<ub)
    {
        int loc = Partition(a, lb, ub);
        quickSort(a, lb, loc-1);
        quickSort(a, loc+1, ub);
    }
}
int main()
{
    int a[] = {7,6,10,5,9,2,1,15,7};
    quickSort(a,0,8);
    for(int i=0; i<9; i++)
    {
        printf("%d  ",a[i]);
    }
    return 0;
}