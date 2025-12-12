#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 5
#define MAX_RECORDS 100
#define D 5
#define R 27

typedef struct
{
    char key[MAX_WORD_LENGTH + 1];
} element;

element a[MAX_RECORDS + 1];
int link[MAX_RECORDS + 1];
int n;

int digit(element item, int i, int r)
{
    int len = strlen(item.key);
    int char_index = len - 1 - (D - 1 - i);

    if (char_index >= 0 && char_index < len)
    {
        return (item.key[char_index] - 'a') + 1;
    }
    return 0;
}

int radixSort(element a[], int link[], int d, int r, int n)
{
    int front[R], rear[R];
    int i, bin, current, first, last;

    if (n <= 1)
    {
        if (n == 1)
            return 1;
        return 0;
    }

    first = 1;
    for (i = 1; i < n; i++)
        link[i] = i + 1;
    link[n] = 0;

    for (i = d - 1; i >= 0; i--)
    {
        for (bin = 0; bin < r; bin++)
            front[bin] = 0;

        for (current = first; current; current = link[current])
        {
            bin = digit(a[current], i, r);

            if (front[bin] == 0)
                front[bin] = current;
            else
                link[rear[bin]] = current;
            rear[bin] = current;
        }

        for (bin = 0; !front[bin]; bin++)
            ;
        first = front[bin];
        last = rear[bin];

        for (bin++; bin < r; bin++)
            if (front[bin])
            {
                link[last] = front[bin];
                last = rear[bin];
            }
        link[last] = 0;
    }

    return first;
}

int main()
{
    char word_buffer[MAX_WORD_LENGTH + 1];

    FILE *file = fopen("in.txt", "r");
    if (file == NULL)
    {
        printf("Failed to open.\n");
        return 1;
    }

    n = 0;
    while (fscanf(file, "%s", word_buffer) == 1 && n < MAX_RECORDS)
    {
        n++;
        strcpy(a[n].key, word_buffer);
    }
    fclose(file);

    int first = radixSort(a, link, D, R, n);
    int current = first;
    while (current != 0)
    {
        printf("%s ", a[current].key);
        current = link[current];
    }
    printf("\n");

    return 0;
}