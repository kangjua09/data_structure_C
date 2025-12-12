#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
#define SWAP(x, y, t) \
    {                 \
        (t) = (x);    \
        (x) = (y);    \
        (y) = (t);    \
    }

typedef struct
{
    int key;
} element;

void adjust(element a[], int root, int n)
{
    int child, rootkey;
    element temp;
    temp = a[root];
    rootkey = a[root].key;
    child = 2 * root;
    while (child <= n)
    {
        if ((child < n) && (a[child].key > a[child + 1].key))
            child++;
        if (rootkey <= a[child].key)
            break;
        else
        {
            a[child / 2] = a[child];
            child *= 2;
        }
    }
    a[child / 2] = temp;
}

void heapsort_(element list[], int n)
{
    int i, j;
    element temp;

    for (i = n / 2; i > 0; i--)
    {
        adjust(list, i, n);
    }
    for (i = n - 1; i > 0; i--)
    {
        SWAP(list[1], list[i + 1], temp);
        adjust(list, 1, i);
    }
}

int main()
{
    element a[MAX_SIZE];
    int n = 0;
    int data;
    FILE *file = fopen("in.txt", "r");
    if (file == NULL)
    {
        printf("fail to open file\n");
        return 1;
    }

    while (fscanf(file, "%d", &data) != EOF)
    {
        n++;
        a[n].key = data;
    }

    heapsort_(a, n);
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", a[i].key);
    }
    printf("\n");

    fclose(file);
    return 0;
}