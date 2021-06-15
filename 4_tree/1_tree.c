#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct node
{
    int data;
    struct node *left, *right;
} node;
//
//
//
//
///////////////////////// user defined tree creation
node *createTree()
{
    int x;
    node *newnode = (node *)malloc(sizeof(node));
    printf("\nenter the data (enter -1 for no node) : ");
    scanf("%d", &x);

    if (x == -1)
        return 0;
    newnode->data = x;
    printf("\nenter data for left child :-");
    newnode->left = createTree();
    printf("\nenter the data for right child :-");
    newnode->right = createTree();
    return newnode;
}
//
//
//
//
///////////////////////// tree traversal
void PreOrder(node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        PreOrder(root->left);
        PreOrder(root->right);
    }
}
//
void InOrder(node *root)
{
    if (root != NULL)
    {
        InOrder(root->left);
        printf("%d ", root->data);
        InOrder(root->right);
    }
}
//
void PostOrder(node *root)
{
    if (root != NULL)
    {
        PostOrder(root->left);
        PostOrder(root->right);
        printf("%d ", root->data);
    }
}
//
//
//
//
///////////////////////// BST validation
int main_func(node *root, long max, long min)
{
    if (!root)
        return 1;
    if (root->data >= max || root->data <= min)
        return 0;
    return main_func(root->left, root->data, min) && main_func(root->right, max, root->data);
}
int isBST(node *root)
{
    //method 1 : slow and does not pass all test cases
    // it checkes for nodes properties but not for whole subtree
    // also gives compile time error for prev checking line
    // static tree *prev = NULL;
    // if(root)
    // {
    //     if(!isBST(root->left))
    //         return 0;
    //     if(prev && prev->data >= root->data)
    //         return 0;
    //     prev = root;
    //     return isBST(root->right);
    // }
    // else return 1;

    //method 2 : fast and passes all test cases
    return main_func(root, LONG_MAX, LONG_MIN);
}
//
//
//
//
///////////////////////// search in BST
node *SearchBST(node *root, int key)
{
    if (root == NULL)
        return NULL;
    if (root->data == key)
        return root;
    else if (root->data > key)
        SearchBST(root->left, key);
    else
        SearchBST(root->right, key);
}
//
node *SearchBST_iterative(node *root, int key)
{
    while (root != NULL)
    {
        if (root->data == key)
            return root;
        else if (root->data > key)
            root = root->left;
        else
            root = root->right;
    }
    return NULL;
}
//
//
//
//
///////////////////////// BST creation
node *createNode(int value)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = value;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}
//
node *insertion(node *root, int key)
{
    if (!root)
    {
        node *newnode = createNode(key);
        return newnode;
    }

    node *cur = root;
    node *prev = NULL;
    while (cur != NULL)
    {
        prev = cur;
        if (cur->data == key)
        {
            printf("node is already present");
            return;
        }
        else if (cur->data > key)
            cur = cur->left;
        else
            cur = cur->right;
    }

    node *newnode = createNode(key);
    if (prev->data < key)
        prev->right = newnode;
    else
        prev->left = newnode;

    return root;
}
//
//
//
//
///////////////////////// BST creation using recursion
node *insertionNode(node *root, int key)
{

    if (root == NULL)
    {
        node *newnode = createNode(key);
        newnode->data = key;
        newnode->left = NULL;
        newnode->right = NULL;
        return newnode;
    }

    if (root->data > key)
        root->left = insertionNode(root->left, key);
    else
        root->right = insertionNode(root->right, key);

    return root;
}
//
//
//
//
///////////////////////// inorder predecessor
node *inorder_predecessor(node *head, int key)
{
    node *root = search(head, key);
    if (!root)
    {
        printf("such node not present");
        return NULL;
    }

    node *cur = root;
    if (root->left)
    {
        cur = root->left;
        while (cur && cur->right)
            cur = cur->right;
        return cur;
    }
    else
    {
        while (head != root)
        {
            if (head->data > key)
            {
                head = head->left;
            }
            else
            {
                cur = head;
                head = head->right;
            }
        }
        return cur;
    }
}
//
//
//
//
///////////////////////// inorder sucessor
node *inorder_sucessor(node *head, int key)
{
    node *root = search(head, key);
    if (!root)
    {
        printf("no such node present\n");
        return NULL;
    }

    node *cur = root;
    if (root->right)
    {
        cur = root->right;
        while (cur && cur->left)
            cur = cur->left;
        return cur;
    }
    else
    {
        while (head != root)
        {
            if (head->data > key)
            {
                cur = head;
                head = head->left;
            }
            else
            {
                head = head->right;
            }
        }
        return cur;
    }
}
//
//
//
//
///////////////////////// BST node deletion
node *deletion(node *root, int value)
{
    if (root == NULL)
        return root;

    if (root->data > value)
        root->left = deletion(root->left, value);
    else if (root->data < value)
        root->right = deletion(root->right, value);
    else
    {
        if (root->left == NULL)
        {
            node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            node *temp = root->left;
            free(root);
            return temp;
        }

        // node *temp = inorder_predecessor(root->left);
        node *temp = inorder_sucessor(root, root->data);

        root->data = temp->data;

        // root->left = deletion(root->left, temp->data);
        root->right = deletion(root->right, temp->data);
    }
    return root;
}

int sizeOfTree(node *root)
{
    if (root == NULL)
        return 0;
    return (sizeOfTree(root->left) + 1 + sizeOfTree(root->right));
}

int main()
{
    node *root;
    root = createTree();
    // printf("\nPre-Order Traversal : ");
    // PreOrder(root);
    // printf("\nIn-Order Traversal : ");
    // InOrder(root);
    // printf("\nPost-Order Traversal : ");
    // PostOrder(root);

    // checking is tree is BST or not
    // if (isBST(root))
    //     printf("\nit is bst\n");
    // else
    //     printf("\nit is not bst\n");

    // if tree holds specific value or not
    // int key;
    // printf("\nenter data to search : ");
    // scanf("%d", &key);
    // recursive search
    // if (SearchBST(root, key) != NULL)
    //     printf("present\n");
    // else
    //     printf("not present\n");
    // // iterative search
    // if (SearchBST_iterative(root, key) != NULL)
    //     printf("present\n");
    // else
    //     printf("not present\n");

    // insertion in BST
    // root = insertion(root, 30);
    // printf("\nPost-Order Traversal : ");
    // PostOrder(root);

    root = deletion(root, 20);
    printf("\nIn-Order Traversal : ");
    InOrder(root);
}