// implementation of stack using two queues and array
#include <stdlib.h>
#include <stdio.h>
#define N 5
int q1[N], q2[N];
int front1 = -1, rear1 = -1, front2 = -1, rear2 = -1;

void enqueue1(int data)
{
    if (front1 == -1 && rear1 == -1)
        front1 = rear1 = 0;
    else
        rear1++;
    q1[rear1] = data;
}

int dequeue1()
{
    int temp;
    temp = q1[front1];
    if (front1 == rear1)
        front1 = rear1 = -1;
    else
        front1++;
    return temp;
}

void enqueue2(int data)
{
    if (front2 == -1 && rear2 == -1)
        front2 = rear2 = 0;
    else
        rear2++;
    q2[rear2] = data;
}

int dequeue2()
{
    int temp;
    temp = q2[front2];
    if (front2 == rear2)
        front2 = rear2 = -1;
    else
        front2++;
    return temp;
}

void push()
{
    if (rear1 == N - 1)
        printf("\noverflow condition");
    else
    {
        int data;
        printf("enter the data : ");
        scanf("%d", &data);
        enqueue1(data);
    }
}

void pop()
{
    if (front1 == -1 && rear1 == -1)
        printf("\nunderflow condition");
    else
    {
        int i;
        for (i = front1; i < rear1; i++)
            enqueue2(dequeue1());
        dequeue1();
        for (i = front2; i <= rear2; i++)
            enqueue1(dequeue2());
    }
}

void peek()
{
    printf("element : %d", q1[rear1]);
}

void traverse()
{
    if (front1 == -1 && rear1 == -1)
        printf("stack is empty");
    else
    {
        int i;
        for (i = rear1; i >= front1; i--)
            printf("element : %d\n", q1[i]);
    }
}

void getLength()
{
    printf("total : %d", rear1 - front1 + 1);
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