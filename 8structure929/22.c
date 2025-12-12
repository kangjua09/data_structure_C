#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MALLOC(p, s)                           \
    if (!((p) = malloc(s)))                    \
    {                                          \
        fprintf(stderr, "Inefficient fail\n"); \
        exit(EXIT_FAILURE);                    \
    }
#define REALLOC(p, s)                          \
    if (!((p) = realloc(p, s)))                \
    {                                          \
        fprintf(stderr, "Inefficient fail\n"); \
        exit(EXIT_FAILURE);                    \
    }

typedef struct
{
    int key;
} element;

int capacity = 1;
int top = -1;
element *stack;

void stackEmpty()
{
    printf("Stack empty\n");
}

void push(element item)
{
    if (top >= capacity - 1)
    {
        REALLOC(stack, 2 * capacity * sizeof(element));
        capacity *= 2;
    }
    stack[++top] = item;
}

element pop()
{
    if (top == -1)
    {
        stackEmpty();
        element errorItem = {-1};
        return errorItem;
    }
    return stack[top--];
}

int main()
{
    int n;
    char a;
    element item;
    MALLOC(stack, capacity * sizeof(element));

    FILE *file = fopen("in2.txt", "r");
    if (file == NULL)
    {
        printf("fail\n");
        exit(1);
    }

    while (fscanf(file, " %c", &a) != EOF) // text상자에 값이 있을때까지만 아니면 무한루프돔
    {
        if (a == 'I')
        {
            fscanf(file, "%d", &n);
            item.key = n;
            push(item);
        }
        else if (a == 'D')
        {
            element poppeditem = pop();
        }
    }

    for (int i = top; i >= 0; i--) // top->bottom
    {
        printf("%d ", stack[i].key);
    }

    fclose(file);
    free(stack);
    return 0;
}