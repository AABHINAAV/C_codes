// implementation of stack using single queue and array
#include <stdlib.h>
#include <stdio.h>
#define N 5
int q[N];
int front = -1, rear = -1;

void enqueue(int data)
{
    if (front == -1 && rear == -1)
        front = rear = 0;
    else
        rear = (rear + 1) % N;
    q[rear] = data;
}

void pop()
{
    if (front == -1 && rear == -1)
        printf("\nstack is empty");
    else
    {
        if (front == rear)
            front = rear = -1;
        else
        {
            if(rear == 0)
                rear = N - 1;
            else 
                rear--;
        }
    }
}

void push()
{
    if ((rear + 1) % N == front)
        printf("\noverflow condition");
    else
    {
        int data;
        printf("enter the data : ");
        scanf("%d", &data);
        enqueue(data);
    }
}

void peek()
{
    if (front == -1 && rear == -1)
        printf("\nstack is empty");
    else
        printf("\nelement : %d", q[rear]);
}

void traverse()
{
    if (front == -1 && rear == -1)
        printf("\nstack is empty");
    else
    {
        int i = rear;
        while (i != front)
        {
            printf("\nelement : %d", q[i]);
            i--;
            if (i < 0)
                i = N - 1;
        }
        printf("\nelement : %d", q[i]);
    }
}

void getLength()
{
    printf("total : %d", rear - front + 1);
}

int main()
{
    int choice;
    while (1)
    {
        printf("\n\n---->MENU<----\n");
        printf("1.PUSH\n");
        printf("2.POP\n");
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
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            traverse();
            break;
        case 5:
            getLength();
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