#include <stdlib.h>
#include <stdio.h>

typedef struct TrieNode
{
    char val;
    int count;
    int endsHere;
    struct TireNode *child[26];
} tn;

tn *create_node(int index)
{
    tn *node = (tn *)malloc(sizeof(tn));
    node->val = 'a' + index;
    node->count = node->endsHere = 0;
    for (int i = 0; i < 26; i++)
        node->child[i] = NULL;
    return node;
}

tn *insert_word(tn *root, char word[])
{
    tn *cur = root;
    int index;
    for (int i = 0; word[i] != '\0'; i++)
    {
        index = word[i] - 'a';
        if (cur->child[index] == NULL)
            cur->child[index] = create_node(index);
        cur = cur->child[index];
        cur->count += 1;
    }
    cur->endsHere = 1;
    return root;
}

void search_word(tn *root, char word[])
{
    int index;
    for (int i = 0; word[i] != '\0'; i++)
    {
        index = word[i] - 'a';
        if (root->child[index] == NULL)
            break;
        root = root->child[index];
    }
    if (root->endsHere)
        printf("word is present\n\n");
    else
        printf("word is absent\n\n");
}

void check_if_prefix(tn *root, char word[])
{
    int index;
    for (int i = 0; word[i] != '\0'; i++)
    {
        index = word[i] - 'a';
        if(root->child[index] == NULL)
            break;
        root = root->child[index];
    }
    if (root->endsHere == 1)
        printf("it is not prefix\n\n");
    else
        printf("it is a prefix of %d words\n\n", root->count);
}

int main()
{
    tn *root = create_node('/' - 'a');
    root = insert_word(root, "apple");
    root = insert_word(root, "add");
    root = insert_word(root, "beer");
    root = insert_word(root, "bear");
    root = insert_word(root, "bearer");
    search_word(root, "app");
    search_word(root, "apple");
    check_if_prefix(root, "bear");
    check_if_prefix(root, "bea");

    return 0;
}