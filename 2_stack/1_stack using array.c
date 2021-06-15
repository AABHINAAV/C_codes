// stack using array
#include <stdio.h>
#include <stdlib.h>
#define max 100
void push(int *top, int *stk);
void pop(int *top, int *stk);
void peek(int *top, int *stk);
void traverse(int *top, int *stk);
void getLength(int *top);
int main()
{
    int stk[max];
    int top = -1;
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
            push(&top, stk);
            break;
        case 2:
            pop(&top, stk);
            break;
        case 3:
            peek(&top, stk);
            break;
        case 4:
            traverse(&top, stk);
            break;
        case 5:
            getLength(&top);
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

void push(int *top, int *stk)
{
    int val;
    printf("enter data : ");
    scanf("%d", &val);
    if (*top == (max - 1))
    {
        printf("overflow");
    }
    else
    {
        (*top)++;
        stk[*top] = val;
    }
}

void pop(int *top, int *stk)
{
    if (*top == -1)
    {
        printf("underflow");
    }
    else
    {
        printf("popped element : %d", stk[*top]);
        (*top)--;
    }
}

void peek(int *top, int *stk)
{
    if (*top == -1)
    {
        printf("empty");
    }
    else
    {
        printf("top element : %d", stk[*top]);
    }
}

void traverse(int *top, int *stk)
{
    if (*top == -1)
    {
        printf("stack is empty");
    }
    else
    {
        int i;
        for (i = *top; i >= 0; i--)
        {
            printf("element : %d\n", stk[i]);
        }
    }
}
void getLength(int *top)
{
    printf("total : %d", *top + 1);
}