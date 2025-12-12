#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SWAP(x, y, t) \
    {                 \
        (t) = (x);    \
        (x) = (y);    \
        (y) = (t);    \
    }
#define MALLOC(p, s)                            \
    if (!((p) = malloc(s)))                     \
    {                                           \
        fprintf(stderr, "Insufficient memory"); \
        exit(EXIT_FAILURE);                     \
    }

typedef struct
{
    char name[100];
    int id;
    double grade;
} element;

void quickSort(element a[], int left, int right)
{
    int i, j;
    char pivot[100];
    element temp;

    if (left < right)
    {
        i = left;
        j = right + 1;
        strcpy(pivot, a[left].name);

        do
        {
            do
                i++;
            while (i <= right && strcmp(a[i].name, pivot) < 0);

            do
                j--;
            while (strcmp(a[j].name, pivot) > 0);

            if (i < j)
                SWAP(a[i], a[j], temp);
        } while (i < j);

        SWAP(a[left], a[j], temp);
        quickSort(a, left, j - 1);
        quickSort(a, j + 1, right);
    }
}

int main()
{
    FILE *file = fopen("in2.txt", "r");
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
        fscanf(file, "%s %d %lf", list[i].name, &list[i].id, &list[i].grade);
    }

    quickSort(list, 1, n);

    for (int i = 1; i <= n; i++)
    {
        printf("이름: %s, 학번: %d, 평균성적: %.2lf\n", list[i].name, list[i].id, list[i].grade);
    }

    free(list);
    fclose(file);
    return 0;
}