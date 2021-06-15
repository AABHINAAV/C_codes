#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct stk
{
    char val;
    struct stk *next;
}stk;

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
    if(top)
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
    if(ch == '^')
        return 3;
    else if(ch == '*' || ch == '/')
        return 2;
    else if(ch == '+' || ch == '-')
        return 1;
    else
        return -1;
}

void infix_to_postfix(stk *top, char ch[])
{
    char res[strlen(ch)], temp;
    int i, index = -1;
    for(i=0; i<strlen(ch); i++)
    {
        if(ch[i] == '(')
            top = push(top, ch[i]);
        else if(ch[i] == ')')
        {
            while(peek(top)!='(')
            {
                temp = peek(top);
                top = pop(top);
                index++;
                res[index] = temp;
            }
            top = pop(top);
        }
        else if(ch[i] == '^' || ch[i] == '*' || ch[i] == '/' || ch[i] == '+' || ch[i] == '-')
        {
            while(!isEmpty(top) && precedence(ch[i]) <= precedence(peek(top)))
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
    while(!isEmpty(top))
    {
        index++;
        res[index] = peek(top);
        top = pop(top);
    }
    for(i=0; i<=index; i++)
    {
        printf("%c", res[i]);
    }
    printf("\n%d\n",index);
}

int main()
{
    stk *top = NULL;
    // char ch[] = "a+b*(c^d-e)^(f+g*h)-i";
    // char ch[] = "a*b/c+e/f*g+k-x*y";
    char ch[] = "(A+B*C)+(D^E)-(F+G*H)-I";

    infix_to_postfix(top, ch);
    return 0;
}