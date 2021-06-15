// double ended queue using circular array
#include <stdio.h>
#include <stdlib.h>
#define N 5

void enqueueRear(int *front, int *rear, int *queue)
{
    if ((*rear + 1) % N == *front)
        printf("queue is full ..... overflow condition");
    else
    {
        int value;
        printf("enter the data : ");
        scanf("%d", &value);

        if (*front == -1 && *rear == -1)
        {
            *front = *rear = 0;
        }
        else if (*rear == N - 1)
        {
            *rear = 0;
        }
        else
        {
            (*rear)++;
        }
        queue[*rear] = value;
    }
}

void enqueueFront(int *front, int *rear, int *queue)
{
    if ((*rear + 1) % N == *front) // (*front == 0 && *rear == N -1) || (*front == *rear + 1)
        printf("queue is full ..... overflow condition");
    else
    {
        int value;
        printf("enter the data : ");
        scanf("%d", &value);

        if (*front == -1 && *rear == -1)
        {
            *front = *rear = 0;
        }
        else if (*front == 0)
        {
            *front = N - 1;
        }
        else
        {
            (*front)--;
        }
        queue[*front] = value;
    }
}

void dequeueRear(int *front, int *rear, int *queue)
{
    if (*front == -1 && *rear == -1)
        printf("queue is empty ..... underflow condition");
    else
    {
        if (*front == *rear)
        {
            *front = *rear = -1;
        }
        else if (*rear == 0)
        {
            *rear = N - 1;
        }
        else
        {
            (*rear)--;
        }
    }
}

void dequeueFront(int *front, int *rear, int *queue)
{
    if (*front == -1 && *rear == -1)
        printf("queue is empty ..... underflow condition");
    else
    {
        if (*front == *rear)
        {
            *front = *rear = -1;
        }
        else if (*front == N - 1)
        {
            *front = 0;
        }
        else
        {
            (*front)++;
        }
    }
}

void traverseFwd(int front, int rear, int *queue)
{
    if (front == -1 && rear == -1)
        printf("queue is empty");
    else
    {
        int i = front;

        while (i != rear)
        {
            printf("\nelement : %d", queue[i]);
            i = (i + 1) % N;
        }
        printf("\nelement : %d", queue[i]);
    }
}

void traverseBkwd(int front, int rear, int *queue)
{
    if (front == -1 && rear == -1)
        printf("queue is empty");
    else
    {
        int i = rear;
        do
        {
            printf("\nelement : %d", queue[i]);
            i--;
            if (i < 0)
                i = N - 1;
        } while (i != front);
        printf("\nelement : %d", queue[i]);
    }
}

void getLength(int front, int rear)
{
    if (front == -1 && rear == -1)
        printf("queue is empty");
    else
    {
        int i = front;
        int count = 1;

        while (i != rear)
        {
            count++;
            i = (i + 1) % N;
        }
        printf("\ntotal : %d", count);
    }
}

void isEmpty(int front, int rear)
{
    if (front == -1 && rear == -1)
        printf("queue is empty");
    else
        printf("queue is not empty");
}

void isFull(int front, int rear)
{
    if ((rear + 1) % N == front)
        printf("queue is full");
    else
        printf("queue is full");
}

void getFront(int front, int rear, int *queue)
{
    if (front == -1 && rear == -1)
        printf("queue is empty");
    else
        printf("front element : %d", queue[front]);
}

void getRear(int front, int rear, int *queue)
{
    if (front == -1 && rear == -1)
        printf("queue is empty");
    else
        printf("front element : %d", queue[rear]);
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
        printf("1.Insert At End\n");
        printf("2.Insert At Beginning\n");
        printf("3.Delete At End\n");
        printf("4.Delete At Beginning\n");
        printf("5.Traverse Forward\n");
        printf("6.Traverse Backward\n");
        printf("7.Get Length\n");
        printf("8.Check If Empty Or Not\n");
        printf("9.Check If Full Or Not\n");
        printf("10.Get Front\n");
        printf("11.Get Rear\n");
        printf("12.Exit\n");
        printf("\n");
        printf("Enter the choice\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            enqueueRear(&front, &rear, queue);
            break;
        case 2:
            enqueueFront(&front, &rear, queue);
            break;
        case 3:
            dequeueRear(&front, &rear, queue);
            break;
        case 4:
            dequeueFront(&front, &rear, queue);
            break;
        case 5:
            traverseFwd(front, rear, queue);
            break;
        case 6:
            traverseBkwd(front, rear, queue);
            break;
        case 7:
            getLength(front, rear);
            break;
        case 8:
            isEmpty(front, rear);
            break;
        case 9:
            isFull(front, rear);
            break;
        case 10:
            getFront(front, rear, queue);
            break;
        case 11:
            getRear(front, rear, queue);
            break;
        case 12:
            exit(1);
            break;
        default:
            printf("invalid input...");
        }
    }
    return 0;
}