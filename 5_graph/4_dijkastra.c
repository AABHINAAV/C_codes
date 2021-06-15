/*
Dijkstra’s algorithm is one of the SSSP (Single Source Shortest Path) algorithms. 
Therefore, it calculates the shortest path from a source node to all the nodes inside the graph.

# Advantages:-
1) It is used in Google Maps
2) It is used in finding Shortest Path.
3) It is used in geographical Maps
4) To find locations of Map which refers to vertices of graph.
5) Distance between the location refers to edges.
6) It is used in IP routing to find Open shortest Path First.
7) It is used in the telephone network.

# Disadvantages:-
1) It do blind search so wastes lot of time while processing.
2) It cannot handle negative edges.
3) This leads to acyclic graphs and most often cannot obtain the right shortest path.
*/

#include <stdlib.h>
#include <stdio.h>
#define INF 99999

typedef struct pq
{
    int val;
    int dist;
    struct pq *next;
} pq;

pq *createNode(int val, int dist)
{
    pq *newnode = (pq *)malloc(sizeof(pq));
    newnode->val = val;
    newnode->dist = dist;
    newnode->next = NULL;
    return newnode;
}

pq *push(pq *q, int val, int dist)
{
    pq *newnode = createNode(val, dist);
    if (q == NULL)
        return newnode;
    else if (dist <= q->dist)
    {
        newnode->next = q;
        q = newnode;
    }
    else
    {
        pq *cur = q;
        while (cur && cur->next)
        {
            if (cur->dist <= dist && cur->next->dist >= dist)
                break;
            cur = cur->next;
        }
        pq *temp = cur->next;
        cur->next = newnode;
        newnode->next = temp;
    }
    return q;
}

pq *pop(pq *q)
{
    pq *temp = q;
    q = q->next;
    free(temp);
    return q;
}

int isEmpty(pq *q)
{
    if (q == NULL)
        return 1;
    return 0;
}

typedef struct graph
{
    int v, e;
    int **mat;
} graph;

graph *create_graph(graph *g)
{
    printf("enter the number of vertices : ");
    scanf("%d", &g->v);
    printf("enter the number of edges : ");
    scanf("%d", &g->e);

    // generating matrix dynamically
    g->mat = (int **)malloc(sizeof(int *) * g->v);
    for (int i = 0; i < g->v; i++)
        g->mat[i] = (int *)malloc(sizeof(int) * g->v);

    // setting all node connection values to -1
    // to show they are not connected
    for (int i = 0; i < g->v; i++)
        for (int j = 0; j < g->v; j++)
            g->mat[i][j] = INF;

    int s, d, val;
    for (int i = 0; i < g->e; i++)
    {
        printf("enter source and destination vertex : ");
        scanf("%d %d", &s, &d);
        if (s < 0 || d < 0 || s > g->v || d > g->v)
        {
            printf("invalid entry..... enter it again\n");
            i--;
            continue;
        }
        printf("enter the edge cost : ");
        scanf("%d", &val);
        g->mat[s][d] = val;
        g->mat[d][s] = val;
    }
    return g;
}

void dijkastra(graph *g)
{
    // unvisited 0
    // visited 1
    int states[g->v];
    for (int i = 0; i < g->v; i++)
        states[i] = 0;

    int s_point;
    printf("enter the staring vertex (press -1 for random selection) : ");
    scanf("%d", &s_point);
    if (s_point < 0 || s_point >= g->v)
        s_point = 0;
    printf("So the starting vertex is : %d\n", s_point);
    int dist = 0;

    pq *q = (pq *)malloc(sizeof(pq));
    q = push(q, s_point, dist);

    while (!isEmpty(q))
    {
        s_point = q->val;
        dist = q->dist;
        q = pop(q);

        if (states[s_point] == 1)
        {
            continue;
        }
        states[s_point] = 1;
        printf("%d : %d\n", s_point, dist);

        for (int i = 0; i < g->v; i++)
        {
            if (g->mat[s_point][i] != INF && states[i] == 0)
            {
                q = push(q, i, g->mat[s_point][i] + dist);
            }
        }
    }
}

int main()
{
    graph *g = (graph *)malloc(sizeof(graph));
    g = create_graph(g);
    dijkastra(g);
    return 0;
}