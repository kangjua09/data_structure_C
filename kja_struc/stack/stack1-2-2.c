#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

int eval(char exp[])
{
    int op1, op2, value;
    char ch;
    int len = strlen(exp);

    StackType s;
    init(&s);

    for (int i = 0; i < len; i++)
    {
        ch = exp[i];
        if (ch != '+' && ch != '-' && ch != '*' && ch != '/')
        {
            value = ch - '0'; // 문자 ->숫자
            push(&s, value);
        }
        else
        {
            op2 = pop(&s);
            op1 = pop(&s);
            switch (ch)
            {
            case '+':
                push(&s, op1 + op2);
                break;
            case '-':
                push(&s, op1 - op2);
                break;
            case '*':
                push(&s, op1 * op2);
                break;
            case '/':
                push(&s, op1 / op2);
                break;
            }
        }
    }
    return pop(&s);
}
int prec(char op)
{
    switch (op)
    {
    case '(':
    case ')':
        return 0;
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    }
    return -1;
}

void infix_to_postfix(char exp[])
{
    char ch, top_op;
    int len = strlen(exp);
    StackType s;
    init_stack(&s);

    for (int i = 0; i < len; i++)
    {
        ch = exp[i];
        switch (ch)
        {
        case '+':
        case '-':
        case '*':
        case '/':
            while (!is_empty(&s) && prec(ch) <= prec(peek(&s)))
                printf("%c", pop(&s));
            push(&s, ch);
            break;
        case '(':
            push(&s, ch);
            break;
        case ')':
            top_op = pop(&s);
            while (top_op != '(')
            {
                printf("%c", top_op);
                top_op = pop(&s);
            }
            break;
        default:
            printf("%c", ch);
            break;
        }
    }
    while (!is_empty(&s))
        printf("%c", pop(&s));
}

int main()
{
    int result;
    result = eval("82/3-32*+");
    printf("--> %d", result);

    return 0;
}