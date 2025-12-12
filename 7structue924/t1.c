#define _CRT_SECURE_NO_WARNINGS
#define MAX_TERMS 101
#define MAX_COLS 101
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int row;
    int col;
    int value;
} term;

void readMatrix(char *filename, term matrix[]);
void fastTranspose(term a[], term b[]);
void writeMatrix(const char *filename, term matrix[]);
void printMatrix2D(term matrix[]);

int main()
{
    term a[MAX_TERMS], b[MAX_TERMS];

    readMatrix("a.txt", a);
    fastTranspose(a, b);
    writeMatrix("b.txt", b);

    printf("A\n");
    printMatrix2D(a);
    printf("\nB\n");
    printMatrix2D(b);

    return 0;
}

void readMatrix(char *filename, term matrix[])
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("파일 열기 실패\n");
        exit(1);
    }

    fscanf(file, "%d %d %d", &matrix[0].row, &matrix[0].col, &matrix[0].value);
    for (int i = 1; i <= matrix[0].value; i++)
    {
        fscanf(file, "%d %d %d", &matrix[i].row, &matrix[i].col, &matrix[i].value);
    }

    fclose(file);
}

// 교재 예제 2.9의 fastTranspose 함수 구현
void fastTranspose(term a[], term b[])
{
    int rowTerms[MAX_COLS], startingPos[MAX_COLS];
    int numCols = a[0].col, numTerms = a[0].value;

    b[0].row = numCols;
    b[0].col = a[0].row;
    b[0].value = numTerms;

    if (numTerms > 0)
    {
        // 원본 행렬a의 각 열에 속한 항의 개수를 계산
        for (int i = 0; i < numCols; i++)
        {
            rowTerms[i] = 0;
        }
        for (int i = 1; i <= numTerms; i++)
        {
            rowTerms[a[i].col]++;
        }

        // 전치 행렬b에서 각 행의 시작 위치를 계산
        startingPos[0] = 1;
        for (int i = 1; i < numCols; i++)
        {
            startingPos[i] = startingPos[i - 1] + rowTerms[i - 1];
        }

        // 항들을 a에서 b로 옮긴다.
        for (int i = 1; i <= numTerms; i++)
        {
            int j = startingPos[a[i].col]++;
            b[j].row = a[i].col;
            b[j].col = a[i].row;
            b[j].value = a[i].value;
        }
    }
}

void writeMatrix(const char *filename, term matrix[])
{
    FILE *file = fopen(filename, "w");
    if (file == NULL)
    {
        printf("파일 열기 실패\n");
        exit(1);
    }

    fprintf(file, "%d %d %d\n", matrix[0].row, matrix[0].col, matrix[0].value);
    for (int i = 1; i <= matrix[0].value; i++)
    {
        fprintf(file, "%d %d %d\n", matrix[i].row, matrix[i].col, matrix[i].value);
    }

    fclose(file);
}

void printMatrix2D(term matrix[])
{
    int rows = matrix[0].row;
    int cols = matrix[0].col;
    int terms = matrix[0].value;
    term *p = &matrix[1];

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (p <= &matrix[terms] && p->row == i && p->col == j)
            {
                printf("\t%d", p->value);
                p++;
            }
            else
            {
                printf("\t%d", 0);
            }
        }
        printf("\n");
    }
}