/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int **makeArray(int rows, int cols);
int **transpose(int **A, int rows, int cols);
void printArray(int **array, int rows, int cols);
void freeArray(int **array, int rows);

int main()
{
    int rows, cols;

    FILE *file = fopen("f2.txt", "r");
    if (file == NULL)
    {
        printf("Failed to open file.\n");
        return 1;
    }
    fscanf(file, "%d %d", &rows, &cols);

    int **A = makeArray(rows, cols);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            fscanf(file, "%d", &A[i][j]);
        }
    }

    int **B = transpose(A, rows, cols);
    printArray(B, cols, rows);

    freeArray(A, rows);
    freeArray(B, cols);
    fclose(file);

    return 0;
}

int **makeArray(int rows, int cols)
{
    int **arr = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++)
    {
        arr[i] = (int *)malloc(cols * sizeof(int));
    }
    return arr;
}

int **transpose(int **A, int rows, int cols)
{
    int **B = makeArray(cols, rows);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            B[j][i] = A[i][j];
        }
    }
    return B;
}

void printArray(int **array, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
}

void freeArray(int **array, int rows)
{
    for (int i = 0; i < rows; i++)
    {
        free(array[i]);
    }
    free(array);
}
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int **makeArray(int rows, int cols);           /* 동적 2차원 배열 생성, 반환 */
int **trasnspose(int **A, int rows, int cols); /* A로부터 전치행렬 B를 생성, 반환 */
void printArray(int **array, int rows, int cols);
void freeArray(int **array, int rows);

int main()
{
    int rows, cols;

    FILE *file = fopen("f2.txt", "r");
    if (file == NULL)
    {
        printf("Fail\n");
        return 1;
    }
    fscanf(file, "%d %d", &rows, &cols);
    int **A = makeArray(rows, cols);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            fscanf(file, "%d", &A[i][j]);
        }
    }
    int **B = trasnspose(A, rows, cols);
    printArray(B, cols, rows);
    freeArray(A, rows);
    freeArray(B, cols);
    fclose(file);
    return 0;
}

int **makeArray(int rows, int cols)
{
    int **A = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++)
    {
        A[i] = (int *)malloc(cols * sizeof(int));
    }
    return A;
}

int **trasnspose(int **A, int rows, int cols)
{
    int **B = (int **)malloc(cols * sizeof(int *));
    for (int i = 0; i < cols; i++)
    {
        B[i] = (int *)malloc(rows * sizeof(int));
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            B[j][i] = A[i][j];
        }
    }
    return B;
}

void printArray(int **array, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
}

void freeArray(int **array, int rows)
{
    for (int i = 0; i < rows; i++)
    {
        free(array[i]);
    }
    free(array);
}