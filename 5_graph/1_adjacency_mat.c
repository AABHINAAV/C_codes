#include<stdio.h>
#include<stdlib.h>
typedef struct Graph
{
    int n_V;
    int n_E;
    int **mat;
}Graph;
Graph *createGraph(Graph *head)
{
    printf("enter the number of vertices : ");
    scanf("%d",&head->n_V);
    printf("enter the number of edges : ");
    scanf("%d",&head->n_E);
    
    head->mat = (int **)malloc(sizeof(int *)*head->n_V);
    int i,j;
    for(i=0; i<head->n_V; i++)
        head->mat[i] = (int *)malloc(sizeof(int) * head->n_V);
    for(i=0; i<head->n_V; i++)
    {
        for(j=0; j<head->n_V; j++)
        {
            head->mat[i][j] = 0;
        }
    }

    int x,y;
    printf("enter node numbers in pair that connect an edge:-\n");
    for(i=0; i<head->n_E; i++)
    {
        scanf("%d %d",&x,&y);
        head->mat[x][y] = 1;
        head->mat[y][x] = 1;
    }
    return head;
}
void printGraph(Graph *head)
{
    for(int i=0; i<head->n_V; i++)
    {
        for(int j=0; j<head->n_V; j++)
        {
            printf("%d\t",head->mat[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    Graph *head = (Graph *)malloc(sizeof(Graph));
    head = createGraph(head);
    printGraph(head);
    return 0;
}