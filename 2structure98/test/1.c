#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printStrings(char* p[], int n);
void freeMemory(char* p[], int n);

int main() {
    int n;
    char** p;
    char k[100];

    FILE* file = fopen("f1.txt", "r");
    if (file == NULL) {
        printf("Failed to open file.\n");
    }

    fscanf(file, "%d", &n);
    p = (char**)malloc(n * sizeof(char*));
	for (int i = 0; i < n; i++) {
		fscanf(file, "%99s", k);
		p[i] = (char*)malloc(strlen(k) + 1);
        if (p[i] != NULL) {
			strcpy(p[i], k);
		}
	}
    
    fclose(file);
    printStrings(p, n);
    freeMemory(p, n);
    free(p);

    return 0;
}

void printStrings(char* p[], int n) {
    for(int i=0; i<n;i++) {
        printf("%s ", p[i]);
    }
}

void freeMemory(char* p[], int n) {
    for(int i=0; i< n; i++) {
        free(p[i]);
    }
}
