/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int linearSearch(int *arr, int n, int target);

int main()
{
    int N, target;
    clock_t start, end;
    double time_taken;

    scanf("%d", &N);
    int *arr = (int *)malloc(N * sizeof(int));

    for (int i = 0; i < N; i++)
    {
        arr[i] = rand() << 15 | rand();
    }
    scanf("%d", &target);

    start = clock();
    int idx = linearSearch(arr, N, target);
    end = clock();
    time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    if (idx == -1)
        printf("Not found\n%f", time_taken);
    else
        printf("Index : %d\n%f", idx, time_taken);

    free(arr);
}

int linearSearch(int *arr, int n, int target)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == target)
        {
            return i;
        }
    }
    return -1;
}
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int linearSearch(int *arr, int n, int target);

int main()
{
    int N, target;
    clock_t start, end;
    double duaration;

    scanf("%d", &N);
    int *ary = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++)
    {
        ary[i] = rand() << 15 | rand();
    }
    scanf("%d", &target);
    start = clock();
    end = clock();
    duaration = ((double)(end - start)) / CLOCKS_PER_SEC;
    if (linearSearch(ary, N, target) == -1)
    {
        printf("Not Found\n%.6f", duaration);
    }
    else
    {
        printf("Index : %d\n%.6f", linearSearch(ary, N, target), duaration);
    }
}

int linearSearch(int *arr, int n, int target)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == target)
        {
            return i;
        }
    }
    return -1;
}