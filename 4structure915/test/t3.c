#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void printIntersect(int *arr1, int size1, int *arr2, int size2);

int main()
{
    int max1 = 10, max2 = 10;
    int size1 = 0, size2 = 0;

    FILE *file1 = fopen("f3_1.txt", "r");
    if (file1 == NULL)
    {
        printf("Failed to open file.\n");
    }
    int *arr1 = (int *)malloc(max1 * sizeof(int));
    while (fscanf(file1, "%d", &arr1[size1]) == 1)
    {
        if (max1 == size1)
        {
            max1 += 10;
            arr1 = (int *)realloc(arr1, max1 * sizeof(int));
        }
        size1++;
    }

    FILE *file2 = fopen("f3_2.txt", "r");
    if (file2 == NULL)
    {
        printf("Failed to open file.\n");
    }
    int *arr2 = (int *)malloc(max2 * sizeof(int));
    while (fscanf(file2, "%d", &arr2[size2]) == 1)
    {
        if (max2 == size2)
        {
            max2 += 10;
            arr2 = (int *)realloc(arr2, max2 * sizeof(int));
        }
        size2++;
    }

    printIntersect(arr1, size1, arr2, size2);

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