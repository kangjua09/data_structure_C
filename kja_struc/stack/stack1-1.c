#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

typedef struct StackType
{
    int arr[100];
    int top;
} StackType;

void init(StackType *s)
{
    s->top = -1; // top 초기화, 배열은 인덱스가 0부터 시작하기 때문에
}

int is_empty(StackType *s)
{
    if (s->top == -1) // 비어있으면 return 1, 비어있지 않으면 return 0
        return 1;
    return 0;
}

int is_full(StackType *s)
{
    if (s->top == SIZE - 1) // 다 차있으면 return 1, 다 안차있으면 return 0
        return 1;
    return 0;
}

void push(StackType *s, int value)
{
    if (is_full(s))
    {
        printf("Stack is full");
        exit(1);
    }
    printf("\npushed : %d", value);
    s->arr[++(s->top)] = value;
}

int pop(StackType *s)
{
    if (is_empty(s))
    {
        printf("Stack is empty");
        exit(1);
    }
    return s->arr[(s->top)--];
}

int peek(StackType *s)
{
    if (is_empty(s))
    {
        printf("Stack is empty");
        exit(1);
    }
    return s->arr[(s->top)];
}

int main()
{
    StackType s;
    init(&s); // stack이 초기화

    push(&s, 3);
    push(&s, 2);
    push(&s, 1);

    printf("\npeek: %d\n", peek(&s));
    printf("\npop: %d\n", pop(&s));
    printf("\npop: %d\n", pop(&s));
    printf("\npop: %d\n", pop(&s));

    printf("\npop: %d\n", pop(&s));
    return 0;
}