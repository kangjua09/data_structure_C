#define _CRT_SECURE_NO_WARNINGS
#define MAX_STACK_SIZE 100
#define MAX_EXPR_SIZE 100
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum
{
    lparen,
    rparen,
    plus,
    minus,
    times,
    divide,
    mod,
    eos,
    operand
} precedence;

char expr[MAX_EXPR_SIZE];
char postfix_expr[MAX_EXPR_SIZE];
int stack[MAX_STACK_SIZE];
int top;

int isp[] = {0, 19, 12, 12, 13, 13, 13, 0};
int icp[] = {20, 19, 12, 12, 13, 13, 13, 0};

int eval();
precedence getToken(char *symbol, int *n);
void postfix();

void push(int item)
{
    if (top >= MAX_STACK_SIZE - 1)
    {
        fprintf(stderr, "Stack is full.\n");
        exit(EXIT_FAILURE);
    }
    stack[++top] = item;
}

int pop()
{
    if (top < 0)
    {
        fprintf(stderr, "Stack is empty.\n");
        exit(EXIT_FAILURE);
    }
    return stack[top--];
}

int eval(void)
{
    precedence token;
    char symbol;
    int op1, op2;
    int n = 0;
    top = -1;

    token = getToken(&symbol, &n);
    while (token != eos)
    {
        if (token == operand)
            push(symbol - '0');
        else
        {
            op2 = pop();
            op1 = pop();
            switch (token)
            {
            case plus:
                push(op1 + op2);
                break;
            case minus:
                push(op1 - op2);
                break;
            case times:
                push(op1 * op2);
                break;
            case divide:
                push(op1 / op2);
                break;
            case mod:
                push(op1 % op2);
                break;
            default:
                break;
            }
        }
        token = getToken(&symbol, &n);
    }
    return pop();
}

precedence getToken(char *symbol, int *n)
{
    *symbol = expr[(*n)++];
    switch (*symbol)
    {
    case '(':
        return lparen;
    case ')':
        return rparen;
    case '+':
        return plus;
    case '-':
        return minus;
    case '/':
        return divide;
    case '*':
        return times;
    case '%':
        return mod;
    case '\0':
        return eos;
    default:
        return operand;
    }
}

void postfix(void)
{
    char symbol;
    precedence token;
    int n = 0;
    int post_idx = 0;
    top = 0;
    stack[0] = eos;

    for (token = getToken(&symbol, &n); token != eos; token = getToken(&symbol, &n))
    {
        if (token == operand)
        {
            postfix_expr[post_idx++] = symbol;
        }
        else if (token == rparen)
        {
            while (stack[top] != lparen)
            {
                precedence p = (precedence)pop();
                if (p == plus)
                    postfix_expr[post_idx++] = '+';
                else if (p == minus)
                    postfix_expr[post_idx++] = '-';
                else if (p == times)
                    postfix_expr[post_idx++] = '*';
                else if (p == divide)
                    postfix_expr[post_idx++] = '/';
                else if (p == mod)
                    postfix_expr[post_idx++] = '%';
            }
            pop();
        }
        else
        {
            while (isp[stack[top]] >= icp[token])
            {
                precedence p = (precedence)pop();
                if (p == plus)
                    postfix_expr[post_idx++] = '+';
                else if (p == minus)
                    postfix_expr[post_idx++] = '-';
                else if (p == times)
                    postfix_expr[post_idx++] = '*';
                else if (p == divide)
                    postfix_expr[post_idx++] = '/';
                else if (p == mod)
                    postfix_expr[post_idx++] = '%';
            }
            push(token);
        }
    }

    while ((token = (precedence)pop()) != eos)
    {
        if (token == plus)
            postfix_expr[post_idx++] = '+';
        else if (token == minus)
            postfix_expr[post_idx++] = '-';
        else if (token == times)
            postfix_expr[post_idx++] = '*';
        else if (token == divide)
            postfix_expr[post_idx++] = '/';
        else if (token == mod)
            postfix_expr[post_idx++] = '%';
    }
    postfix_expr[post_idx] = '\0';
}

int main()
{
    FILE *file;
    char line[MAX_EXPR_SIZE];

    file = fopen("in21.txt", "r");
    if (file == NULL)
    {
        fprintf(stderr, "파일열기실패\n");
        return 1;
    }
    while (fscanf(file, "%s", expr) != EOF)
    {
        postfix();
        printf("%s\n", postfix_expr);
        strcpy(expr, postfix_expr);
        printf("%d\n", eval());
    }
    fclose(file);

    file = fopen("in22.txt", "r");
    if (file == NULL)
    {
        fprintf(stderr, "파일열기실패2\n");
        return 1;
    }
    while (fscanf(file, "%s", expr) != EOF)
    {
        postfix();
        printf("%s\n", postfix_expr);
        strcpy(expr, postfix_expr);
        printf("%d\n", eval());
    }
    fclose(file);

    return 0;
}