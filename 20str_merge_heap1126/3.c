#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

typedef struct
{
    int key;
    char value;
} element;

int listMerge(element a[], int link[], int start1, int start2);

int rmergeSort(element a[], int link[], int left, int right)
{
    if (left >= right)
        return left;
    int mid = (left + right) / 2;
    return listMerge(a, link, rmergeSort(a, link, left, mid), rmergeSort(a, link, mid + 1, right));
}

int listMerge(element a[], int link[], int start1, int start2)
{
    /*
    if(a[last1].key <= a[last2].key)에서,
    두 키 값이 같을 경우 먼저 입력된 리스트의 요소를 우선 선택되었기 때문에 stable sorting입니다.
    */
    int last1, last2, lastResult = 0;
    for (last1 = start1, last2 = start2; last1 && last2;)
        if (a[last1].key <= a[last2].key)
        {
            link[lastResult] = last1;
            lastResult = last1;
            last1 = link[last1];
        }
        else
        {
            link[lastResult] = last2;
            lastResult = last2;
            last2 = link[last2];
        }
    if (last1 == 0)
        link[lastResult] = last2;
    else
        link[lastResult] = last1;
    return link[0];
}

int main()
{
    FILE *file = fopen("in.txt", "r");
    if (file == NULL)
    {
        printf("fail\n");
        return 1;
    }

    int keyData;
    char charData;
    int n = 0;
    element a[MAX_SIZE];
    int link[MAX_SIZE];
    while (fscanf(file, "%d %c", &keyData, &charData) != EOF)
    {
        n++;
        if (n >= MAX_SIZE)
            break;
        a[n].key = keyData;
        a[n].value = charData;
        link[n] = 0;
    }

    int first = rmergeSort(a, link, 1, n);
    while (first != 0)
    {
        printf("%d %c\n", a[first].key, a[first].value);
        first = link[first];
    }
    printf("\n");

    fclose(file);
    return 0;
}