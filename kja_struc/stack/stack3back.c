#include <stdio.h>
#include <string.h>

typedef struct
{
    char data[100];
    int top;
} Stack;

void init(Stack *s)
{
    s->top = -1;
}

int is_empty(Stack *s)
{
    return s->top == -1;
}

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

int check_palindrome(char *str)
{
    Stack s;
    init(&s);

    int len = strlen(str);

    // 모든 문자 push
    for (int i = 0; i < len; i++)
    {
        push(&s, str[i]);
    }

    // 앞에서부터 하나씩 비교
    for (int i = 0; i < len; i++)
    {
        if (str[i] != pop(&s))
        {
            return 0;
        }
    }

    return 1;
}

int main()
{
    int n;
    char arr[100][100];

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", arr[i]);
    }

    for (int i = 0; i < n; i++)
    {
        if (check_palindrome(arr[i]))
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }

    return 0;
}
