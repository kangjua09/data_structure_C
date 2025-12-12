/* #define _CRT_SECURE_NO_WARNINGS
#define SWAP(x, y, t) ((t)=(x), (x)=(y), (y)=(t))
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sort(int* list, int n);

int main() {
    int n;

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
    for(int i=0; i<n; i++) {
        printf("%d ", list[i]);
    }
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
*/

#define _CRT_SECURE_NO_WARNINGS
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sort(int *arr, int n);

int main()
{
    int n;
    int *arr;

    FILE *file = fopen("f1.txt", "r");
    if (file == NULL)
    {
        printf("Failed to open file.\n");
        return 1;
    }

    fscanf(file, "%d", &n);
    arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL)
    {
        fprintf(stderr, "fail\n");
        return 1;
    }
    for (int i = 0; i < n; i++)
    {
        if (fscanf(file, "%d", &arr[i]) != 1)
        {
            fprintf(stderr, "Not enough integers in file\n");
            free(arr);
            return 1;
        }
    }
    sort(arr, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    fclose(file);
    free(arr);
    return 0;
}

void sort(int *arr, int n)
{
    int min, temp;
    for (int i = 0; i < n; i++)
    {
        min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[min] > arr[j])
            {
                min = j;
            }
        }
        SWAP(arr[i], arr[min], temp);
    }
}