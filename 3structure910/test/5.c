/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 반환형이 int일 때 오버플로 없이 계산 가능한 최대 n = 46

int fibonacci(int n);

int main() {
    int n;
    while(scanf("%d", &n) == 1) {
        if(n<0 || n>46)
            continue;
        printf("%d\n", fibonacci(n));
    }
    return 0;
}

int fibonacci(int n) {
    if (n <= 1)
        return n;
    return fibonacci(n-1) + fibonacci(n-2);
}
    */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int fibonacci(int n);

int main()
{
    int n;
    while (scanf("%d", &n) == 1)
    {
        if (n < 0 || n > 46)
            continue;
        else
            printf("%d", fibonacci(n));
    }
    return 0;
}

int fibonacci(int n)
{
    if (n <= 1)
        return n;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}