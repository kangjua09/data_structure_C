#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void* a, const void* b);
// void* 어느 자료형이든 가능

int main() {
    char arr[][10] = { "banana", "apple", "orange", "mango", "lemon"};
    int n = sizeof(arr) / sizeof(arr[0]);

    qsort(arr, n, sizeof(arr[0]), compare);

    for(int i=0; i<n; i++) {
        printf("%s\n", arr[i]);
    }

    return 0;
}

int compare(const void* a, const void* b) {
    // a, b는 각각 문자열(char[10]의 시작 주소
    const char* str1 = (const char*)a;
    const char* str2 = (const char*)b;

    return strcmp(str1, str2);
}