// menu driven double queue using linked list and single pointer
// insert at beginning
// insert at end
// delete from beginning
// delete from end
// traverse forward
// traverse backward
// get length

// it is simply a doubly linked list with capabality of insertion, deletion and traversing from both the ends
// but as it is linked list so memory is allocated dynamically thus there is checking of full like we used to do in array
#include <stdlib.h>
#include <stdio.h>
struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

void traverseFwd(struct node *head)
{
    if (head == NULL)
    {
        printf("list is emppty");
    }
    else
    {
        do
        {
            printf("element : %d\n", head->data);
            head = head->next;
        } while (head != NULL);
    }
}

void traverseBkwd(struct node *tail)
{
    if (tail == NULL)
    {
        printf("list is emppty");
    }
    else
    {
        do
        {
            printf("element : %d\n", tail->data);
            tail = tail->prev;
        } while (tail != NULL);
    }
}

void getLength(struct node *head)
{
    int count = 0;
    if (head == NULL)
    {
        printf("list is empty");
    }
    else
    {
        do
        {
            count++;
            head = head->next;
        } while (head != NULL);
        printf("total : %d", count);
    }
}

struct node *insertAtEnd(struct node *tail)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    printf("enter data : ");
    scanf("%d", &newNode->data);
    newNode->next = NULL;
    if (tail == NULL)
    {
        newNode->prev = NULL;
        tail = newNode;
    }
    else
    {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
    return tail;
}

struct node *insertAtBeginning(struct node *head)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    printf("enter data : ");
    scanf("%d", &newNode->data);
    newNode->prev = NULL;
    if (head == NULL)
    {
        newNode->next = NULL;
        head = newNode;
    }
    else
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    return head;
}

struct node *deleteAtEnd(struct node *tail)
{
    if (tail == NULL)
    {
        printf("list is empty");
    }
    else if (tail->prev == NULL)
    {
        printf("deleting last element : %d ..... now the list is empty....", tail->data);
        free(tail);
        tail = NULL;
    }
    else
    {
        struct node *temp = tail;
        tail = tail->prev;
        tail->next = NULL;
        free(temp);
    }
    return tail;
}

struct node *deleteAtBeginning(struct node *head)
{
    if (head == NULL)
    {
        printf("list is empty");
    }
    else if (head->next == NULL)
    {
        printf("deleting last element : %d ..... now the list is empty....", head->data);
        free(head);
        head = NULL;
    }
    else
    {
        struct node *p = head;
        head = head->next;
        head->prev = NULL;
        free(p);
    }
    return head;
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
        printf("5.Traverse Forward\n");
        printf("6.Traverse Backward\n");
        printf("7.Get Length\n");
        printf("8.Exit\n");
        printf("\n");
        printf("Enter the choice\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            tail = insertAtEnd(tail);
            if (head == NULL)
                head = tail;
            break;
        case 2:
            head = insertAtBeginning(head);
            if (tail == NULL)
                tail = head;
            break;
        case 3:
            tail = deleteAtEnd(tail);
            if (tail == NULL)
                head = NULL;
            break;
        case 4:
            head = deleteAtBeginning(head);
            if (head == NULL)
                tail = NULL;
            break;
        case 5:
            traverseFwd(head);
            break;
        case 6:
            traverseBkwd(tail);
            break;
        case 7:
            getLength(head);
            break;
        case 8:
            exit(1);
            break;
        default:
            printf("invalid input...");
        }
    }
    return 0;
}