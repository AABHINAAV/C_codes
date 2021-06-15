#include <stdio.h>
#include <stdlib.h>
typedef struct tree
{
    int data;
    struct tree *left, *right;
} tree;

tree *createNode(int key)
{
    tree *newnode = (tree *)malloc(sizeof(tree));
    newnode->data = key;
    newnode->left = newnode->right = NULL;
    return newnode;
}

tree *create_BST(tree *root, int key)
{
    if (root == NULL)
    {

        tree *newnode = createNode(key);
        return newnode;
    }

    tree *cur = root;
    tree *prev = NULL;
    while (cur != NULL)
    {
        prev = cur;
        if (cur->data > key)
            cur = cur->left;
        else if (cur->data < key)
            cur = cur->right;
        else
        {
            printf("\nalready present");
            return root;
        }
    }

    tree *newnode = createNode(key);

    if (prev->data > key)
        prev->left = newnode;
    else
        prev->right = newnode;

    return root;
}

void inorder(tree *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d  ", root->data);
        inorder(root->right);
    }
}

tree *search(tree *root, int key)
{
    while (root)
    {
        if (root->data > key)
            root = root->left;
        else if (root->data < key)
            root = root->right;
        else
            return root;
    }
    return NULL;
}

void inorder_predecessor(tree *head, int key)
{
    tree *root = search(head, key);
    if (!root)
    {
        printf("such node not present");
        return;
    }

    tree *cur = root;
    if (root->left)
    {
        cur = root->left;
        while (cur && cur->right)
            cur = cur->right;
        printf("%d\n", cur->data);
        return;
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
        printf("%d\n", cur->data);
        return;
    }
}

void inorder_sucessor(tree *head, int key)
{
    tree *root = search(head, key);
    if (!root)
    {
        printf("no such node present\n");
        return;
    }

    tree *cur = root;
    if (root->right)
    {
        cur = root->right;
        while (cur && cur->left)
            cur = cur->left;
        printf("%d\n", cur->data);
        return;
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
        printf("%d\n", cur->data);
        return;
    }
}

int num_of_nodes(tree *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        int ltotal = num_of_nodes(root->left);
        int rtotal = num_of_nodes(root->right);
        int total = ltotal + rtotal + 1;
        return total;
    }
}

int sum_of_nodes(tree *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        int ltotal = sum_of_nodes(root->left);
        int rtotal = sum_of_nodes(root->right);
        int total = ltotal + rtotal + root->data;
        return total;
    }
}

int max_node(tree *root)
{
    while(root->right)
    {
        root = root->right;
    }
    return root->data;
}

int min_node(tree *root)
{
    while(root->left)
    {
        root = root->left;
    }
    return root->data;
}

int rangeSumBST(tree *root, int low, int high)
{
    if(root == NULL)
    {
        return 0;
    }
    if(low < root->data && high < root->data)
        return rangeSumBST(root->left, low, high);
    else if(low > root->data && high > root->data)
        return rangeSumBST(root->right, low, high);
    else
    {
        int lsum = rangeSumBST(root->left, low, high);
        int rsum = rangeSumBST(root->right, low, high);
        return lsum + rsum + root->data;
    }
}

int main()
{
    int a[21] = {50, 16, 90, 14, 40, 78, 100, 10, 15, 35, 45, 75, 82, 5, 32, 36, 81, 85, 37, 79, 87};

    tree *root = NULL;
    for (int i = 0; i < 21; i++)
        root = create_BST(root, a[i]);
    
    inorder(root);
    printf("\n");

    // if(search(root, 30))
    //     printf("present\n");
    // else
    //     printf("absent\n");

    // inorder_predecessor(root, 35);
    // inorder_predecessor(root, 90);

    // inorder_sucessor(root, 100);
    // inorder_sucessor(root, 15);

    // root = deletion(root, 14);
    // inorder(root);
    // printf("\n");



    printf("%d\t%d\t%d\n",min_node(root), max_node(root), sum_of_nodes(root));
    return 0;
}