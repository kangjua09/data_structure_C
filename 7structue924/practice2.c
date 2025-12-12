/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100

typedef struct
{
    int key;
} element;

element stack[MAX_STACK_SIZE];
int top = -1;

void push(element item)
{
    if (top >= MAX_STACK_SIZE - 1)
    {
        fprintf(stderr, "Stack is full, cannot add element\n");
        exit(EXIT_FAILURE);
    }
    stack[++top] = item;
}

element pop()
{
    if (top < 0)
    {
        printf("Stack empty\n");
        element errorItem = {-1};
        return errorItem;
    }
    return stack[top--];
}

int main()
{
    char temp;
    int n;

    while (1)
    {
        scanf(" %c", &temp);

        if (temp == 'F')
        {
            break;
        }
        else if (temp == 'I')
        {
            scanf("%d", &n);
            element newItem;
            newItem.key = n;
            push(newItem);
        }
        else if (temp == 'D')
        {
            element poppedItem = pop();
        }
    }

    for (int i = 0; i <= top; i++)
    {
        printf("%d ", stack[i].key);
    }
    printf("\n");

    return 0;
}
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 101

typedef struct
{
    int key;
} element;
element stack[MAX_STACK_SIZE];
int top = -1;

void stackEmpty()
{
    printf("Stack empty\n");
}

void stackFull()
{
    fprintf(stderr, "fail\n");
    exit(EXIT_FAILURE);
}

void push(element item)
{
    if (top >= MAX_STACK_SIZE - 1)
    {
        stackFull();
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
    char a;
    int n;

    while (1)
    {
        scanf(" %c", &a);
        if (a == 'F')
        {
            break;
        }
        else if (a == 'I')
        {
            scanf("%d", &n);
            element item;
            item.key = n;
            push(item);
        }
        else if (a == 'D')
        {
            element poppedItem = pop();
        }
    }
    for (int i = 0; i <= top; i++)
    {
        printf("%d ", stack[i].key);
    }
    printf("\n");

    return 0;
}