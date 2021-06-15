#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left, *right;
} node;

node *createTree()
{
    int val;
    printf("\nenter the data (enter -1 for no node) : ");
    scanf("%d", &val);

    if (val == -1)
        return NULL;
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = val;
    printf("\nenter the data for left node :-");
    newnode->left = createTree();
    printf("\nenter the data for right node :-");
    newnode->right = createTree();

    return newnode;
}

void leftView(node *root, int cur_level, int *max_level)
{
    if(root == NULL)
        return;
    if(*max_level < cur_level)
    {
        printf("%d\t",root->data);
        *max_level = cur_level;
    }
    leftView(root->left, cur_level + 1, max_level);
    leftView(root->right, cur_level + 1, max_level);
}

void rightView(node *root, int cur_level, int *max_level)
{
    if(root == NULL)
        return;
    if(*max_level < cur_level)
    {
        printf("%d\t",root->data);
        *max_level = cur_level;
    }
    rightView(root->right, cur_level + 1, max_level);
    rightView(root->left, cur_level + 1, max_level);
}

int main()
{
    node *root = createTree();
    
    printf("left view : ");
    int max_level = -1;
    int cur_level = 0;
    leftView(root, cur_level, &max_level);
    
    printf("\nright view : ");
    max_level = -1;
    cur_level = 0;
    rightView(root, cur_level, &max_level);
}