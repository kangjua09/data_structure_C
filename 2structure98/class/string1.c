#include <stdio.h>

void readStrings(char strings[][20], int size);
void printStrings(char strings[][20], int size);

int main() {
    char strings[5][20];

    readStrings(strings, 5);
    printStrings(strings, 5);

    return 0;
}

void readStrings(char strings[][20], int size) {
    for(int i=0; i<size; i++) {
        printf("%d번 문자열 (최대 19자): ", i+1);
        scanf("%19s", strings[i]);
    }
}

void printStrings(char strings[][20], int size) {
    for(int i=0; i<size; i++) {
        printf("%s\n", strings[i]);
    }
}