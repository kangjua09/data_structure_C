/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct listNode *listPointer;
typedef struct listNode
{
    int data;
    listPointer next;
};

void printList(listPointer first);

int main()
{
    listPointer first = NULL;
    listPointer last = NULL;
    int num;

    FILE *file = fopen("in1.txt", "r");
    if (file == NULL)
    {
        printf("파일열기싫패\n");
        exit(1);
    }

    while (fscanf(file, "%d", &num) != EOF)
    {
        listPointer newNode = (listPointer)malloc(sizeof(struct listNode));
        if (newNode == NULL)
        {
            printf("메모리 할당 실패\n");
            exit(1);
        }
        newNode->data = num;
        newNode->next = NULL;

        // 리스트에 새로운 노드 연결
        if (first == NULL) // 리스트가 비어있을 경우
        {
            first = newNode;
            last = newNode;
        }
        else // 리스트에 노드가 이미 있을 경우
        {
            last->next = newNode; // 마지막 노드의 next가 새 노드를 가리키게 함
            last = newNode;       // last 포인터를 새 노드로 업데이트
        }
    }

    printList(first);
    fclose(file);
    return 0;
}

void printList(listPointer first)
{
    for (listPointer temp = first; temp != NULL; temp = temp->next)
    {
        printf("%d ", temp->data);
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

void printList(listPointer first);

int main()
{
    listPointer first = NULL;
    listPointer last = NULL;
    int n;

    FILE *file = fopen("in1.txt", "r");
    if (file == NULL)
    {
        printf("파일열기싫패\n");
        exit(1);
    }

    while (scanf(file, "%d", &n) != EOF)
    {
        listPointer newNode = (listPointer)malloc(sizeof(struct listNode));
        if (newNode == NULL)
        {
            printf("fail\n");
            exit(1);
        }
        newNode->data = n;
        newNode->link = NULL;
        if (first == NULL)
        {
            first = newNode;
            last = newNode;
        }
        else
        {
            last->link = newNode;
            last = newNode;
        }
    }
    printList(first);
    fclose(file);
    return 0;
}

void printList(listPointer first)
{
    for (; first; first = first->link)
    {
        printf("%d ", first->data);
    }
    printf("\n");
}