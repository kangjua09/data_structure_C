#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

typedef struct
{
    int arr[SIZE];
    int top;
} Array;

void init(Array *s)
{
    s->top = -1;
}
// 배열은 인덱스가 0부터 시작하기 때문에 top 초기화

int stackEmpty(Array *s)
{
    return (s->top == -1);
}
// top == -1 이면 비어있음

int stackFull(Array *s)
{
    return (s->top == SIZE - 1);
}
// top이 마지막 칸까지 올라갔는지 확인

void push(Array *s, int value)
{
    if (stackFull(s))
    {
        printf("Stack is full\n"); // 포화상태
    }
    s->arr[++(s->top)] = value; // 포화x->배열인덱스 증가시켜서 top에 값 넣음
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