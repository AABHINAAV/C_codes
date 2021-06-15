#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void enqueue(struct node **head)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    printf("enter the data : ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;

    if (*head == NULL)
        *head = newnode;
    else
    {
        struct node *cur = *head;
        while (cur->next != NULL)
            cur = cur->next;
        cur->next = newnode;
    }
}

struct node *dequeue(struct node **head)
{
    if (*head == NULL)
        printf("queues is empty");
    else
    {
        struct node *temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

void peek(struct node **head)
{
    if (*head == NULL)
        printf("queue is empty");
    else
        printf("peeking element is : %d", (*head)->data);
}

void traverse(struct node **head)
{
    if (*head == NULL)
        printf("queue is empty");
    else
    {
        struct node *cur = *head;
        while (cur != NULL)
        {
            printf("\nelement is : %d", cur->data);
            cur = cur->next;
        }
    }
}

void getLength(struct node **head)
{
    if (*head == NULL)
        printf("queue is empty");
    else
    {
        int count = 0;
        struct node *cur = *head;
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
    struct node *head = NULL;

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
            enqueue(&head);
            break;
        case 2:
            dequeue(&head);
            break;
        case 3:
            peek(&head);
            break;
        case 4:
            traverse(&head);
            break;
        case 5:
            getLength(&head);
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