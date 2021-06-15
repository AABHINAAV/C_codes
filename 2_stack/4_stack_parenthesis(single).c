#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    char data;
    struct node *next;
} node;

node *push(node *top, char value)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = value;
    newnode->next = top;
    top = newnode;
    return top;
}

int isEmpty(node *top)
{
    if(top == NULL)
        return 1;
    else 
        return 0;
}

node *pop(node *top)
{
    node *temp = top;
    top = top->next;
    free(temp);
    return top;
}

int checkParenthesis(char *exp)
{
    node *top = NULL;
    int i;
    for (i = 0; exp[i] != '\0'; i++)
    {
        if(exp[i] == '(')
            top = push(top,'(');
        else if(exp[i] == ')')
        {
            if(isEmpty(top))
                return 0;
            top = pop(top);
        }
    }

    if(isEmpty(top))
        return 1;
    else
        return 0;
}

int main()
{
    char *exp = "(8)*(9))";

    if (checkParenthesis(exp))
        printf("the parenthesis is matching\n");
    else
        printf("the parenthesis is not matching\n");

    return 0;
}
