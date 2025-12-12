/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void printIntersect(int *arr1, int size1, int *arr2, int size2);

int main()
{
    int n1 = 0, n2 = 0;

    FILE *file1 = fopen("f1_1.txt", "r");
    if (file1 == NULL)
    {
        printf("Failed to open file.\n");
    }
    int *arr1 = (int *)malloc(10 * sizeof(int));
    while (fscanf(file1, "%d", &arr1[n1]) == 1)
        n1++;

    FILE *file2 = fopen("f1_2.txt", "r");
    if (file2 == NULL)
    {
        printf("Failed to open file.\n");
    }
    int *arr2 = (int *)malloc(10 * sizeof(int));
    while (fscanf(file2, "%d", &arr2[n2]) == 1)
        n2++;

    printIntersect(arr1, n1, arr2, n2);

    fclose(file1);
    fclose(file2);
    free(arr1);
    free(arr2);

    return 0;
}

void printIntersect(int *arr1, int size1, int *arr2, int size2)
{
    int i = 0, j = 0;
    while (i < size1 && j < size2)
    {
        if (arr1[i] == arr2[j])
        {
            printf("%d ", arr1[i]);
            i++;
            j++;
        }
        else if (arr1[i] < arr2[j])
            i++;
        else
            j++;
    }
    printf("\n");
}
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void printIntersect(int *arr1, int size1, int *arr2, int size2);

int main()
{
    int n1 = 0, n2 = 0;
    FILE *file1 = fopen("f1_1.txt", "r");
    if (file1 == NULL)
    {
        printf("fail\n");
        return 1;
    }
    int *arr1 = (int *)malloc(10 * sizeof(int));
    while (fscanf(file1, "%d", &arr1[n1]) == 1)
    {
        n1++;
    }

    FILE *file2 = fopen("f1_2.txt", "r");
    if (file2 == NULL)
    {
        printf("fail\n");
        return 1;
    }
    int *arr2 = (int *)malloc(10 * sizeof(int));
    while (fscanf(file2, "%d", &arr2[n2]) == 1)
    {
        n2++;
    }
    printIntersect(arr1, n1, arr2, n2);
    fclose(file1);
    fclose(file2);
    free(arr1);
    free(arr2);
    return 0;
}

void printIntersect(int *arr1, int size1, int *arr2, int size2)
{
    int i = 0, j = 0;
    while (i < size1 && j < size2)
    {
        if (arr1[i] == arr2[j])
        {
            printf("%d ", arr1[i]);
            i++;
            j++;
        }
        else if (arr1[i] < arr2[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }
}