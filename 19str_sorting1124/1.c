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
    int key;
    char name[100];
    int grade;
} element;

void insert(element e, element a[], int i)
{
    a[0] = e;
    while (e.key < a[i].key)
    {
        a[i + 1] = a[i];
        i--;
    }
    a[i + 1] = e;
}

void insertionSort(element a[], int n)
{
    int j;
    for (j = 2; j <= n; j++)
    {
        element temp = a[j];
        insert(temp, a, j - 1);
    }
}

int main()
{
    FILE *file = fopen("in1.txt", "r");
    if (file == NULL)
    {
        printf("fail\n");
        return 1;
    }
    int n;
    fscanf(file, "%d", &n);
    element *list;
    MALLOC(list, sizeof(element) * (n + 1));
    for (int i = 1; i <= n; i++)
    {
        fscanf(file, "%d %s %d", &list[i].key, &list[i].name, &list[i].grade);
    }
    insertionSort(list, n);
    for (int i = 1; i <= n; i++)
    {
        printf("%d %s %d\n", list[i].key, list[i].name, list[i].grade);
    }
    free(list);
    fclose(file);
    return 0;
}