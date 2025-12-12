/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct listNode *listPointer;
typedef struct listNode
{
    int data;
    struct listNode *next;
};

void insert(listPointer *first, int data);
void printList(listPointer first);

int main()
{
    listPointer first = NULL;
    int n;

    FILE *file = fopen("in1.txt", "r");
    if (file == NULL)
    {
        printf("Failed to open file.\n");
        exit(1);
    }

    while (fscanf(file, "%d", &n) != EOF)
    {
        insert(&first, n);
    }

    printList(first);
    fclose(file);
    return 0;
}

void insert(listPointer *first, int data)
{
    listPointer newNode = (listPointer)malloc(sizeof(struct listNode));
    newNode->data = data;
    newNode->next = *first;
    *first = newNode;
}

void printList(listPointer first)
{
    listPointer temp = first;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MALLOC(p, s)                \
    if (!((p) = malloc(s)))         \
    {                               \
        fprintf(stderr, "errer\n"); \
        exit(EXIT_FAILURE);         \
    }

typedef struct listNode *listPointer;
typedef struct listNode
{
    int data;
    listPointer link;
};

void insert(listPointer *first, int data);
void printList(listPointer first);

int main()
{
    listPointer first = NULL;
    int n;

    FILE *file = fopen("in1.txt", "r");
    if (file == NULL)
    {
        printf("fail\n");
        exit(1);
    }

    while (fscanf(file, "%d", &n) != EOF)
    {
        insert(&first, n);
    }
    printList(first);
    fclose(file);
    return 0;
}

void insert(listPointer *first, int data)
{
    listPointer temp;
    MALLOC(temp, sizeof(*temp));
    temp->data = data;
    temp->link = *first;
    *first = temp;
}

void printList(listPointer first)
{
    printf("The list contains: ");
    for (; first; first = first->link)
    {
        printf("%4d", first->data);
    }
    printf("\n");
}