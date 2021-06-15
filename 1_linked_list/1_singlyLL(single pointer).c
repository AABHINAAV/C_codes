// menu driven linked list using single pointer
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
    struct node *next;
};

// to get length of LL
void getLength(struct node *head)
{
    int count = 0;
    while (head != NULL)
    {
        head = head->next;
        count++;
    }
    printf("lenght : %d\n", count);
}

// to print LL
void traverse(struct node *head)
{
    while (head != NULL)
    {
        printf("element : %d\n", head->data);
        head = head->next;
    }
}

//reverse traverse
void reversePrint(struct node *head)
{
    if (head == NULL)
        return;
    reversePrint(head->next);
    printf("element : %d\n", head->data);
    return;
}

// insert at end of LL
struct node *insertAtLast(struct node *head)
{
    struct node *lastNode = (struct node *)malloc(sizeof(struct node));
    lastNode->next = NULL;
    if (head == NULL)
    {
        head = lastNode;
    }
    else
    {
        struct node *p = head;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = lastNode;
    }
    printf("enter data : ");
    scanf("%d", &lastNode->data);
    return head;
}

struct node *insertAtBeginning(struct node *head)
{
    struct node *newHead = (struct node *)malloc(sizeof(struct node));
    if (head == NULL)
    {
        head = newHead;
    }
    else
    {
        newHead->next = head;
    }
    printf("enter data : ");
    scanf("%d", &newHead->data);
    return newHead;
}

struct node *deleteAtEnd(struct node *head)
{
    if (head == NULL)
    {
        printf("list is empty");
    }
    else
    {
        struct node *p = head;
        struct node *q = p->next;
        if (q == NULL)
        {
            free(p);
            head = NULL;
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
    return head;
}

struct node *deleteAtBeginning(struct node *head)
{
    struct node *p = head;
    head = head->next;
    free(p);
    return (head);
}

struct node *mergeSortedLists(struct node *head1, struct node *head2)
{
    struct node *head = NULL;
    struct node *start = NULL;
    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data == head2->data)
        {
            if (head == NULL)
            {
                start = head = head1;
                head1 = head1->next;
                head->next = head2;
                head2 = head2->next;
            }
            else
            {
                head->next = head1;
                head1 = head1->next;
                head = head->next;
                head->next = head2;
                head2 = head2->next;
            }
            head = head->next;
        }
        else if (head1->data > head2->data)
        {
            if (head == NULL)
            {
                start = head = head2;
                head2 = head2->next;
            }
            else
            {
                head->next = head2;
                head2 = head2->next;
                head = head->next;
            }
        }
        else
        {
            if (head == NULL)
            {
                start = head = head1;
                head1 = head1->next;
            }
            else
            {
                head->next = head1;
                head1 = head1->next;
                head = head->next;
            }
        }
    }
    if (head1 == NULL && head2 != NULL)
    {
        if (head == NULL)
            start = head = head2;
        else
            head->next = head2;
    }
    if (head2 == NULL && head1 != NULL)
    {
        if (head == NULL)
            start = head = head1;
        else
            head->next = head1;
    }
    return start;
}

int main()
{
    // struct node *head = NULL;
    // int choice;
    // while (1)
    // {
    //     printf("---->MENU<----\n");
    //     printf("1.Insert At End\n");
    //     printf("2.Insert At Beginning\n");
    //     printf("3.Delete At End\n");
    //     printf("4.Delete At Beginning\n");
    //     printf("5.Traverse\n");
    //     printf("6.Get Length\n");
    //     printf("7.Exit\n");
    //     printf("\n");
    //     printf("Enter the choice\n");
    //     scanf("%d", &choice);

    //     switch (choice)
    //     {
    //     case 1:
    //         head = insertAtLast(head);
    //         break;
    //     case 2:
    //         head = insertAtBeginning(head);
    //         break;
    //     case 3:
    //         head = deleteAtEnd(head);
    //         break;
    //     case 4:
    //         head = deleteAtBeginning(head);
    //         break;
    //     case 5:
    //         traverse(head);
    //         break;
    //     case 6:
    //         getLength(head);
    //         break;
    //     case 7:
    //         exit(1);
    //         break;
    //     default:
    //         printf("invalid input...");
    //     }
    // }


//////////////////merging sorted list 
    struct node *head1, *head2, *head;
    head1 = head2 = NULL;

    head1 = insertAtLast(head1);
    head1 = insertAtLast(head1);
    head1 = insertAtLast(head1);

    head2 = insertAtLast(head2);
    head2 = insertAtLast(head2);

    printf("\nlist 1:\n");
    traverse(head1);
    printf("\nlist 2:\n");
    traverse(head2);

    head = mergeSortedLists(head1, head2);
    printf("\nmergerd list:\n");
    traverse(head);
    return 0;
}