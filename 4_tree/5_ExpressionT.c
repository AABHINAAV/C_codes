#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct tree
{
    char data;
    struct tree *left, *right;
}tree;

tree *createNode(char ch)
{
    tree *newnode = (tree *)malloc(sizeof(tree));
    newnode->data = ch;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

void preorder(tree *root)
{
    if(root)
    {
        printf("%c",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(tree *root)
{
    if(root)
    {
        inorder(root->left);
        printf("%c",root->data);
        inorder(root->right);
    }
}

void postorder(tree *root)
{
    if(root)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%c",root->data);
    }
}

typedef struct stk
{
    tree *node;
    struct stk *next;
}stk;

stk *push(stk *top, tree *newnode)
{
    stk *newtop = (stk *)malloc(sizeof(stk));
    newtop->node = newnode;
    newtop->next = top;
    top = newtop;
    return top;
}

stk *pop(stk *top)
{
    stk *temp = top;
    top = top->next;
    free(temp);
    return top;
}

tree *peek(stk *top)
{
    return top->node;
}

tree *expression_tree(char ch[], tree *root, stk *top)
{
    tree *newnode, *lchild, *rchild;
    int i;
    for(i=0; i<strlen(ch); i++)
    {
        if(ch[i] == '^' || ch[i] == '*' || ch[i] == '/' || ch[i] == '+' || ch[i] == '-')
        {
            newnode = createNode(ch[i]);
            rchild = peek(top);
            top = pop(top);
            lchild = peek(top);
            top = pop(top);
            newnode->left = lchild;
            newnode->right = rchild;
            top = push(top, newnode);
        }
        else
        {
            newnode = createNode(ch[i]);
            top = push(top, newnode);
        }
    }
    return peek(top);
}

int main()
{
    char ch[] = "ab*c/ef/g*+k+xy*-";
    tree *root = NULL;
    stk *top = NULL;
    root = expression_tree(ch, root, top);
    preorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    postorder(root);
    printf("\n");
    return 0;
}