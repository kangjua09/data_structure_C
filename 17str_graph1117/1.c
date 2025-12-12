/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 11

typedef struct node *nodePointer;
typedef struct node
{
    int vertex;
    nodePointer link;
} node;

nodePointer graph[MAX_VERTICES];

void insert(int v1, int v2)
{
    nodePointer newNode = (nodePointer)malloc(sizeof(node));
    newNode->vertex = v2;
    newNode->link = graph[v1];
    graph[v1] = newNode;
}

void printList(int n)
{
    for (int i = 1; i <= n; i++)
    {
        printf("Vertex %d: ", i);
        nodePointer current = graph[i];
        while (current)
        {
            printf("%d ", current->vertex);
            current = current->link;
        }
        printf("\n");
    }
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

    printList(n);

    fclose(file);
    return 0;
}
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 11

typedef struct node *nodePointer;
typedef struct node
{
    int vertex;
    nodePointer link;
} node;

nodePointer graph[MAX_VERTICES];

void insert(int v1, int v2)
{
    nodePointer newNode = (nodePointer)malloc(sizeof(node));
    newNode->vertex = v1;
    newNode->link = graph[v2];
    graph[v2] = newNode;
}

void printGraph(int n)
{
    for (int i = 1; i <= n; i++)
    {
        printf("Vertex %d: ", i);
        nodePointer curr = graph[i];
        while (curr != NULL)
        {
            printf("%d ", curr->vertex);
            curr = curr->link;
        }
        printf("\n");
    }
}

int main()
{
    FILE *file = fopen("in.txt", "r");
    if (file == NULL)
    {
        printf("파일을 열 수 없습니다.\n");
        return 1;
    }
    int n, v;
    fscanf(file, "%d", &n);
    for (int i = 1; i < n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (fscanf(file, "%d", &v) != 1)
                break;
            if (v == 1)
            {
                insert(i, j);
                insert(j, i);
            }
        }
    }
    printGraph(n);
    fclose(file);
    return 0;
}