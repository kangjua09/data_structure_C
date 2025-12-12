#include <stdio.h>
#define MAX 100

int n;
int graph[MAX][MAX];
int visited[MAX];

void dfs(int v)
{
    int w;
    visited[v] = 1;
    for (w = 0; w < n; w++)
        if (graph[v][w] && !visited[w])
            dfs(w);
}

int main()
{
    int i, j;
    FILE *file = fopen("in21.txt", "r");
    fscanf(file, "%d", &n);

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            graph[i][j] = 0;

    for (i = 0; i < n; i++)
        for (j = i + 1; j < n; j++)
        {
            fscanf(file, "%d", &graph[i][j]);
            graph[j][i] = graph[i][j];
        }

    int count = 0;
    for (i = 0; i < n; i++)
        visited[i] = 0;

    for (i = 0; i < n; i++)
        if (!visited[i])
        {
            dfs(i);
            count++;
        }

    printf("%d\n", count);
}