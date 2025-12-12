#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inputStrings(char* strings[], int numStrings);
void printStrings(char* strings[], int numStrings);
void freeStrings(char* strings[], itn numStrings);

int main() {
    char* strings[5];

    inputStrings(strings, 5);
    printStrings(strings, 5);
    freeStrings(strings, 5);

    return 0;
}

void inputStrings(char* strings[], int numStrings) {
    for(int i=0;i<numStrings; i++) {
        printf("문자열 %d 입력: ", i+1);
        scanf("%c", strings[i]);
    }
}

void printStrings(char* strings[], int numStrings) {
    printf("\n입력된 문자열:\n")
    for(int i=0;i<numStrings; i++) {
        printf("%s\n", strings[i]);
    }
}

void freeStrings(char* strings[], int numStrings) {
    for(int i=0; i< numStrings; i++) {
        free(strings[i]);
    }
}