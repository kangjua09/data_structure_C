#include <stdio.h>
#define MAX 100

int n;
int graph[MAX][MAX];
int visited[MAX];

void dfs(int v)
{
    int w;
    visited[v] = 1;
    printf("%d ", v);
    for (w = 0; w < n; w++)
        if (graph[v][w] && !visited[w])
            dfs(w);
}

int queue[MAX];
int front = 0, rear = 0;

void addq(int v)
{
    queue[rear++] = v;
}
int deleteq()
{
    return queue[front++];
}

void bfs(int v)
{
    int w;
    front = rear = 0;
    printf("%d ", v);
    visited[v] = 1;
    addq(v);
    while (front < rear)
    {
        v = deleteq();
        for (w = 0; w < n; w++)
            if (graph[v][w] && !visited[w])
            {
                printf("%d ", w);
                addq(w);
                visited[w] = 1;
            }
    }
}

int main()
{
    int i, j;
    FILE *file = fopen("in1.txt", "r");
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

    int v;
    while (scanf("%d", &v) != EOF)
    {
        for (i = 0; i < n; i++)
            visited[i] = 0;
        printf("BFS(%d): ", v);
        bfs(v);
        printf("\n");

        for (i = 0; i < n; i++)
            visited[i] = 0;
        printf("DFS(%d): ", v);
        dfs(v);
        printf("\n");
    }
}