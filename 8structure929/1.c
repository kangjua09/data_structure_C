/*
#include <stdio.h>
#include <stdlib.h>
#define MALLOC(p, s)                            \
    if (!((p) = malloc(s)))                     \
    {                                           \
        fprintf(stderr, "Insufficient memory"); \
        exit(EXIT_FAILURE);                     \
    }
#define REALLOC(p, s)                           \
    if (!((p) = realloc(p, s)))                 \
    {                                           \
        fprintf(stderr, "Insufficient memory"); \
        exit(EXIT_FAILURE);                     \
    }

typedef struct
{
    int key;
} element;

element *stack;
int top = -1;
int capacity = 1;

void stackFull()
{
    REALLOC(stack, 2 * capacity * sizeof(element));
    capacity *= 2;
}
void push(element item)
{
    if (top >= capacity - 1)
    {
        stackFull();
    }
    stack[++top] = item;
}

element pop()
{
    if (top == -1)
    {
        printf("Stack empty\n");
        element errorItem = {-1};
        return errorItem;
    }
    return stack[top--];
}

int main()
{
    MALLOC(stack, sizeof(element) * capacity);

    char command;
    int x;

    while (1)
    {
        scanf(" %c", &command);

        if (command == 'F')
        {
            break;
        }
        else if (command == 'I')
        {
            scanf("%d", &x);
            element newItem;
            newItem.key = x;
            push(newItem);
        }
        else if (command == 'D')
        {
            element poppedItem = pop();
        }
    }

    for (int i = 0; i <= top; i++)
    {
        printf("%d", stack[i].key);
        if (i < top)
        {
            printf(" ");
        }
    }

    if (top > -1)
    {
        printf("\n");
    }

    free(stack);
    return 0;
}
*/

#include <stdio.h>
#include <stdlib.h>
#define MALLOC(p, s)                            \
    if (!((p) = malloc(s)))                     \
    {                                           \
        fprintf(stderr, "Insufficient memory"); \
        exit(EXIT_FAILURE);                     \
    }
#define REALLOC(p, s)                           \
    if (!((p) = realloc(p, s)))                 \
    {                                           \
        fprintf(stderr, "Insufficient memory"); \
        exit(EXIT_FAILURE);                     \
    }

typedef struct
{
    int key;
} element;

element *stack;
int top = -1;
int capacity = 1;

void stackEmpty()
{
    printf("Stack empty\n");
}

void stackFull()
{
    REALLOC(stack, 2 * capacity * sizeof(element));
    capacity *= 2;
}

void push(element item)
{
    if (top >= capacity - 1)
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
    }
    return stack[top--];
}

int main()
{
    int n;
    char a;
    MALLOC(stack, capacity * sizeof(element));

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
            element poppeditem = pop();
        }
    }

    for (int i = 0; i <= top; i++)
    {
        printf("%d ", stack[i].key);
    }

    free(stack);
    return 0;
}

/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

typedef struct
{
    int *arr;
    int top;
    int capacity;
} Array;

void init(Array *s)
{
    s->top = -1;
    s->capacity = 1; // 초기크기 1
    s->arr = (int *)malloc(sizeof(int) * s->capacity);
}
// 배열은 인덱스가 0부터 시작하기 때문에 top 초기화

int stackEmpty(Array *s)
{
    return (s->top == -1);
}
// top == -1 이면 비어있음

int stackFull(Array *s)
{
    return (s->top == s->capacity - 1);
}
// top이 마지막 칸까지 올라갔는지 확인

void stackFullrealloc(Array *s)
{
    s->capacity *= 2;
    s->arr = (int *)realloc(s->arr, sizeof(int) * s->capacity);
}

void push(Array *s, int value)
{
    if (stackFull(s))
        stackFullrealloc(s);
    s->arr[++(s->top)] = value;
}

int pop(Array *s, int *value)
{
    if (stackEmpty(s))
    {
        printf("Stack empty\n"); // 비어잇는거 메세지 출력
        return 0;
    }
    *value = s->arr[(s->top)--]; // 값의 위치 배열인덱스 감소시킴(빼내니까)
    return 1;
}

int main()
{
    Array s;
    init(&s);

    char temp;
    int n;

    while (1)
    {
        scanf("%c", &temp);
        if (temp == 'F') // F면 그만
            break;
        else if (temp == 'I') // I면 push
        {
            scanf("%d", &n);
            push(&s, n);
        }
        else if (temp == 'D') // D면 빼내기
        {
            int value;
            pop(&s, &value);
        }
    }

    // 최종 stack 출력
    for (int i = 0; i <= s.top; i++)
    {
        printf("%d ", s.arr[i]);
    }

    return 0;
}
*/