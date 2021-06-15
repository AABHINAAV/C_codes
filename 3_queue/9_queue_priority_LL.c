#include <stdio.h>
#include <stdlib.h>

typedef struct PriQue
{
    int data;
    int priority;
    struct PriQue *next;
} PQ;

PQ *makeNode(int val, int pri)
{
    PQ *newnode = (PQ *)malloc(sizeof(PQ));
    newnode->data = val;
    newnode->priority = pri;
    newnode->next = NULL;
    return newnode;
}

PQ *enqueue(PQ *head, int val, int pri)
{
    PQ *cur = head;
    PQ *newnode = makeNode(val, pri);

    if (cur == NULL)
        head = newnode;
    else if (cur->priority >= pri)
    {
        newnode->next = head;
        head = newnode;
    }
    else
    {
        while (cur && cur->next)
        {
            if (cur->priority <= pri && cur->next->priority >= pri)
                break;
            cur = cur->next;
        }
        PQ *nextlink = cur->next;
        cur->next = newnode;
        newnode->next = nextlink;
    }

    return head;
}

void traverse(PQ *head)
{
    while (head != NULL)
    {
        printf("element : %d\tpriority : %d\n", head->data, head->priority);
        head = head->next;
    }
}

void peek(PQ *head)
{
    printf("\npeeking element :-\nelement : %d\tpriority : %d\n\n\n", head->data, head->priority);
}

PQ *pop(PQ *head)
{
    PQ *temp = head;
    head = head->next;
    free(temp);
    return head;
}

int main()
{
    PQ *head = NULL;
    head = enqueue(head, 12, 4);
    head = enqueue(head, 10, 2);
    head = enqueue(head, 14, 2);
    head = enqueue(head, 16, 4);
    head = enqueue(head, 12, 3);
    traverse(head);
    peek(head);
    head = pop(head);
    traverse(head);
    peek(head);

    return 0;
}