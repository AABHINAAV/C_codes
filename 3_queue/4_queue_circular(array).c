// circular queue using linked list
// it is similar to circular linked list 
// one main property is :-
    // insertion is done only at end
    // deletion is done only at beginning
// it is also called linear queue using circular array
#include <stdio.h>
#include <stdlib.h>
#define N 5

void enqueue(int *front, int *rear, int *queue)
{
    if ((*rear + 1) % N == *front)
        printf("queue is full ..... overflow condition");
    else
    {
        int value;
        printf("enter the data : ");
        scanf("%d", &value);
        if (*front == -1 && *rear == -1)
            *front = *rear = 0;
        else
            *rear = (*rear + 1) % N;
        queue[*rear] = value;
    }
}

void dequeue(int *front, int *rear, int *queue)
{
    if (*front == -1 && *rear == -1)
        printf("queue is empty ..... underflow condition");
    else
    {
        if (*front == *rear)
            *front = *rear = -1;
        else
            *front = (*front + 1) % N;
    }
}

void peek(int *front, int *rear, int *queue)
{
    if (*front == -1 && *rear == -1)
        printf("queue is empty ..... overflow condition");
    else
        printf("peeking element is : %d\n", queue[*front]);
}

void traverse(int *front, int *rear, int *queue)
{
    if (*front == -1 && *rear == -1)
        printf("queue is empty .... underflow condition");
    else
    {
        int cur = *front;
        while (cur != *rear)
        {
            printf("element : %d\n", queue[cur]);
            cur = (cur + 1) % N;
        }
        printf("element : %d\n", queue[cur]);
    }
}

int main()
{
    int queue[N];
    int front, rear;
    front = rear = -1;

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
        // case 5:
        //     getLength(&front, &rear);
        //     break;
        case 6:
            exit(1);
            break;
        default:
            printf("invalid input...");
        }
    }
    return 0;
}