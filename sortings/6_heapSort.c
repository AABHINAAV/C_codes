#include <stdio.h>
#include <stdlib.h>
void insertion(int heap[], int data, int i)
{
    if (i == 0)
    {
        heap[0] = data;
        return;
    }
    while (heap[(i - 1) / 2] < data && i != 0)
    {
        heap[i] = heap[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    heap[i] = data;
}
void deletion(int heap[], int A[], int index)
{
    A[index] = heap[0];
    int temp = heap[index];
    heap[index] = '\0';
    heap[0] = temp;
    int i = 0;

    while ((temp < heap[2 * i + 1] || temp < heap[2 * i + 2]) && i < index - 1)
    {
        int a = heap[2 * i + 1];
        int b = heap[2 * i + 2];
        if (a > b)
        {
            heap[i] = a;
            i = 2 * i + 1;
        }
        else
        {
            heap[i] = b;
            i = 2 * i + 2;
        }
    }
    heap[i] = temp;
}
int main()
{
    printf("unsorted array :-\n");
    int a[] = {80, 11, 25, 79, 8, 32, 41};
    for (int i = 0; i < 7; i++)
    {
        printf("%d  ", a[i]);
    }
    printf("\n\n");

    int heap[100];
    for (int i = 0; i < 7; i++)
    {
        insertion(heap, a[i], i);
    }

    printf("heap :-\n");
    for (int i = 0; heap[i] != '\0'; i++)
    {
        printf("%d  ", heap[i]);
    }
    printf("\n\n");

    int i = 6;
    int A[7];
    while (i >= 0)
    {
        deletion(heap, A, i);
        i--;
    }

    printf("sorted array :-\n");
    for (int i = 0; i < 7; i++)
    {
        printf("%d  ", A[i]);
    }
    printf("\n");
}