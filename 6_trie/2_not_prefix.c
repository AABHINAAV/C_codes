// print all the word that are not prefix of any other word
#include <stdio.h>
#include <stdlib.h>

typedef struct TrieNode
{
    char val;
    int endsHere;
    struct TrieNode *child[26];
} tn;

tn *create_node(int index)
{
    tn *node = (tn *)malloc(sizeof(tn));
    node->val = 'a' + index;
    node->endsHere = 0;
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
        cur->endsHere = 0;
        cur = cur->child[index];
    }
    for (int i = 0; i < 26; i++)
        if (cur->child[i] != NULL)
            return root;
    cur->endsHere = 1;
    return root;
}

void main_func(tn *root, char res[], int level)
{
    if (root->endsHere)
    {
        res[level] = '\0';
        printf("%s\n", res);
    }
    for (int i = 0; i < 26; i++)
    {
        if (root->child[i])
        {
            res[level] = root->child[i]->val;
            main_func(root->child[i], res, level + 1);
        }
    }
}

void words_not_prefix(tn *root)
{
    char res[1000];
    int level = 0;
    main_func(root, res, level);
}

int main()
{
    tn *root = create_node('/' - 'a');
    root = insert_word(root, "apple");
    root = insert_word(root, "app");
    root = insert_word(root, "there");
    root = insert_word(root, "the");
    words_not_prefix(root);
    return 0;
}