// 2023015950 - Ȳ����

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 2

typedef struct Node
{
    int vertex;
    struct Node *next;
} Node;

typedef struct Graph
{
    int numVertices;
    Node **adjLists;
} Graph;

Node *createNode(int v);
Graph *createGraph(int vertices);
void addEdge(Graph *graph, int src, int dest);
void printGraph(Graph *graph);
void DFS(Graph *graph, int startVertex, int *visited);

int main()
{
    FILE *fp = fopen("in3.txt", "r");

    int vertices;
    fscanf(fp, "%d", &vertices);

    Graph *graph = createGraph(vertices);
    int **matrix = (int **)malloc(sizeof(int *) * vertices);
    for (int i = 0; i < vertices; i++)
    {
        matrix[i] = (int *)malloc(sizeof(int) * vertices);
    }
    for (int i = 0; i < vertices; i++)
    {
        for (int j = i + 1; j < vertices; j++)
        {
            int edge;
            fscanf(fp, "%d", &edge);
            matrix[i][j] = edge;
            matrix[j][i] = edge;
            if (edge == 1)
            {
                addEdge(graph, i, j);
            }
        }
    }
    for (int i = 0; i < vertices; i++)
    {
        matrix[i][i] = 0;
    }
    fclose(fp);

    printf("Adjacency Matrix:\n");
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    printf("\nVertex & Edge List:\n");
    printGraph(graph);
    printf("\n");

    int startVertex;
    scanf("%d", &startVertex);
    startVertex--;
    int *visited = malloc(vertices * sizeof(int));
    for (int i = 0; i < vertices; i++)
    {
        visited[i] = 0;
    }

    printf("DFS (%d): ", startVertex + 1);
    DFS(graph, startVertex, visited);
}

Node *createNode(int v)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

Graph *createGraph(int vertices)
{
    Graph *graph = malloc(sizeof(Graph));
    graph->numVertices = vertices;

    graph->adjLists = malloc(vertices * sizeof(Node *));
    for (int i = 0; i < vertices; i++)
    {
        graph->adjLists[i] = NULL;
    }
    return graph;
}

void addEdge(Graph *graph, int src, int dest)
{
    Node *temp = graph->adjLists[src];
    while (temp)
    {
        if (temp->vertex == dest)
            return;
        temp = temp->next;
    }

    Node *newNode = createNode(dest);
    if (graph->adjLists[src] == NULL)
    {
        graph->adjLists[src] = newNode;
    }
    else
    {
        Node *last = graph->adjLists[src];
        while (last->next != NULL)
        {
            last = last->next;
        }
        last->next = newNode;
    }

    temp = graph->adjLists[dest];

    while (temp)
    {
        if (temp->vertex == src)
            return;
        temp = temp->next;
    }
    newNode = createNode(src);
    if (graph->adjLists[dest] == NULL)
    {
        graph->adjLists[dest] = newNode;
    }
    else
    {
        Node *last = graph->adjLists[dest];
        while (last->next != NULL)
        {
            last = last->next;
        }
        last->next = newNode;
    }
}

void printGraph(Graph *graph)
{
    for (int v = 0; v < graph->numVertices; v++)
    {
        Node *temp = graph->adjLists[v];
        printf("Vertex %d: ", v + 1);
        while (temp)
        {
            printf("%d ", temp->vertex + 1);
            temp = temp->next;
        }
        printf("\n");
    }
}

void DFS(Graph *graph, int startVertex, int *visited)
{
    visited[startVertex] = 1;
    printf("%d ", startVertex + 1);

    Node *adjList = graph->adjLists[startVertex];
    Node *temp = adjList;

    while (temp != NULL)
    {
        int connectedVertex = temp->vertex;

        if (!visited[connectedVertex])
        {
            DFS(graph, connectedVertex, visited);
        }
        temp = temp->next;
    }
}