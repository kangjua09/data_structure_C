#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

FILE* file;

int sumAry1D(int *ary, int size);

int main() {
    int r, n, c;

    file = fopen("f4.txt", "r");
    if (file == NULL) {
        printf("Failed to open file.\n");
    }
    
    fscanf(file, "%d", &r);
    int** ary = calloc(r, sizeof(int*));
    int* len = calloc(r, sizeof(int));
    for(int i=0;i<r;i++) {
        fscanf(file, "%d", &n);
        ary[i] = calloc(n, sizeof(int));
        len[i] = n;
        for(int k=0; k<n; k++) {
        fscanf(file, "%d", &ary[i][k]);
        }
    }
    int total = 0;
    for(int i=0;i<r;i++) {
        printf("%d\n", sumAry1D(ary[i], len[i]));
        total += sumAry1D(ary[i], len[i]);
    }
    printf("배열 합 = %d", total);
    
    fclose(file);
    for(int i=0;i<r;i++)
        free(ary[i]);
    free(ary);
    free(len);

    return 0;
}

int sumAry1D(int *ary, int size) {
    int sum = 0;
    for(int i=0; i<size; i++) {
        sum += ary[i];
    }
    return sum;
}