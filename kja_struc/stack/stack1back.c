#include <stdio.h>
#include <string.h>

typedef struct
{
    char data[51];
    int top;
} Stack;

void init(Stack *s)
{
    s->top = -1;
} // 스택 초기화

int is_empty(Stack *s)
{
    return s->top == -1;
} // 스택이 비어있는지 확인

void push(Stack *s, char c)
{
    s->data[++(s->top)] = c;
}

char pop(Stack *s)
{
    if (is_empty(s))
        return 0;
    return s->data[(s->top)--];
}

int check_valid(char *str)
{
    Stack s;
    init(&s);

    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == '(')
        {
            push(&s, '(');
        }
        else if (str[i] == ')')
        {
            if (is_empty(&s))
                return 0; // 스택이 비엇으면 짝이 없어서 탈락
            pop(&s);
        }
    }
    return is_empty(&s); // 스택 비어야 올바른 괄호열
}

int main()
{
    int T;
    char ps[100][51];

    scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {
        scanf("%s", ps[i]);
    }

    for (int i = 0; i < T; i++)
    {
        if (check_valid(ps[i]))
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }

    return 0;
}
