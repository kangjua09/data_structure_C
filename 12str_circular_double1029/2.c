/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MALLOC(p, s)                         \
    if (!((p) = malloc(s)))                  \
    {                                        \
        fprintf(stderr, "메모리할당실패\n"); \
        exit(EXIT_FAILURE);                  \
    }

typedef struct
{
    int data;
} element;

typedef struct node *nodePointer;
typedef struct node
{
    nodePointer llink;
    element data;
    nodePointer rlink;
};

void dinsert(nodePointer header, nodePointer newnode);
void printForward(nodePointer header);
void printBackward(nodePointer header);

int main()
{
    element n;
    nodePointer header, newNode;

    MALLOC(header, sizeof(struct node));
    header->llink = header;
    header->rlink = header;

    FILE *file = fopen("in.txt", "r");
    if (file == NULL)
    {
        fprintf(stderr, "file open fail.\n");
        exit(1);
    }

    while (fscanf(file, "%d", &n) == 1)
    {
        MALLOC(newNode, sizeof(struct node));
        newNode->data = n;
        dinsert(header, newNode);
    }

    printForward(header);
    printBackward(header);

    fclose(file);
    return 0;
}

void dinsert(nodePointer header, nodePointer newnode)
{
    newnode->llink = header;
    newnode->rlink = header->rlink;
    header->rlink->llink = newnode;
    header->rlink = newnode;
}

void printForward(nodePointer header)
{
    nodePointer current = header->rlink;
    while (current != header)
    {
        printf("%d ", current->data);
        current = current->rlink;
    }
    printf("\n");
}

void printBackward(nodePointer header)
{
    nodePointer current = header->llink;
    while (current != header)
    {
        printf("%d ", current->data);
        current = current->llink;
    }
    printf("\n");
}
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MALLOC(p, s)                         \
    if (!((p) = malloc(s)))                  \
    {                                        \
        fprintf(stderr, "메모리할당실패\n"); \
        exit(EXIT_FAILURE);                  \
    }

typedef struct
{
    int data;
} element;

typedef struct node *nodePointer;
typedef struct node
{
    nodePointer llink;
    element data;
    nodePointer rlink;
};

void printForward(nodePointer header);
void printBackward(nodePointer header);

void dinsert(nodePointer header, nodePointer newnode)
{
    nodePointer current = header->rlink;
    while (current != header && current->data.data < newnode->data.data)
    {
        current = current->rlink;
    }
    newnode->llink = current->llink;
    newnode->rlink = current;
    current->llink->rlink = newnode;
    current->llink = newnode;
}

int main()
{
    element n;
    nodePointer newNode, header;
    MALLOC(header, sizeof(struct node));
    header->llink = header;
    header->rlink = header;

    FILE *file = fopen("in.txt", "r");
    if (file == NULL)
    {
        printf("fail\n");
        return 1;
    }
    while (fscanf(file, "%d", &n.data) == 1)
    {
        MALLOC(newNode, sizeof(struct node));
        newNode->data = n;
        dinsert(header, newNode);
    }
    printForward(header);
    printBackward(header);

    free(header);
    fclose(file);
    return 0;
}

void printForward(nodePointer header)
{
    nodePointer current = header->rlink;
    while (current != header)
    {
        printf("%d ", current->data.data);
        current = current->rlink;
    }
    printf("\n");
}

void printBackward(nodePointer header)
{
    nodePointer current = header->llink;
    while (current != header)
    {
        printf("%d ", current->data.data);
        current = current->llink;
    }
    printf("\n");
}