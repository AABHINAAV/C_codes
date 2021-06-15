/*
we use simple queue for bfs
coz it moves on radius
and keeps on increasing the radius
or we can say that firtly those nodes are visited that at distance 0 then those which are distance 1
then 2, 3, and so on
if we build a tree of those nodes in then we will be able to see that radius structure more clearly.



Advantages of BFS:-
1. Solution will definitely found out by BFS If there are some solution.
2. Never get trapped in unwanted nodes without the solution.
3. Finding Shortest path from Source to other vertices in an unweighted graph.

Disadvantages Of BFS :-
1. Memory Constraints As it stores all the nodes of present level to go for next level.
2. If solution is far away then it consumes time.

Application Of BFS :-
1. Finding Shortest Path.
2. Checking graph with bipertiteness.
3. Creating Bipartite Graphs.
4. Copying cheiney's Algorithm.
5. Finding quickest and efficient solution of a puzzle ( eg. Rubik’s cube) by applying BFS on the state space.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct queue
{
    int front;
    int back;
    int *arr;
} queue;

queue *enqueue(queue *q, int val)
{
    if (q->back == 99)
    {
        return q;
    }

    if (q->front == -1 && q->back == -1)
    {
        q->front = q->back = 0;
    }
    else
    {
        q->back++;
    }
    q->arr[q->back] = val;

    return q;
}

queue *dequeue(queue *q)
{
    if (q->front == -1 && q->back == -1)
    {
        return q;
    }
    else if (q->front == q->back)
    {
        q->front = q->back = -1;
    }
    else
    {
        q->front++;
    }
    return q;
}

int peek(queue *q)
{
    return q->arr[q->front];
}

int isEmpty(queue *q)
{
    if (q->front == -1 && q->back == -1)
        return 1;
    return 0;
}

typedef struct graph
{
    int v, e;
    int **mat;
} graph;

graph *create_graph(graph *head)
{
    int s, d;
    for (int i = 0; i < head->e; i++)
    {
        printf("enter the source and destination edge (-1 -1 for no more edges): ");
        scanf("%d %d", &s, &d);

        if (s == -1 || d == -1)
        {
            break;
        }
        else if (s > head->v || d > head->v || s < 0 || d < 0)
        {
            printf("invalid entey\n");
        }
        else
        {
            head->mat[s][d] = 1;
        }
    }
    return head;
}

void bfs_traversal(graph *head)
{
    // initial = 1
    // waiting = 2
    // visited = 3
    int states[head->v];
    for (int i = 0; i < head->v; i++)
        states[i] = 1;

    int s_point;
    printf("enter the starting vertex (press -1 for starting from random vertex): ");
    scanf("%d", &s_point);
    if (s_point == -1 || s_point >= head->v)
        s_point = 0;

    printf("\nBFS traversal is :- \n");
    queue *q = (queue *)malloc(sizeof(queue));
    q->front = -1;
    q->back = -1;
    q->arr = (int *)malloc(sizeof(int) * 100);

    q = enqueue(q, s_point);
    while (!isEmpty(q))
    {
        s_point = peek(q);
        states[s_point] = 3;
        q = dequeue(q);
        printf("%d  ", s_point);

        for (int i = 0; i < head->v; i++)
        {
            if (head->mat[s_point][i] == 1 && states[i] == 1)
            {
                q = enqueue(q, i);
                states[i] = 2;
            }
        }
    }
    printf("\n");
}

int main()
{
    graph *head = (graph *)malloc(sizeof(graph));
    printf("enter the number of vertices : ");
    scanf("%d", &head->v);

    head->e = head->v * (head->v - 1);

    head->mat = (int **)malloc(sizeof(int *) * head->v);
    for (int i = 0; i < head->v; i++)
    {
        head->mat[i] = (int *)malloc(sizeof(int) * head->v);
    }

    // graph creation using adjency matrix
    head = create_graph(head);

    // bfs traversal of graph
    bfs_traversal(head);

    return 0;
}

// enter the number of vertices : 9
// enter the source and destination edge (-1 -1 for no more edges): 0 1
// enter the source and destination edge (-1 -1 for no more edges): 0 4
// enter the source and destination edge (-1 -1 for no more edges): 0 3
// enter the source and destination edge (-1 -1 for no more edges): 1 2
// enter the source and destination edge (-1 -1 for no more edges): 1 4
// enter the source and destination edge (-1 -1 for no more edges): 2 5
// enter the source and destination edge (-1 -1 for no more edges): 3 4
// enter the source and destination edge (-1 -1 for no more edges): 3 6
// enter the source and destination edge (-1 -1 for no more edges): 4 6
// enter the source and destination edge (-1 -1 for no more edges): 4 7
// enter the source and destination edge (-1 -1 for no more edges): 4 5
// enter the source and destination edge (-1 -1 for no more edges): 5 7
// enter the source and destination edge (-1 -1 for no more edges): 6 7
// enter the source and destination edge (-1 -1 for no more edges): 7 8
// enter the source and destination edge (-1 -1 for no more edges): -1 -1
// enter the starting vertex : 0
// BSF traversal is :-
// 0  1  3  4  2  6  5  7  8