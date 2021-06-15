// // queue using linked list and single pointer
// #include <stdlib.h>
// #include <stdio.h>
// struct node
// {
//     int data;
//     struct node *next;
// };

// struct node *enqueue(struct node *rear);
// struct node *dequeue(struct node *front);
// void peek(struct node *front);
// void traverse(struct node *front);
// void getLength(struct node *front);

// int main()
// {
//     struct node *front = NULL;
//     struct node *rear = NULL;

//     int choice;
//     while (1)
//     {
//         printf("\n\n---->MENU<----\n");
//         printf("1.Insert\n");
//         printf("2.Delete\n");
//         printf("3.Peek\n");
//         printf("4.Traverse\n");
//         printf("5.Get Length\n");
//         printf("6.Exit\n");
//         printf("\n");
//         printf("Enter the choice\n");
//         scanf("%d", &choice);

//         switch (choice)
//         {
//         case 1:
//             rear = enqueue(rear);
//             if (front == NULL)
//                 front = rear;
//             break;
//         case 2:
//             front = dequeue(front);
//             if (front == NULL)
//                 rear = front;
//             break;
//         case 3:
//             peek(front);
//             break;
//         case 4:
//             traverse(front);
//             break;
//         case 5:
//             getLength(front);
//             break;
//         case 6:
//             exit(1);
//             break;
//         default:
//             printf("invalid input...");
//         }
//     }
//     return 0;
// }

// struct node *enqueue(struct node *rear)
// {
//     struct node *newNode = (struct node *)malloc(sizeof(struct node));
//     printf("enter data : ");
//     scanf("%d", &newNode->data);
//     if (rear == NULL)
//     {
//         rear = newNode;
//     }
//     else
//     {
//         rear->next = newNode;
//         newNode->next = NULL;
//         rear = newNode;
//     }
//     return rear;
// }

// struct node *dequeue(struct node *front)
// {
//     if (front == NULL)
//     {
//         printf("queue is empty....underflow condition....");
//     }
//     else
//     {
//         struct node *temp = front;
//         printf("dequeued element : %d", temp->data);
//         front = front->next;
//         free(temp);
//     }
//     return front;
// }

// void peek(struct node *front)
// {
//     if (front == NULL)
//         printf("queue is empty...");
//     else
//         printf("first element in queue : %d", front->data);
// }

// void traverse(struct node *front)
// {
//     if (front == NULL)
//         printf("queue is empty...");
//     else
//     {
//         while (front != NULL)
//         {
//             printf("element : %d\n", front->data);
//             front = front->next;
//         }
//     }
// }

// void getLength(struct node *front)
// {
//     if (front == NULL)
//         printf("queue is empty...");
//     else
//     {
//         int count = 0;
//         struct node *temp = front;
//         while (temp != NULL)
//         {
//             count++;
//             temp = temp->next;
//         }
//         printf("total : %d", count);
//     }
// }

#include <stdlib.h>
#include <stdio.h>
struct node
{
    int data;
    struct node *next;
};

struct node *enqueue(struct node *head)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    printf("enter the data : ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;

    if (head == NULL)
        head = newnode;
    else
    {
        struct node *cur = head;
        while (cur->next != NULL)
            cur = cur->next;
        cur->next = newnode;
    }
    return head;
}

struct node *dequeue(struct node *head)
{
    if (head == NULL)
        printf("queues is empty");
    else
    {
        struct node *temp = head;
        head = head->next;
        free(temp);
    }
    return head;
}

void peek(struct node *head)
{
    if(head == NULL)
        printf("queue is empty");
    else
        printf("peeking element is : %d",head->data);
}

void traverse(struct node *head)
{
    if (head == NULL)
        printf("queue is empty");
    else
    {
        while (head != NULL)
        {
            printf("\nelement is : %d", head->data);
            head = head->next;
        }
    }
}

void getLength(struct node *head)
{
    if (head == NULL)
        printf("queue is empty");
    else
    {
        int count = 0;
        while (head != NULL)
        {
            count++;
            head = head->next;
        }
        printf("total : %d",count);
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
            head = enqueue(head);
            break;
        case 2:
            head = dequeue(head);
            break;
        case 3:
            peek(head);
            break;
        case 4:
            traverse(head);
            break;
        case 5:
            getLength(head);
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