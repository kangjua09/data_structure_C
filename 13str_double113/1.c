/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MALLOC(p, s)                            \
    if (!((p) = malloc(s)))                     \
    {                                           \
        fprintf(stderr, "Insufficient memory"); \
        exit(EXIT_FAILURE);                     \
    }

typedef struct
{
    int data;
} element;

typedef struct Node *nodePointer;
typedef struct Node
{
    nodePointer llink;
    element data;
    nodePointer rlink;
};

void dinsert(nodePointer header, int data);
int search(nodePointer header, int data);
void ddelete(nodePointer header, int data);
void printList(nodePointer header);
void freeList(nodePointer header);

int main()
{
    int choice, data, index;
    char fname[100];
    FILE *file;
    nodePointer header, newNode;
    MALLOC(header, sizeof(struct node));
    header->data.data = -1;
    header->llink = header;
    header->rlink = header;

    while (1)
    {
        printf("작업 선택 (1.입력 2.추가 3.검색 4.삭제 5.종료) >> ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("file 이름 입력 >> ");
            scanf("%s", fname);
            file = fopen(fname, "r");
            if (file == NULL)
            {
                printf("fail\n");
                break;
            }
            while (fscanf(file, "%d", &data) != EOF)
            {
                dinsert(header, data);
            }
            fclose(file);
            printList(header);
            break;

        case 2:
            printf("데이터 입력 >> ");
            scanf("%d", &data);
            dinsert(header, data);
            printList(header);
            break;

        case 3:
            printf("검색 데이터 >> ");
            scanf("%d", &data);
            index = search(header, data);
            printf("%d\n", index);
            printList(header);
            break;

        case 4:
            printf("삭제 데이터 >> ");
            scanf("%d", &data);
            ddelete(header, data);
            printList(header);
            break;

        case 5:
            freeList(header);
            printf("프로그램을 종료합니다.\n");
            return 0;

        default:
            printf("오류. 1~5 사이의 숫자를 입력하세요.\n");
            break;
        }
    }

    return 0;
}

void dinsert(nodePointer header, int data)
{
    nodePointer newNode;
    MALLOC(newNode, sizeof(struct Node));
    newNode->data.data = data;
    nodePointer current = header->rlink;
    while (current != header && current->data.data < data)
    {
        current = current->rlink;
    }
    newNode->llink = current->llink;
    newNode->rlink = current;
    current->llink->rlink = newNode;
    current->llink = newNode;
}

int search(nodePointer header, int data)
{
    nodePointer current = header->rlink;
    int index = 1;

    while (current != header)
    {
        if (current->data.data == data)
        {
            return index;
        }
        if (current->data.data > data)
        {
            return 0;
        }
        current = current->rlink;
        index++;
    }
    return 0;
}

void printList(nodePointer header)
{
    nodePointer current = header->rlink;
    while (current != header)
    {
        printf("%d ", current->data.data);
        current = current->rlink;
    }
    printf("\n");
}

void ddelete(nodePointer header, int data)
{
    nodePointer current = header->rlink;
    while (current != header && current->data.data != data)
    {
        current = current->rlink;
    }
    if (current == header)
    {
        printf("invalid!\n");
        return;
    }
    current->llink->rlink = current->rlink;
    current->rlink->llink = current->llink;

    free(current);
}

void freeList(nodePointer header)
{
    nodePointer current = header->rlink;
    nodePointer temp;

    while (current != header)
    {
        temp = current;
        current = current->rlink;
        free(temp);
    }
    free(header);
}
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MALLOC(p, s)                            \
    if (!((p) = malloc(s)))                     \
    {                                           \
        fprintf(stderr, "Insufficient memory"); \
        exit(EXIT_FAILURE);                     \
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

void dinsert(nodePointer header, int data)
{
    nodePointer newNode;
    MALLOC(newNode, sizeof(struct node));
    newNode->data.data = data;
    nodePointer current = header->rlink;
    while (current != header && current->data.data < data)
    {
        current = current->rlink;
    }
    newNode->llink = current->llink;
    newNode->rlink = current;
    current->llink->rlink = newNode;
    current->llink = newNode;
}

void search(nodePointer header, int data)
{
    nodePointer current = header->rlink;
    int index = 1;

    while (current != header)
    {
        if (current->data.data == data)
        {
            return index;
        }
        if (current->data.data > data)
        {
            return 0;
        }
        current = current->rlink;
        index++;
    }
    return 0;
}

void ddelete(nodePointer node, nodePointer deleted)
{
    if (node == deleted)
        printf("Deletion of head node not permitted.\n");
    else
    {
        deleted->llink->rlink = deleted->rlink;
        deleted->rlink->llink = deleted->llink;
        free(deleted);
    }
}

int main()
{
    FILE *file;
    nodePointer header, newNode;
    MALLOC(header, sizeof(struct node));
    char fname[100];
    int n, data;
    header->data.data = -1;
    header->llink = header;
    header->rlink = header;

    while (1)
    {
        printf("작업 선택(1.입력 2.추가 3.검색 4.삭제 5.종료) >> ");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            printf("file 이름 입력 >> ");
            scanf("%s", fname);
            file = fopen("in.txt", "r");
            if (file == NULL)
            {
                fprintf(stderr, "file error\n");
            }
            while (fscanf(file, "%d", &data) != EOF)
            {
                dinsert(header, newNode);
            }

        case 2:
            printf("데이터 입력 >> ");
            scanf("%d", &data);
            dinsert(header, data);
            printList(header);
            break;

        case 3:
            printf("검색 테이터 >> ");
            scanf("%d", data);
            dinsert(header, data);
            printList(header);
            break;

        case 4:
            printf("삭제 데이터 >> ");
            scanf("%d", data);
            dinsert(header, data);
            printList(header);
            break;

        default:
            printf("오류. 1~5 사이의 숫자를 입력하세요.\n");
            break;
        }
    }
    return 0;
}