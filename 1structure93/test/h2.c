#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void input(double* arr, int n);
int search(double* arr, int n, double data);
void output(double* arr, int n);

FILE* file;

int main() {
    int n;

    file = fopen("f2.txt", "r");
    if (file == NULL) {
        printf("Failed to open file.\n");
    }


    fscanf(file, "%d", &n);
    double* arr = malloc(n * sizeof(double));
    input(arr, n);
    output(arr, n);

    fclose(file);
    free(arr);
}

void input(double* arr, int n) {

    for(int i=0; i<n; i++) {
        fscanf(file,"%lf", &arr[i]);
    }
    return;
}

void output(double* arr, int n) {
    double num;
    scanf("%lf", &num);
    printf("index = %d", search(arr, n, num));
}

int search(double* arr, int n, double data) {
    for(int i=0;i<n;i++) {
        if(data == arr[i])
            return i;
    }
    return -1;
}