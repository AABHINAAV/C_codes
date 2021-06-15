// // implementation of queue using two stacks and array
// #include <stdlib.h>
// #include <stdio.h>
// #define N 5
// int s1[N], s2[N];
// int top1 = -1, top2 = -1;
// int count = 0;

// void Push1(int data)
// {
//     top1++;
//     s1[top1] = data;
// }

// int Pop1()
// {
//     return s1[top1--];
// }

// void Push2(int data)
// {
//     top2++;
//     s2[top2] = data;
// }

// int Pop2()
// {
//     return s2[top2--];
// }

// void enqueue()
// {
//     if (top1 == N - 1)
//         printf("queues is full");
//     else
//     {
//         int data;
//         printf("enter the data : ");
//         scanf("%d", &data);
//         Push1(data);
//         count++;
//     }
// }

// void dequeue()
// {
//     if (top1 == -1)
//         printf("queue is empty");
//     else
//     {
//         int i;
//         for (i = 0; i < count; i++)
//             Push2(Pop1());

//         Pop2();
//         count--;

//         for (i = 0; i < count; i++)
//             Push1(Pop2());

//         top2 = -1;
//     }
// }

// void Peek()
// {
//     printf("top element : %d\n", s1[0]);
// }

// void getLength()
// {
//     printf("total : %d\n", count);
// }

// void traverse()
// {
//     if (top1 == -1)
//         printf("queue is empty");
//     else
//     {
//         int i;
//         for (i = 0; i < count; i++)
//             Push2(Pop1());

//         for (i = 0; i < count; i++)
//             printf("\nelement : %d", s1[i]);

//         for (i = 0; i < count; i++)
//             Push1(Pop2());
//     }
// }

// int main()
// {
//     int choice;
//     while (1)
//     {
// printf("\n\n---->MENU<----\n");
// printf("1.Insert\n");
// printf("2.Delete\n");
// printf("3.Peek\n");
// printf("4.Traverse\n");
// printf("5.Get Length\n");
// printf("6.Exit\n");
// printf("\n");
// printf("Enter the choice\n");
// scanf("%d", &choice);

//         switch (choice)
//         {
//         case 1:
//             enqueue();
//             break;
//         case 2:
//             dequeue();
//             break;
//         case 3:
//             Peek();
//             break;
//         case 4:
//             traverse();
//             break;
//         case 5:
//             getLength();
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
//
//
//
//
//
//
//
// implementation of queue using two stacks and ll
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} node;

void enqueue(node **top)
{
    node *newnode = (node *)malloc(sizeof(node));
    printf("enter the data : ");
    scanf("%d", &newnode->data);
    newnode->next = *top;
    (*top) = newnode;
}

void transfer(node **q1, node **q2)
{
    while ((*q1) != NULL)
    {
        node *newnode = (node *)malloc(sizeof(node));
        newnode->data = (*q1)->data;
        newnode->next = (*q2);
        *q2 = newnode;
        node *temp = *q1;
        *q1 = (*q1)->next;
        free(temp);
    }
}

void dequeue(node **q1, node **q2)
{
    if ((*q1) == NULL)
        printf("queue is empty");
    else
    {
        transfer(&(*q1), &(*q2));
        node *temp = *q2;
        *q2 = (*q2)->next;
        free(temp);
        transfer(&(*q2), &(*q1));
    }
}

void Peek(node **q1, node **q2)
{
    if (*q1 == NULL)
    {
        printf("queue is empty\n");
    }
    else
    {
        transfer(&(*q1),&(*q2));
        printf("\npeeking element : %d\n", (*q2)->data);
        transfer(&(*q2),&(*q1));
    }
}

void traverse(node **q1, node **q2)
{
    if ((*q1) == NULL)
    {
        printf("queue is empty\n");
    }
    else
    {
        transfer(&(*q1),&(*q2));
        node *temp = *q2;
        while (temp != NULL)
        {
            printf("\n%d", temp->data);
            temp = temp->next;
        }
        transfer(&(*q2),&(*q1));
    }
}

int main()
{
    node *q1 = NULL;
    node *q2 = NULL;
    int choice;
    while (1)
    {
        printf("\n\n---->MENU<----\n");
        printf("1.Insert\n");
        printf("2.Delete\n");
        printf("3.Peek\n");
        printf("4.Traverse\n");
        printf("5.Exit\n");
        printf("\n");
        printf("Enter the choice\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            enqueue(&q1);
            break;
        case 2:
            dequeue(&q1, &q2);
            break;
        case 3:
            Peek(&q1, &q2);
            break;
        case 4:
            traverse(&q1, &q2);
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