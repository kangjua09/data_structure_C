#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 50
#define MALLOC(p, s)                         \
    if (!((p) = malloc(s)))                  \
    {                                        \
        fprintf(stderr, "메모리할당실패\n"); \
        exit(EXIT_FAILURE);                  \
    }

typedef enum
{
    head,
    entry
} tagfield;

typedef struct matrixNode *matrixPointer;
struct entryNode
{
    int row;
    int col;
    int value;
};

struct matrixNode
{
    matrixPointer down;
    matrixPointer right;
    tagfield tag;
    union
    {
        matrixPointer next;
        struct entryNode entry;
    } u;
};
matrixPointer hdnode[MAX_SIZE];

matrixPointer mread();
void mwrite(matrixPointer node);
void merase(matrixPointer *node);

matrixPointer newNode()
{
    matrixPointer temp;
    MALLOC(temp, sizeof(struct matrixNode));
    return temp;
}

int main()
{
    int choice = 0;
    matrixPointer matrix = NULL;

    while (1)
    {
        printf("\nmatrix 작업 선택 (1.입력 2.출력 3.삭제 4.종료): ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            if (matrix != NULL)
            {
                printf("기존 행렬을 삭제합니다.\n");
                merase(&matrix);
            }
            matrix = mread();
            printf("입력이 완료되었습니다.\n");
            break;

        case 2:
            if (matrix == NULL)
            {
                printf("출력할 데이터가 없습니다. 먼저 입력하세요.\n");
            }
            else
            {
                mwrite(matrix);
            }
            break;

        case 3:
            if (matrix == NULL)
            {
                printf("삭제할 데이터가 없습니다.\n");
            }
            else
            {
                merase(&matrix);
                printf("행렬이 삭제되었습니다.\n");
            }
            break;

        case 4:
            if (matrix != NULL)
            {
                merase(&matrix);
            }
            printf("프로그램을 종료합니다.\n");
            return 0;

        default:
            printf("오류. 1~4 사이의 숫자를 입력하세요.\n");
            break;
        }
    }

    return 0;
}

matrixPointer mread()
{
    int numRows, numCols, numTerms, numHeads, i;
    int row, col, value, currentRow;
    matrixPointer temp, last, node;

    printf("Enter the number of rows, columns, and number of nonzero terms: ");
    scanf("%d%d%d", &numRows, &numCols, &numTerms);

    numHeads = (numCols > numRows) ? numCols : numRows;
    node = newNode();

    node->tag = entry;
    node->u.entry.row = numRows;
    node->u.entry.col = numCols;
    if (!numHeads)
        node->right = node;
    else
    {
        for (i = 0; i < numHeads; i++)
        {
            temp = newNode();
            hdnode[i] = temp;
            hdnode[i]->tag = head;
            hdnode[i]->right = temp;
            hdnode[i]->u.next = temp;
        }
    }
    currentRow = 0;
    last = hdnode[0];
    for (i = 0; i < numTerms; i++)
    {
        printf("Enter row, column and value: ");
        scanf("%d%d%d", &row, &col, &value);

        if (row > currentRow)
        {
            last->right = hdnode[currentRow];
            currentRow = row;
            last = hdnode[row];
        }
        temp = newNode();
        temp->tag = entry;
        temp->u.entry.row = row;
        temp->u.entry.col = col;
        temp->u.entry.value = value;

        last->right = temp;
        last = temp;

        hdnode[col]->u.next->down = temp;
        hdnode[col]->u.next = temp;
    }
    last->right = hdnode[currentRow];

    for (i = 0; i < numCols; i++)
        hdnode[i]->u.next->down = hdnode[i];
    for (i = 0; i < numHeads - 1; i++)
        hdnode[i]->u.next = hdnode[i + 1];
    hdnode[numHeads - 1]->u.next = node;
    node->right = hdnode[0];

    return node;
}

void mwrite(matrixPointer node)
{
    int i;
    matrixPointer temp, head = node->right;
    printf("\n numRows = %d, numCols = %d \n",
           node->u.entry.row, node->u.entry.col);
    printf(" The matrix by row, column, and value: \n\n");
    for (i = 0; i < node->u.entry.row; i++)
    {
        for (temp = head->right; temp != head; temp = temp->right)
            printf("%5d%5d%5d \n", temp->u.entry.row,
                   temp->u.entry.col, temp->u.entry.value);
        head = head->u.next;
    }
}

void merase(matrixPointer *node)
{
    matrixPointer x, y, head = (*node)->right;
    int i, numHeads;
    for (i = 0; i < (*node)->u.entry.row; i++)
    {
        y = head->right;
        while (y != head)
        {
            x = y;
            y = y->right;
            free(x);
        }
        x = head;
        head = head->u.next;
        free(x);
    }
    y = head;
    while (y != *node)
    {
        x = y;
        y = y->u.next;
        free(x);
    }
    free(*node);
    *node = NULL;
}
