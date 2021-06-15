#include<stdlib.h>
#include<stdio.h>

typedef struct listNode
{
    int val;
    struct listNode *next;
}listNode;

listNode *createNode(int val)
{
    listNode *newnode = (listNode *)malloc(sizeof(listNode));
    newnode->val = val;
    newnode->next = NULL;
    return newnode;
}

typedef struct graph
{
    int v;
    int e;
    listNode *mat;
}graph;

graph *create_graph(graph *g)
{
    printf("enter the number of vertices : ");
    scanf("%d", &g->v);
    printf("enter the number of edges : ");
    scanf("%d", &g->e);

    // create matrix of initial list nodes of ll
    g->mat = (listNode *)malloc(sizeof(listNode) * g->v);
    for(int i=0; i<g->v; i++)
    {
        (g->mat + i)->val = i+1;
        (g->mat + i)->next = NULL;
    }

    int s,d;
    listNode *cur;
    for(int i=0; i<g->e; i++)
    {
        printf("enter the source and destination matrix for edge %d : ", i+1);
        scanf("%d %d", &s, &d);

        cur = g->mat + s-1;
        while(cur->next != NULL)
            cur = cur->next;
        cur->next = createNode(d);

        // uncomment it for an undirected graph
        // cur = g->mat + d-1;
        // while(cur->next)
        //     cur = cur->next;
        // cur->next = createNode(s);
    }

    return g;
}

void show_adjacency_list(graph *g)
{
    listNode *cur;
    for(int i=0; i<g->v; i++)
    {
        cur = g->mat + i;
        printf("all connect node from %d are : ",cur->val);
        cur = cur->next;
        while(cur)
        {
            printf("%d  ", cur->val);
            cur = cur->next;
        }
        printf("\n");
    }
}

int main()
{
    graph *g = (graph *)malloc(sizeof(graph));
    g = create_graph(g);
    show_adjacency_list(g);
    return 0;
}



// undirected graph
// enter the number of vertices : 4 
// enter the number of edges : 5
// enter the source and destination matrix for edge 1 : 1 2
// enter the source and destination matrix for edge 2 : 1 3
// enter the source and destination matrix for edge 3 : 1 4
// enter the source and destination matrix for edge 4 : 2 4
// enter the source and destination matrix for edge 5 : 3 4
// all connect node from 1 are : 2  3  4  
// all connect node from 2 are : 1  4  
// all connect node from 3 are : 1  4  
// all connect node from 4 are : 1  2  3  

// directed graph
// enter the number of vertices : 4  
// enter the number of edges : 5
// enter the source and destination matrix for edge 1 : 1 2
// enter the source and destination matrix for edge 2 : 1 3
// enter the source and destination matrix for edge 3 : 1 4
// enter the source and destination matrix for edge 4 : 2 4
// enter the source and destination matrix for edge 5 : 3 4
// all connect node from 1 are : 2  3  4  
// all connect node from 2 are : 4  
// all connect node from 3 are : 4  
// all connect node from 4 are : 