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
void delete(listPointer *first, listPointer trail, listPointer x);

int main()
{
    listPointer first = NULL;
    listPointer last = NULL;
    int num, n;

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

    while (1)
    {
        scanf("%d", &n);
        if (n == -1)
        {
            break;
        }

        listPointer trail = NULL;
        listPointer x = first;

        while (x != NULL && x->data != n)
        {
            trail = x;   // trail은 현재 노드가 되고
            x = x->next; // x는 다음 노드로 이동
        }
        if (x == NULL)
        {
            printf("값을 못 찾음");
        }
        else
        {
            delete(&first, trail, x);
            printList(first);
        }
    }

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

void delete(listPointer *first, listPointer trail, listPointer x)
{
    if (trail)
    {
        trail->next = x->next;
    }
    else
    {
        *first = (*first)->next;
    }
    free(x);
}
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct listNode *listPointer;
typedef struct listNode
{
    int data;
    listPointer link;
};