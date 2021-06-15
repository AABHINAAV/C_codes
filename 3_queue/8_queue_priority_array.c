#include<stdio.h>
#include<stdlib.h>

typedef struct priori_q
{
    int val;
    int pri;
}priori_q;

void push(priori_q pq[], int val, int pri, int size, int *end)
{
    if(*end == size-1)
    {
        printf("overflow condition\n");
        return;
    }
    pq[(*end)].val = val;
    pq[(*end)].pri = pri;
    (*end)++;
}

void pop(priori_q pq[], int *end)
{
    int max_index = 0;
    int max_val = pq[max_index].val;

    for(int i=1; i<(*end); i++)
    {
        if(pq[max_index].pri < pq[i].pri)
        {
            max_index = i;
            max_val = pq[i].val;
        }
    }

    for(int i=max_index; i<(*end); i++)
    {
        pq[i].val = pq[i+1].val;
        pq[i].pri = pq[i+1].pri;
    }
    (*end)--;
}

void peek(priori_q pq[], int index)
{
    int max_index = 0;
    int max_val = pq[max_index].val;

    for(int i=1; i<index; i++)
    {
        if(pq[max_index].pri < pq[i].pri)
        {
            max_index = i;
            max_val = pq[i].val;
        }
    }

    printf("\npeeking index :: %d", max_index);
    printf("\npeeking value :: %d", max_val);
    printf("\npeeking priority :: %d\n", pq[max_index].pri);
}

void traverse(priori_q pq[], int index)
{
    for(int i=0; i<index; i++)
    {
        printf("%d : %d\n",pq[i].pri,pq[i].val);
    }
}

int main()
{
    int size = 100;
    int end = 0;
    priori_q pq[size];
    push(pq, 12, 4, size, &end);
    push(pq, 10, 2, size, &end);
    push(pq, 14, 2, size, &end);
    push(pq, 16, 4, size, &end);
    push(pq, 18, 5, size, &end);
    push(pq, 12, 3, size, &end);
    traverse(pq, end);
    peek(pq, end);
    pop(pq, &end);
    peek(pq, end);
    traverse(pq, end);

    return 0;
}