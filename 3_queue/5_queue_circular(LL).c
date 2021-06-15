// circular queue using linked list
// it is similar to circular linked list 
// one main property is :-
    // insertion is done only at end
    // deletion is done only at beginning
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
        printf("queue is empty\n");
    else
    {
        struct node *temp = head;
        do
        {
            count++;
            temp = temp->next;
        } while (temp != head);
    }
    printf("total : %d\n", count);
}

void traverse(struct node *head)
{
    if (head == NULL)
        printf("queue is empty\n");
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

struct node *enqueue(struct node *tail)
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

struct node *dequeue(struct node *tail)
{
    if(tail == NULL)
        printf("queue is empty\n");
    else
    {
        struct node *temp = tail->next;
        tail->next = tail->next->next;
        free(temp);
    }
    return tail;
}

int main()
{
    struct node *head = NULL;
    struct node *tail = NULL;

    int choice;
    while (1)
    {
        printf("---->MENU<----\n");
        printf("1.enqueue\n");
        printf("2.dequeue\n");
        printf("3.Traverse\n");
        printf("4.Get Length\n");
        printf("5.Exit\n");
        printf("\n");
        printf("Enter the choice\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            tail = enqueue(tail);
            if (head == NULL)
                head = tail;
            break;
        case 2:
            tail = dequeue(tail);
            if (tail == NULL)
                head = NULL;
            break;
        case 3:
            traverse(head);
            break;
        case 4:
            getLength(head);
            break;
        case 5:
            exit(1);
            break;
        default:
            printf("invalid input...");
        }
    }
    return 0;
}