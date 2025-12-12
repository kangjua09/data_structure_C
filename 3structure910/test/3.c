/* #define _CRT_SECURE_NO_WARNINGS
#define SWAP(x, y, t) ((t)=(x), (x)=(y), (y)=(t))
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sort(char** list, int n);

int main() {
    int n;

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

    char k[200];
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
    for(int i=0; i<n; i++) {
        printf("%s ", list[i]);
        free(list[i]);
    }
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
            if (strcmp(list[j], list[min]) < 0) min = j;
        }
    SWAP(list[i], list[min], temp);
    }
}*/

#define _CRT_SECURE_NO_WARNINGS
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sort(char **list, int n);
void print_list(char **list, int n);
void free_list(char **list, int n);

int main()
{
    int n;
    char arr[200];
    char **list;

    FILE *file = fopen("f3.txt", "r");
    if (file == NULL)
    {
        printf("fail\n");
        exit(1);
    }

    fscanf(file, "%d", &n);
    list = (char **)malloc(n * sizeof(char *));
    if (list == NULL)
    {
        fprintf(stderr, "Memory allocation failed!\n");
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        fscanf(file, "%s ", arr);
        list[i] = (char *)malloc(strlen(arr) + 1);
        if (list[i] == NULL)
        {
            fprintf(stderr, "String memory allocation failed!\n");
            free_list(list, i);
            return 1;
        }
        strcpy(list[i], arr);
    }

    sort(list, n);
    print_list(list, n);
    free_list(list, n);
    fclose(file);
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

void print_list(char **list, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%s ", list[i]);
    }
    printf("\n");
}

void free_list(char **list, int n)
{
    for (int i = 0; i < n; i++)
    {
        free(list[i]);
    }
    free(list);
}