//queue using array
#include <stdlib.h>
#include <stdio.h>
#define N 5

void enqueue(int *front, int *rear, int *queue)
{
    int val;
    printf("enter data : ");
    scanf("%d", &val);
    if (*rear == N - 1)
    {
        printf("overflow");
    }
    else if (*front == -1 && *rear == -1)
    {
        *front = *rear = 0;
        queue[*rear] = val;
    }
    else
    {
        (*rear)++;
        queue[*rear] = val;
    }
}

void dequeue(int *front, int *rear, int *queue)
{
    if (*front == -1 && *rear == -1)
    {
        printf("queue is empty");
    }
    else if (*front == *rear)
    {
        *front = *rear = -1;
    }
    else
    {
        printf("dequeud value : %d", queue[*front]);
        (*front)++;
    }
}

void peek(int *front, int *rear, int *queue)
{
    if (*front == -1 && *rear == -1)
    {
        printf("queue is empty");
    }
    else
    {
        printf("element : %d", queue[*front]);
    }
}

void traverse(int *front, int *rear, int *queue)
{
    if (*front == -1 && *rear == -1)
    {
        printf("queue is empty");
    }
    else
    {
        int i;
        for (i = *front; i <= *rear; i++)
        {
            printf("element : %d\n", queue[i]);
        }
    }
}

void getLength(int *front, int *rear)
{
    if (*front == -1 && *rear == -1)
    {
        printf("queue is empty");
    }
    else
    {
        printf("total : %d", *rear - *front + 1);
    }
}

int main()
{
    int queue[N];
    int front = -1;
    int rear = -1;
    int choice;

    while (1)
    {
        printf("\n\n---->MENU<----\n");
        printf("1.Insert\n");
        printf("2.Delete\n");
        printf("3.Peek\n");
        printf("4.Traverse\n");
        printf("5.Get Length\n");
        printf("6.Exit\n");
        printf("\n");
        printf("Enter the choice\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            enqueue(&front, &rear, queue);
            break;
        case 2:
            dequeue(&front, &rear, queue);
            break;
        case 3:
            peek(&front, &rear, queue);
            break;
        case 4:
            traverse(&front, &rear, queue);
            break;
        case 5:
            getLength(&front, &rear);
            break;
        case 6:
            exit(1);
            break;
        default:
            printf("invalid input...");
        }
    }
    return 0;
}