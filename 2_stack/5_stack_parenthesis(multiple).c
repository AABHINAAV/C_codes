#include <stdlib.h>
#include <stdio.h>

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
    if (top == NULL)
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

int isSame(char value, node *top)
{
    if ((value == ')' && top->data == '(') || (value == ']' && top->data == '[') || (value == '}' && top->data == '{'))
        return 1;
    else
        return 0;
}

int checkParenthesis(char *exp)
{
    node *top = NULL;
    int i;

    for (i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '[' || exp[i] == '{' || exp[i] == '(')
            top = push(top, exp[i]);
        else if (exp[i] == ']' || exp[i] == '}' || exp[i] == ')')
        {
            if (isEmpty(top))
                return 0;

            if (isSame(exp[i], top))
                top = pop(top);
            else
                return 0;
        }
    }
    if (isEmpty(top))
        return 1;
    else
        return 0;
}

int main()
{
    char *exp = "([a*a-(3+2]))";
    // char *exp = "(4+{5*5}[])";

    if (checkParenthesis(exp))
        printf("this is matching\n");
    else
        printf("this is not matching\n");

    return 0;
}