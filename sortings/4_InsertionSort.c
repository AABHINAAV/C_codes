/*
best case --> O(n)
worst and average case --> O(n^2)
insertion sort is stable(ordering of non-distinct elements remains the same)
insertion sort is in place(it does not takes extra space like heap sort)
it is also called online sort algorithm(online algo means it does not waits for all elements just like selection or bubble
instead it starts sorting as soon as a single elements is inserted)
*/
#include <stdlib.h>
#include <stdio.h>
void insertionSort(int a[])
{
    int temp;
    for (int i = 1; i < 10; i++)
    {
        temp = a[i];
        int j = i - 1;
        while (j >= 0 && temp < a[j])
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = temp;
    }
}
int main()
{
    int a[10] = {3, 5, 7, 2, 0, 10, 1, 4, 9, 8};
    insertionSort(a);
    for (int i = 0; i < 10; i++)
        printf("%d  ", a[i]);
    printf("\n");
    return 0;
}