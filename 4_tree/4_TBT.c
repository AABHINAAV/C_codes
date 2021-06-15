#include <stdio.h>
#include <stdlib.h>
typedef struct tree
{
    int data;
    int lflag;
    struct tree *left;
    int rflag;
    struct tree *right;
} tree;

tree *createNode(int key)
{
    tree *newnode = (tree *)malloc(sizeof(tree));
    newnode->data = key;
    newnode->left = NULL;
    newnode->lflag = 0;
    newnode->right = NULL;
    newnode->rflag = 0;
    return newnode;
}

tree *create_TBT(tree *root, int key)
{
    if (root == NULL)
    {
        tree *newnode = createNode(key);
        return newnode;
    }

    tree *cur = root;
    tree *prev = NULL;
    while (cur)
    {
        prev = cur;
        if (cur->data > key)
        {
            if (cur->lflag == 0 && cur->left)
                cur = cur->left;
            else
                break;
        }
        else if (cur->data < key)
        {
            if (cur->rflag == 0 && cur->right)
                cur = cur->right;
            else
                break;
        }
        else
        {
            printf("node already present\n");
            return root;
        }
    }

    tree *newnode = createNode(key);
    if (prev->data > key)
    {
        newnode->left = prev->left;
        newnode->lflag = 1;
        newnode->right = prev;
        newnode->rflag = 1;

        prev->left = newnode;
        prev->lflag = 0;
    }
    else
    {
        newnode->left = prev;
        newnode->lflag = 1;
        newnode->right = prev->right;
        newnode->rflag = 1;

        prev->right = newnode;
        prev->rflag = 0;
    }

    return root;
}

void inorder(tree *root)
{
    if (!root)
    {
        printf("tree is empty\n");
        return;
    }

    if (root)
    {
        if(root->lflag == 0)
            inorder(root->left);
        printf("%d  ", root->data);
        if(root->rflag == 0)
            inorder(root->right);
    }
}

int main()
{
    int a[21] = {50, 16, 90, 14, 40, 78, 100, 10, 15, 35, 45, 75, 82, 5, 32, 36, 81, 85, 37, 79, 87};

    tree *root = NULL;
    for (int i = 0; i < 21; i++)
        root = create_TBT(root, a[i]);

    inorder(root);
    printf("\n");

    return 0;
}