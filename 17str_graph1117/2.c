/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 11
#define TRUE 1
#define FALSE 0

typedef struct node *nodePointer;
typedef struct node
{
    int vertex;
    nodePointer link;
} node;

nodePointer graph[MAX_VERTICES];
short int visited[MAX_VERTICES];

void insert(int v1, int v2)
{
    nodePointer newNode = (nodePointer)malloc(sizeof(node));
    newNode->vertex = v2;
    newNode->link = graph[v1];
    graph[v1] = newNode;
}

void dfs(int v)
{
    nodePointer w;
    visited[v] = TRUE;
    printf("%5d", v);
    for (w = graph[v]; w; w = w->link)
        if (!visited[w->vertex])
            dfs(w->vertex);
}

int main()
{
    FILE *file = fopen("in1.txt", "r");
    if (!file)
        return 1;

    int n, edge;
    fscanf(file, "%d", &n);

    for (int i = 1; i <= n; i++)
    {
        graph[i] = NULL;
        visited[i] = FALSE;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            fscanf(file, "%d", &edge);
            if (edge == 1)
            {
                insert(i, j);
                insert(j, i);
            }
        }
    }

    int startNode;
    scanf("%d", &startNode);

    dfs(startNode);
    printf("\n");

    fclose(file);
    return 0;
}
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTEX 11
#define TRUE 1
#define FALSE 0