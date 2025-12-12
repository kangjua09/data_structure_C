/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENTS 200
#define HEAP_FULL(n) (n == MAX_ELEMENTS - 1)
#define HEAP_EMPTY(n) (!n)

typedef struct
{
    int key;
} element;
element heap[MAX_ELEMENTS];
int n = 0;

void push(element item, int *n)
{
    int i;
    if (HEAP_FULL(*n))
    {
        fprintf(stderr, "The heap is full.\n");
        exit(EXIT_FAILURE);
    }
    i = ++(*n);
    while ((i != 1) && (item.key > heap[i / 2].key))
    {
        heap[i] = heap[i / 2];
        i /= 2;
    }
    heap[i] = item;
}

element pop(int *n)
{
    int parent, child;
    element item, temp;
    if (HEAP_EMPTY(*n))
    {
        fprintf(stderr, "The heap is empty\n");
        exit(EXIT_FAILURE);
    }
    item = heap[1];
    temp = heap[(*n)--];
    parent = 1;
    child = 2;
    while (child <= *n)
    {
        if ((child < *n) && (heap[child].key < heap[child + 1].key))
            child++;
        if (temp.key >= heap[child].key)
            break;
        heap[parent] = heap[child];
        parent = child;
        child *= 2;
    }
    heap[parent] = temp;
    return item;
}

int main()
{
    FILE *file = fopen("in.txt", "r");
    if (file == NULL)
    {
        printf("파일을 열 수 없습니다.\n");
        return 0;
    }

    int num_elements;
    while (fscanf(file, "%d", &num_elements) != EOF)
    {
        n = 0;
        for (int i = 0; i < num_elements; i++)
        {
            int input_key;
            fscanf(file, "%d", &input_key);
            element new_item;
            new_item.key = input_key;
            push(new_item, &n);
        }

        for (int i = 1; i <= n; i++)
        {
            printf("%d ", heap[i].key);
        }
        printf("\n");
    }

    fclose(file);
    return 0;
}
    */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENTS 200
#define HEAP_FULL(n) (n == MAX_ELEMENTS - 1)
#define HEAP_EMPTY(n) (!n)

typedef struct
{
    int key;
} element;

element heap[MAX_ELEMENTS];
int n = 0;

void push(element item, int *n)
{
    int i;
    if (HEAP_FULL(*n))
    {
        fprintf(stderr, "The heap is full.\n");
        exit(EXIT_FAILURE);
    }
    i = ++(*n);
    while ((i != 1) && (item.key > heap[i / 2].key))
    {
        heap[i] = heap[i / 2];
        i /= 2;
    }
    heap[i] = item;
}

int main()
{
    FILE *file = fopen("in.txt", "r");
    if (file == NULL)
    {
        printf("fail.\n");
        return 1;
    }
    int num_size;
    int num_input;
    element item;

    while (fscanf(file, "%d", &num_size) != EOF)
    {
        n = 0; // 최대 배열크기 초기화
        for (int i = 0; i < num_size; i++)
        {
            fscanf(file, "%d", &num_input);
            item.key = num_input;
            push(item, &n);
        }
        for (int i = 1; i <= n; i++)
        {
            printf("%d ", heap[i].key);
        }
    }
    fclose(file);
    return 0;
}