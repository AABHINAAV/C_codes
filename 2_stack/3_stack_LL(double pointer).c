// stack using ll using double pointer
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void traverse(struct node **top)
{
    if (*top == NULL)
        printf("stack is empty");
    else
    {
        struct node *cur = *top;
        while (cur != NULL)
        {
            printf("\nelement : %d", cur->data);
            cur = cur->next;
        }
    }
}

void push(struct node **top)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    printf("enter the data : ");
    scanf("%d", &newnode->data);
    newnode->next = *top;
    *top = newnode;
}

void pop(struct node **top)
{
    if (*top == NULL)
        printf("stack is empty");
    else
    {
        struct node *temp = *top;
        *top = (*top)->next;
        free(temp);
    }
}

void peek(struct node **top)
{
    if (*top == NULL)
        printf("stack is empty");
    else
    {
        printf("top element is : %d", (*top)->data);
    }
}

void getLength(struct node **top)
{
    if (*top == NULL)
        printf("stack is empty");
    else
    {
        int count = 0;
        struct node *cur = *top;
        while (cur != NULL)
        {
            count++;
            cur = cur->next;
        }
        printf("total : %d", count);
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
            push(&top);
            break;
        case 2:
            pop(&top);
            break;
        case 3:
            peek(&top);
            break;
        case 4:
            traverse(&top);
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