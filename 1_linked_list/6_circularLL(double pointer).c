#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

void getLength(node **head)
{
    if (*head == NULL)
        printf("list is empty");
    else
    {
        int count = 0;
        node *cur = *head;
        do
        {
            count++;
            cur = cur->next;
        } while (cur != *head);
        printf("\ntotal : %d",count);
    }
}

void traverse(node **head)
{
    if (*head == NULL)
        printf("list is empty");
    else
    {
        node *cur = *head;
        do
        {
            printf("element : %d\n", cur->data);
            cur = cur->next;
        } while (cur != *head);
    }
}

void insertAtEnd(node **head)
{
    node *newnode = (struct node *)malloc(sizeof(struct node));
    printf("enter the data : ");
    scanf("%d", &newnode->data);

    if (*head == NULL)
    {
        *head = newnode;
        newnode->next = *head;
    }
    else
    {
        node *cur = *head;
        while (cur->next != *head)
            cur = cur->next;
        cur->next = newnode;
        newnode->next = *head;
    }
}

void insertAtBeginning(node **head)
{
    node *newnode = (struct node *)malloc(sizeof(struct node));
    printf("enter the data : ");
    scanf("%d", &newnode->data);
    newnode->next = *head;

    node *cur = *head;
    while (cur->next != *head)
    {
        printf("element : %d\n", cur->data);
        cur = cur->next;
    }
    cur->next = newnode;

    *head = newnode;
}

void deleteAtEnd(node **head)
{
    if (*head == NULL)
        printf("list is empty");
    else
    {
        node *cur = *head;
        while (cur->next->next != *head)
        {
            cur = cur->next;
        }
        node *temp = cur->next;
        cur->next = cur->next == cur ? *head = NULL : *head;
        free(temp);
    }
}

void deleteAtBeginning(node **head)
{
    if (*head == NULL)
        printf("list is empty");
    else
    {
        node *cur = *head;
        while (cur->next != *head)
        {
            cur = cur->next;
        }
        node *temp = cur->next;
        cur->next = (*head)->next;
        *head = (*head)->next == *head ? NULL : (*head)->next;
        free(temp);
    }
}

int main()
{
    struct node *head = NULL;

    int choice;
    while (1)
    {
        printf("\n\n---->MENU<----\n");
        printf("1.Insert at end\n");
        printf("2.Insert at beginning\n");
        printf("3.Delete from end\n");
        printf("4.Delete from beginnig\n");
        printf("5.Traverse\n");
        printf("6.Get Length\n");
        printf("7.Exit\n");
        printf("\n");
        printf("Enter the choice\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insertAtEnd(&head);
            break;
        case 2:
            insertAtBeginning(&head);
            break;
        case 3:
            deleteAtEnd(&head);
            break;
        case 4:
            deleteAtBeginning(&head);
            break;
        case 5:
            traverse(&head);
            break;
        case 6:
            getLength(&head);
            break;
        case 7:
            exit(1);
            break;
        default:
            printf("invalid input...");
        }
    }
    return 0;
}