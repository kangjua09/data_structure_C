#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printStrings(char arr[][21], int n);
int compare(const void* a, const void* b);

int main() {
    int n;
    char arr[20][21];

    FILE* file = fopen("f1.txt", "r");
    if (file == NULL) {
        printf("Failed to open file.\n");
    }
    fscanf(file, "%d", &n);
	for (int i = 0; i < n; i++) {
		fscanf(file, "%s", arr[i]);
	}
    
    qsort(arr, n, sizeof(arr[0]), compare);
    
    fclose(file);
    printStrings(arr, n);
    return 0;
}

void printStrings(char arr[][21], int n) {

	for (int i = 0; i < n; i++) {
		printf("%s ", arr[i]);
	}
}

int compare(const void* a, const void* b) {
	const char* str1 = (const char*)a;
	const char* str2 = (const char*)b;
	return strcmp(str1, str2);
}