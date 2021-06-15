// menu driven doubly linked list using double pointer
// insert at beginning
// insert at end
// delete from beginning
// delete from end
// traverse
// get length
#include <stdlib.h>
#include <stdio.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

void traverse(struct node **head)
{
    if (*head == NULL)
    {
        printf("list is empty");
    }
    else
    {
        struct node *temp = *head;
        while (temp != NULL)
        {
            printf("element : %d\n", temp->data);
            temp = temp->next;
        }
    }
}

void getLength(struct node **head)
{
    int count = 0;
    if (*head == NULL)
    {
        printf("list is empty");
    }
    else
    {
        struct node *temp = *head;
        do
        {
            count++;
            temp = temp->next;
        } while (temp != NULL);
        printf("total : %d", count);
    }
}

void insertAtLast(struct node **tail)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    printf("enter the data : ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    if (*tail == NULL)
    {
        newnode->prev = NULL;
        *tail = newnode;
    }
    else
    {
        (*tail)->next = newnode;
        newnode->prev = *tail;
        *tail = newnode;
    }
}

void insertAtBeginning(struct node **head)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    printf("enter the data : ");
    scanf("%d", &newnode->data);
    newnode->prev = NULL;
    if (*head == NULL)
    {
        newnode->next = NULL;
        *head = newnode;
    }
    else
    {
        newnode->next = *head;
        (*head)->prev = newnode;
        *head = newnode;
    }
}

void deleteAtEnd(struct node **tail)
{
    if (*tail == NULL)
    {
        printf("list is empty");
    }
    else if ((*tail)->prev == NULL)
    {
        free(*tail);
        *tail = NULL;
    }
    else
    {
        struct node *p = *tail;
        *tail = (*tail)->prev;
        (*tail)->next = NULL;
        free(p);
    }
}

void deleteAtBeginning(struct node **head){
    if(*head == NULL){
        printf("list is empty");
    }
    else if((*head)->next == NULL){
        free(*head);
        *head = NULL;
    }
    else{
        struct node *p = *head;
        *head = (*head)->next;
        (*head)->prev = NULL;
        free(p);
    }
}

int main()
{
    struct node *head = NULL;
    struct node *tail = NULL;

    int choice;
    while (1)
    {
        printf("\n\n---->MENU<----\n");
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
            insertAtLast(&tail);
            if (head == NULL)
                head = tail;
            break;
        case 2:
            insertAtBeginning(&head);
            if (tail == NULL)
                tail = head;
            break;
        case 3:
            deleteAtEnd(&tail);
            if (tail == NULL)
                head = NULL;
            break;
        case 4:
            deleteAtBeginning(&head);
            if (head == NULL)
                tail = NULL;
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