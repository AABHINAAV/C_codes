/*
reverse the string
and then do same operation we did to convert from infix to postfix
only difference is that in infix to postfix if we get any operator that has precedence less than equal to 
that on top of stack we perform operation of popping
while in infix to prefix we do so only if operator's precedence is less than that on top of stack
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct stk
{
    char val;
    struct stk *next;
} stk;

stk *push(stk *top, char ch)
{
    stk *newnode = (stk *)malloc(sizeof(stk));
    newnode->val = ch;
    newnode->next = top;
    top = newnode;
    return top;
}

stk *pop(stk *top)
{
    if (top)
    {
        stk *temp = top;
        top = top->next;
        free(temp);
    }
    return top;
}

int isEmpty(stk *top)
{
    return top == NULL;
}

char peek(stk *top)
{
    return top->val;
}

int precedence(char ch)
{
    if (ch == '^')
        return 3;
    else if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '+' || ch == '-')
        return 1;
    else
        return -1;
}

void infix_to_prefix(stk *top, char ch[])
{
    char res[strlen(ch)], temp;
    int i, index = -1;
    for (i = 0; i < strlen(ch); i++)
    {
        if (ch[i] == '(')
            top = push(top, ch[i]);
        else if (ch[i] == ')')
        {
            while (peek(top) != '(')
            {
                temp = peek(top);
                top = pop(top);
                index++;
                res[index] = temp;
            }
            top = pop(top);
        }
        else if (ch[i] == '^' || ch[i] == '*' || ch[i] == '/' || ch[i] == '+' || ch[i] == '-')
        {
            while (!isEmpty(top) && precedence(ch[i]) < precedence(peek(top)))
            {
                index++;
                res[index] = peek(top);
                top = pop(top);
            }
            top = push(top, ch[i]);
        }
        else
        {
            index++;
            res[index] = ch[i];
        }
    }
    while (!isEmpty(top))
    {
        index++;
        res[index] = peek(top);
        top = pop(top);
    }
    for (i = index; i >= 0; i--)
    {
        printf("%c", res[i]);
    }
    printf("\n");
}

int main()
{
    stk *top = NULL;
    // char ch[] = "K+L-M*N+(O^P)*W/U/V*T+Q";
    // char ch[] = "a*b/c+e/f*g+k-x*y";
    char ch[] = "(A+B*C)-(D+E)^(F+G)";
    char temp;
    int i = 0;
    int j = strlen(ch) - 1;
    while (i < j)
    {
        temp = ch[i];
        ch[i] = ch[j];
        ch[j] = temp;
        i++;
        j--;
    }
    for (i = 0; i < strlen(ch); i++)
    {
        if (ch[i] == ')')
            ch[i] = '(';
        else if (ch[i] == '(')
            ch[i] = ')';
    }
    infix_to_prefix(top, ch);
    return 0;
}