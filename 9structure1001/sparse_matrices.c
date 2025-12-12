#include <stdio.h>
#include <stdlib.h>

#define MAX_TERMS 101

typedef struct
{
    int row;
    int col;
    int value;
} term;

void matrixAdd(term a[], term b[], term c[]);
void printMatrix(term m[]);

int main(void)
{
    term a[MAX_TERMS], b[MAX_TERMS], c[MAX_TERMS];
    FILE *file1, *file2;
    int i;

    if ((file1 = fopen("f1.txt", "r")) == NULL)
    {
        fprintf(stderr, "Error\n");
        exit(EXIT_FAILURE);
    }
    fscanf(file1, "%d %d %d", &a[0].row, &a[0].col, &a[0].value);
    for (i = 1; i <= a[0].value; i++)
    {
        fscanf(file1, "%d %d %d", &a[i].row, &a[i].col, &a[i].value);
    }
    fclose(file1);

    if ((file2 = fopen("f2.txt", "r")) == NULL)
    {
        fprintf(stderr, "Error\n");
        exit(EXIT_FAILURE);
    }
    fscanf(file2, "%d %d %d", &b[0].row, &b[0].col, &b[0].value);
    for (i = 1; i <= b[0].value; i++)
    {
        fscanf(file2, "%d %d %d", &b[i].row, &b[i].col, &b[i].value);
    }
    fclose(file2);

    matrixAdd(a, b, c);

    printf("/* C = A+B */\n");
    printf("%d\t%d\t%d\n", c[0].row, c[0].col, c[0].value);
    for (int i = 1; i <= c[0].value; i++)
    {
        printf("%d\t%d\t%d\n", c[i].row, c[i].col, c[i].value);
    }
    printf("\n");

    printMatrix(c);

    return 0;
}

void matrixAdd(term a[], term b[], term c[])
{
    int posA = 1, posB = 1, posC = 1;

    if (a[0].row != b[0].row || a[0].col != b[0].col)
    {
        fprintf(stderr, "Error\n");
        exit(EXIT_FAILURE);
    }

    c[0].row = a[0].row;
    c[0].col = a[0].col;

    while (posA <= a[0].value && posB <= b[0].value)
    {
        if (a[posA].row < b[posB].row)
        {
            c[posC++] = a[posA++];
        }
        else if (a[posA].row > b[posB].row)
        {
            c[posC++] = b[posB++];
        }
        else
        {
            if (a[posA].col < b[posB].col)
            {
                c[posC++] = a[posA++];
            }
            else if (a[posA].col > b[posB].col)
            {
                c[posC++] = b[posB++];
            }
            else
            {
                int sum = a[posA].value + b[posB].value;
                if (sum != 0)
                {
                    c[posC].row = a[posA].row;
                    c[posC].col = a[posA].col;
                    c[posC].value = sum;
                    posC++;
                }
                posA++;
                posB++;
            }
        }
    }

    for (; posA <= a[0].value; posA++)
    {
        c[posC++] = a[posA];
    }
    for (; posB <= b[0].value; posB++)
    {
        c[posC++] = b[posB];
    }
    c[0].value = posC - 1;
}

void printMatrix(term m[])
{
    int numRows = m[0].row;
    int numCols = m[0].col;
    int numTerms = m[0].value;
    int curTerm = 1;

    for (int r = 0; r < numRows; r++)
    {
        for (int i = 0; i < numCols; i++)
        {
            if (curTerm <= numTerms && m[curTerm].row == r && m[curTerm].col == i)
            {
                printf("%d\t", m[curTerm].value);
                curTerm++;
            }
            else
            {
                printf("0\t");
            }
        }
        printf("\n");
    }
}