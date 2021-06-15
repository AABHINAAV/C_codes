// menu driven circular linked list using single pointer
// insert at end
// delete from end
// traverse
// get lenght
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

void getLength(struct node *head)
{
    int count = 0;
    if (head == NULL)
        printf("list is empty");
    else
    {
        struct node *temp = head;
        do
        {
            count++;
            temp = temp->next;
        } while (temp != head);
    }
    printf("total : %d", count);
}

void traverse(struct node *head)
{
    if (head == NULL)
        printf("list is empty");
    else
    {
        struct node *temp = head;
        do
        {
            printf("element : %d\n", temp->data);
            temp = temp->next;
        } while (temp != head);
    }
}

struct node *insertAtEnd(struct node *tail)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    printf("enter data : ");
    scanf("%d", &newNode->data);
    if (tail == NULL)
    {
        tail = newNode;
        tail->next = tail;
    }
    else
    {
        newNode->next = tail->next;
        tail->next = newNode;
        tail = newNode;
    }
    return tail;
}

struct node *insertAtBeginning(struct node *head)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    printf("enter the data : ");
    scanf("%d", &newnode->data);
    if (head == NULL)
    {
        head = newnode;
        head->next = head;
    }
    else
    {
        newnode->next = head;
        struct node *temp = head;
        do
        {
            temp = temp->next;
        } while (temp->next != head);
        temp->next = newnode;
        head = newnode;
    }
    return head;
}

struct node *deleteAtEnd(struct node *tail)
{
    if (tail == NULL)
        printf("list is empty");
    else if (tail->next == tail)
    {
        printf("last element is deleted : %d .....now the list is empty....",tail->data);
        free(tail);
        tail = NULL;
    }
    else
    {
        struct node *p = tail->next;
        struct node *q = (tail->next)->next;
        while (q != tail)
        {
            p = p->next;
            q = q->next;
        }
        p->next = q->next;
        tail = p;
        free(q);
    }
    return tail;
}

struct node *deleteAtBeginning(struct node *head)
{
    if (head == NULL)
        printf("list is empty");
    else if(head->next == head){
        printf("last element is deleted : %d .....now the list is empty....",head->data);
        free(head);
        head = NULL;
    }
    else
    {
        struct node *temp = head;
        do{
            temp = temp->next;
        }while(temp->next != head);
        struct node *p = temp->next;
        temp->next = head->next;
        head = head->next;
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
        printf("---->MENU<----\n");
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
            tail = insertAtEnd(tail);
            if (head == NULL)
                head = tail;
            break;
        case 2:
            head = insertAtBeginning(head);
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
            traverse(head);
            break;
        case 6:
            getLength(head);
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