/*
The Floyd-Warshall algorithm helps in determining all the shortest paths in a graph with positive or negative weight edges. 
The Floyd-Warshall algorithm or Floyd's algorithm is an example of dynamic programming. 
It is also known as Roy-Warshall algorithm, the WFI algorithm or the Roy-Floyd algorithm.


# Advantages 
1. It helps to find the shortest path in a weighted graph with positive or negative edge weights.
2. A single execution of the algorithm is sufficient to find the lengths of the shortest paths between all pairs of vertices.
3. It is easy to modify the algorithm and use it to reconstruct the paths.
4. Versions of the algorithm can be used for finding the widest paths between all pairs of vertices in a weighted graph or 
transitive closure of a relation R.


# Disadvantages 
1. It can find the shortest path only when there are no negative cycles.
2. It does not return the details of the paths. 
*/
#include <stdlib.h>
#include <stdio.h>
#define INF 9999
typedef struct Graph
{
    int V, E;
    int **mat;
} Graph;

void printGraph(Graph *head)
{
    for (int i = 0; i < head->V; i++)
    {
        for (int j = 0; j < head->V; j++)
        {
            // printf("%d\t",head->mat[i][j]);
            if (head->mat[i][j] == INF)
                printf("%7s", "INF");
            else
                printf("%7d", head->mat[i][j]);
        }
        printf("\n");
    }
}

void floydWarshall(Graph *head)
{
    int i,j,k;

    int new_dist;
    for(k=0; k<head->V; k++)
    {
        for(i=0; i<head->V; i++)
        {
            for(j=0; j<head->V; j++)
            {
                new_dist = head->mat[i][k] + head->mat[k][j];
                if(new_dist < head->mat[i][j])
                    head->mat[i][j] = new_dist;
            }
        }
    }

    printf("\n\nprinting shortest paths :-\n");
    printGraph(head);
}

int main()
{
    int graph[4][4] = {{0, 5, INF, 10},
                       {INF, 0, 3, INF},
                       {INF, INF, 0, 1},
                       {INF, INF, INF, 0}};

    Graph *head = (Graph *)malloc(sizeof(Graph));

    head->V = 4;
    head->E = 4;

    head->mat = malloc(sizeof(int *) * head->V);
    for (int i = 0; i < head->V; i++)
    {
        head->mat[i] = (int *)malloc(sizeof(int) * head->V);
    }

    for (int i = 0; i < head->V; i++)
    {
        for (int j = 0; j < head->V; j++)
        {
            head->mat[i][j] = graph[i][j];
        }
    }

    printf("original matrix :-\n");
    printGraph(head);
    floydWarshall(head);
}