#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MALLOC(p, s)                         \
    if (!((p) = malloc(s)))                  \
    {                                        \
        fprintf(stderr, "메모리할당실패\n"); \
        exit(EXIT_FAILURE);                  \
    }

typedef struct node *nodePointer;
typedef struct node
{
    nodePointer llink;
    int data;
    nodePointer rlink;
} Node;

nodePointer createheader()
{
    nodePointer header;
    MALLOC(header, sizeof(Node));
    header->rlink = header;
    header->llink = header;
    return header;
}

void dinsert(nodePointer node, nodePointer newnode)
{
    newnode->llink = node;
    newnode->rlink = node->rlink;
    node->rlink->llink = newnode;
    node->rlink = newnode;
}

void printList(nodePointer header)
{
    nodePointer current = header->rlink;
    while (current != header)
    {
        printf("%d ", current->data);
        current = current->rlink;
    }
    printf("\n");
}

nodePointer copyReverse(nodePointer originalList)
{
    nodePointer newlist = createheader();
    nodePointer cursor = originalList->llink;
    nodePointer newnode;
    while (cursor != originalList)
    {
        MALLOC(newnode, sizeof(Node));
        newnode->data = cursor->data;
        dinsert(newlist->llink, newnode);
        cursor = cursor->llink;
    }
    return newlist;
}

int main()
{
    int n;
    nodePointer newnode;
    nodePointer list1 = createheader();
    nodePointer list2;

    FILE *file = fopen("in3.txt", "r");
    if (file == NULL)
    {
        printf("fail\n");
        return 1;
    }
    // O(n) 생성을 위해 항상 리스트의 맨 끝(list1->llink) 뒤에 삽입
    while (fscanf(file, "%d", &n) == 1)
    {
        MALLOC(newnode, sizeof(Node));
        newnode->data = n;
        dinsert(list1->llink, newnode);
    }
    printList(list1);
    list2 = copyReverse(list1);
    printList(list2);

    fclose(file);
    return 0;
}