/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printDifference(char **arr1, int size1, char **arr2, int size2);

int main()
{
    int n1 = 0, n2 = 0;
    char temp[100];

    FILE *file1 = fopen("f2_1.txt", "r");
    if (file1 == NULL)
    {
        printf("Failed to open file.\n");
    }

    char **arr1 = (char **)malloc(10 * sizeof(char *));
    while (fscanf(file1, "%s", temp) == 1)
    {
        arr1[n1] = (char *)malloc((strlen(temp) + 1) * sizeof(char));
        strcpy(arr1[n1], temp);
        n1++;
    }

    FILE *file2 = fopen("f2_2.txt", "r");
    if (file2 == NULL)
    {
        printf("Failed to open file.\n");
    }
    char **arr2 = (char **)malloc(10 * sizeof(char *));
    while (fscanf(file2, "%s", temp) == 1)
    {
        arr2[n2] = (char *)malloc((strlen(temp) + 1) * sizeof(char));
        strcpy(arr2[n2], temp);
        n2++;
    }

    printDifference(arr1, n1, arr2, n2);

    fclose(file1);
    fclose(file2);
    free(arr1);
    free(arr2);
    return 0;
}

void printDifference(char **arr1, int size1, char **arr2, int size2)
{
    int i = 0, j = 0;
    while (i < size1 && j < size2)
    {
        if (strcmp(arr1[i], arr2[j]) == 0)
        {
            i++;
            j++;
        }
        else if (strcmp(arr1[i], arr2[j]) < 0)
        {
            printf("%s ", arr1[i]);
            i++;
        }
        else
            j++;
    }

    while (i < size1)
    {
        printf("%s ", arr1[i]);
        i++;
    }
    printf("\n");
}
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printDifference(char **arr1, int size1, char **arr2, int size2);
void free_list(char **list, int n);

int main()
{
    int n1 = 0, n2 = 0;
    char temp[100];

    FILE *file1 = fopen("f2_1.txt", "r");
    if (file1 == NULL)
    {
        printf("fail\n");
        return 1;
    }
    char **arr1 = (char **)malloc(10 * sizeof(char *));
    while (fscanf(file1, "%s", temp) == 1)
    {
        arr1[n1] = (char *)malloc((strlen(temp) + 1) * sizeof(char));
        strcpy(arr1[n1], temp);
        n1++;
    }

    FILE *file2 = fopen("f2_2.txt", "r");
    if (file2 == NULL)
    {
        printf("fail\n");
        return 1;
    }
    char **arr2 = (char **)malloc(10 * sizeof(char *));
    while (fscanf(file2, "%s", temp) == 1)
    {
        arr2[n2] = (char *)malloc((strlen(temp) + 1) * sizeof(char));
        strcpy(arr2[n2], temp);
        n2++;
    }
    printDifference(arr1, n1, arr2, n2);
    fclose(file1);
    fclose(file2);
    free_list(arr1, n1);
    free_list(arr2, n2);
    return 0;
}

void printDifference(char **arr1, int size1, char **arr2, int size2)
{
    int i = 0, j = 0;
    while (i < size1 && j < size2)
    {
        if (strcmp(arr1[i], arr2[j]) != 0)
        {
            printf("%s ", arr1[i]);
            i++;
        }
        else
        {
            i++;
            j++;
        }
    }
    while (i < size1)
    {
        printf("%s ", arr1[i]);
        i++;
    }
    printf("\n"); // arr1에서 값이 남아았을수도 잇으니까
}

void free_list(char **list, int n)
{
    // 1. (2단계 해제) 개별 문자열 데이터(아파트)를 먼저 해제
    for (int i = 0; i < n; i++)
    {
        free(list[i]);
    }
    // 2. (1단계 해제) 포인터 목록(호수 목록)을 마지막에 해제
    free(list);
}