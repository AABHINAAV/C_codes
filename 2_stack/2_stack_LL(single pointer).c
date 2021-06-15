// stack using ll using single pointer
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

struct node *push(struct node *top)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    printf("enter data : ");
    scanf("%d", &newNode->data);
    newNode->next = top;
    top = newNode;
    return top;
}

struct node *pop(struct node *top)
{
    if (top == NULL)
    {
        printf("underflow");
    }
    else
    {
        struct node *temp = top;
        printf("popped element : %d\n", temp->data);
        top = top->next;
        free(temp);
    }
    return top;
}

void peek(struct node *top)
{

    if (top == NULL)
    {
        printf("empty");
    }
    else
    {
        printf("top element : %d\n", top->data);
    }
}

void traverse(struct node *top)
{
    if (top == NULL)
    {
        printf("stack is empty");
    }
    else
    {
        while (top != NULL)
        {
            printf("element : %d\n", top->data);
            top = top->next;
        }
    }
}

void getLength(struct node *top)
{
    int count = 0;
    struct node *temp = top;
    if (top == NULL)
    {
        printf("stack is empty");
    }
    else
    {
        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        printf("total : %d\n", count);
    }
}

int main()
{
    struct node *top = NULL;
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
            top = push(top);
            break;
        case 2:
            top = pop(top);
            break;
        case 3:
            peek(top);
            break;
        case 4:
            traverse(top);
            break;
        case 5:
            getLength(top);
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
