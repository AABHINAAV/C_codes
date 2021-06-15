// menu driven linked list using double pointer
// insert at beginning
// insert at end
// delete from beginning
// delete from end
// traverse
// get length
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void traverse(struct node **head)
{
    struct node *temp = *head;
    if (*head == NULL)
    {
        printf("list is empty");
    }
    else
    {
        while (temp != NULL)
        {
            printf("element : %d\n", temp->data);
            temp = temp->next;
        }
    }
}

void getLength(struct node **head)
{
    struct node *temp = *head;
    int count = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    printf("lenght : %d\n", count);
}

void insertAtLast(struct node **head)
{
    struct node *lastnode = (struct node *)malloc(sizeof(struct node));
    printf("enter the data : ");
    scanf("%d", &lastnode->data);
    if (*head == NULL)
    {
        *head = lastnode;
    }
    else
    {
        struct node *p = *head;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = lastnode;
        lastnode->next = NULL;
    }
}

void insertAtBeginning(struct node **head)
{
    struct node *newhead = (struct node *)malloc(sizeof(struct node));
    printf("enter the data : ");
    scanf("%d", &newhead->data);
    if (*head == NULL)
    {
        newhead->next = NULL;
        *head = newhead;
    }
    else
    {
        newhead->next = *head;
        *head = newhead;
    }
}

void deleteAtEnd(struct node **head)
{
    if (*head == NULL)
    {
        printf("list is empty");
    }
    else
    {
        struct node *p = *head;
        struct node *q = p->next;
        if (q == NULL)
        {
            free(p);
            *head = NULL;
        }
        else
        {
            while (q->next != NULL)
            {
                p = p->next;
                q = q->next;
            }
            p->next = NULL;
            free(q);
        }
    }
}

void deleteAtBeginning(struct node **head){
    if(*head == NULL){
        printf("list is empty");
    }
    else{
        struct node *p = *head;
        *head = (*head)->next;
        free(p);
    }
}

int main()
{
    struct node *head = NULL;
    int choice;
    while (1)
    {
        printf("---->MENU<----\n");
        printf("1.Insert At End\n");
        printf("2.Insert At Beginning\n");
        printf("3.Delete At End\n");
        printf("4.Delete At Beginning\n");
        printf("5.Traverse\n");
        printf("6.Get Length\n");
        printf("7.Exit\n");
        printf("\n");
        printf("Enter the choice\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insertAtLast(&head);
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
