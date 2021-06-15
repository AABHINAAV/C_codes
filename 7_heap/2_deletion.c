#include <stdlib.h>
#include <stdio.h>
void deletion(int heap[], int index)
{
    int temp = heap[index];
    heap[index] = '\0';
    int i=0;
    heap[0] = temp;

    while((temp<heap[2*i +1] || temp<heap[2*i +2]) && i<index-1)
    {
        int a = heap[2*i +1];
        int b = heap[2*i +2];
        if(a>b)
        {
            heap[i] = a;
            i = 2*i +1;
        }
        else
        {
            heap[i] = b;
            i = 2*i +2;
        }
    }
    heap[i] = temp;
}
int main()
{
    int heap[] = {50,20,30,10,12,15,10,8,7,1,3,7,9};
    int size = 12;

    deletion(heap, size);
    for (int i = 0; heap[i] != '\0'; i++)
    {
        printf("%d  ", heap[i]);
    }
    printf("\n");
}