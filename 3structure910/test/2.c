/* #define _CRT_SECURE_NO_WARNINGS
#define SWAP(x, y, t) ((t)=(x), (x)=(y), (y)=(t))
#define COMPARE(x,y) (((x)<(y))? -1: ((x) == (y))? 0:1)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sort(int* list, int n);
int binsearch(int* list, int searchnum, int left, int right);

int main() {
    int n;
    int searchnum;

    FILE* file = fopen("f1.txt", "r");
    if (file == NULL) {
        printf("Failed to open file.\n");
    }

    fscanf(file, "%d", &n);
    int *list = (int *)malloc(n * sizeof(int));
    if(list == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        if (fscanf(file, "%d", &list[i]) != 1) {
            fprintf(stderr, "Not enough integers in file\n");
            free(list);
            return 1;
        }
    }

    sort(list, n);
    scanf("%d", &searchnum);
    int idx = binsearch(list, searchnum, 0, n-1);
    if (idx != -1)
        printf("S (%d)\n", idx);
    else
        printf("F (-1)\n");

    fclose(file);
    free(list);
    return 0;
}

void sort(int* list, int n) {
    int i, j, min, temp;
    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++) {
            if (list[j] < list[min]) min = j;
        }
    SWAP(list[i], list[min], temp);
    }
}

int binsearch(int* list, int searchnum, int left, int right) {
    while(left <= right)  {
        int middle = (right + left) / 2;
        switch(COMPARE(list[middle], searchnum)) {
            case -1:left =middle +1;
                break;
            case 0 : return middle;
            case 1 : right = middle -1;
                break;
        }
    }
    return -1;
}
    */

#define _CRT_SECURE_NO_WARNINGS
#define COMPARE(x, y) (((x) < (y)) ? -1 : ((x) == (y)) ? 0 \
                                                       : 1)
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sort(int *list, int n);
int binsearch(int list[], int searchnum, int left, int right);
int main()
{
    int n, searchnum;
    FILE *file = fopen("f1.txt", "r");
    if (file == NULL)
    {
        printf("Failed to open file.\n");
        return 1;
    }

    fscanf(file, "%d", &n);
    int *list = (int *)malloc(n * sizeof(int));
    if (list == NULL)
    {
        fprintf(stderr, "Memory allocation failed!\n");
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        if (fscanf(file, "%d", &list[i]) != 1)
        {
            fprintf(stderr, "Not enough integers in file\n");
            free(list);
            return 1;
        }
    } // 파일에 있던 수들을 배열에 저장 -> 배열 정렬
    sort(list, n);
    scanf("%d", &searchnum);
    if (binsearch(list, searchnum, 0, n - 1) != -1)
        printf("S (%d)", binsearch(list, searchnum, 0, n - 1));
    else
        printf("F (-1)");

    fclose(file);
    free(list);
    return 0;
}

void sort(int *list, int n)
{
    int min, temp;
    for (int i = 0; i < n; i++)
    {
        min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (list[min] > list[j])
            {
                min = j;
            }
        }
        SWAP(list[i], list[min], temp);
    }
}

int binsearch(int list[], int searchnum, int left, int right)
{
    while (left <= right)
    {
        int middle = (right + left) / 2;
        switch (COMPARE(list[middle], searchnum))
        {
        case -1:
            left = middle + 1;
            break;
        case 0:
            return middle;
        case 1:
            right = middle - 1;
            break;
        }
    }
    return -1;
}