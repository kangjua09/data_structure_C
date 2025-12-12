/*
#define _CRT_SECURE_NO_WARNINGS
#define SWAP(x, y, t) ((t)=(x), (x)=(y), (y)=(t))
#define COMPARE(x,y) (((x)<(y))? -1: ((x) == (y))? 0:1)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sort(char** list, int n);
int binsearch(char* list[], char* searchStr, int left, int right);

int main() {
    int n;
    char searchStr[200];
    char k[200];

    FILE* file = fopen("f3.txt", "r");
    if (file == NULL) {
        printf("Failed to open file.\n");
    }

    fscanf(file, "%d", &n);
    char **list = (char **)malloc(n * sizeof(char*));
    if(list == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        if (fscanf(file, "%199s", k) != 1) {
            fprintf(stderr, "Not enough strings in file\n");
            for (int j = 0; j < i; j++)
                free(list[j]);
            return 1;
        }
        list[i] = (char*)malloc(strlen(k) + 1);
        strcpy(list[i], k);
    }

    sort(list, n);
    scanf("%s", searchStr);
    int idx = binsearch(list, searchStr, 0, n-1);
    if (idx != -1)
        printf("S (%d)\n", idx);
    else
        printf("F (-1)\n");

    fclose(file);
    free(list);
    return 0;
}

void sort(char** list, int n) {
    int i, j, min;
    char* temp;
    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++) {
            if (strcmp(list[j], list[min]) < 0)
            min = j;
        }
    SWAP(list[i], list[min], temp);
    }
}

int binsearch(char* list[], char* searchStr, int left, int right) {
    while(left <= right)  {
        int middle = (left +right) / 2;
        int cmp = strcmp(list[middle], searchStr);
        if(cmp < 0)
            left  = middle + 1;
        else if (cmp > 0)
            right = middle - 1;
        else
            return middle;
    }
    return -1;
}
    */

#define _CRT_SECURE_NO_WARNINGS
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sort(char **list, int n);
int binsearch(char **list, char *searchstr, int left, int right);
void free_list(char **list, int n);

int main()
{
    int n;
    char searchstr[200];
    FILE *file = fopen("f1.txt", "r");
    if (file == NULL)
    {
        printf("Failed to open file.\n");
        return 1;
    }

    fscanf(file, "%d", &n);
    char **list = (char **)malloc(n * sizeof(char *));
    if (list == NULL)
    {
        fprintf(stderr, "Memory allocation failed!\n");
        return 1;
    }

    char arr[200];
    for (int i = 0; i < n; i++)
    {
        if (fscanf(file, "%199s", arr) != 1)
        {
            fprintf(stderr, "Memory allocation failed!\n");
            free_list(list, n);
            return 1;
        }
        list[i] = (char *)malloc(strlen(arr) + 1);
        strcpy(list[i], arr);
    } // 파일에 있던 수들을 배열에 저장 -> 배열 정렬

    sort(list, n);
    scanf("%s", searchstr);
    if (binsearch(list, searchstr, 0, n - 1) != -1)
        printf("S (%d)", binsearch(list, searchstr, 0, n - 1));
    else
        printf("F (-1)");

    fclose(file);
    free_list(list, n);
    return 0;
}

void sort(char **list, int n)
{
    int min;
    char *temp;
    for (int i = 0; i < n - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (strcmp(list[j], list[min]) < 0)
                min = j;
        }
        SWAP(list[i], list[min], temp);
    }
}

int binsearch(char **list, char *searchstr, int left, int right)
{
    while (left <= right)
    {
        int middle = (right + left) / 2;
        int cmp = strcmp(list[middle], searchstr);
        {
            if (cmp < 0)
                left = middle + 1;
            else if (cmp > 0)
                right = middle - 1;
            else
                return middle;
        }
    }
    return -1;
}

void free_list(char **list, int n)
{
    for (int i = 0; i < n; i++)
    {
        free(list[i]);
    }
    free(list);
}