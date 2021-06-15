#include <stdlib.h>
#include <stdio.h>
void insertNode(int heap[], int data, int i)
{
    while (heap[(i - 1) / 2] < data && i != 0)
    {
        heap[i] = heap[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    heap[i] = data;
}
int main()
{
    int heap[100] = {20, 11, 15, 10, 8, 12};
    int size = 5;
    //       20
    //   11      15
    // 10  8   12
    // insertNode(heap, 16, 6);

    size++;
    insertNode(heap, 21, size);
    //       21
    //   11      20
    // 10  8   12  15
    for (int i = 0; heap[i] != '\0'; i++)
    {
        printf("%d  ", heap[i]);
    }
    printf("\n");
}