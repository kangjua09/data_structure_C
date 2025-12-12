#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

FILE* file;

int** build2DArray(int rows, int cols);
void input(int** ary, int rows, int cols);
double calculate(int** ary, int rows, int cols);

int main() {
    int rows, cols;
    file = fopen("f3.txt", "r");
    if (file == NULL) {
        printf("Failed to open file.\n");
    }

    fscanf(file, "%d %d", &rows, &cols);
    int** ary = build2DArray(rows, cols);
    input(ary, rows, cols);
    printf("표준편차 = %.2lf", calculate(ary, rows, cols));

    for(int i = 0; i<rows; i++) {
        free(ary[i]);
    }
    free(ary);
    fclose(file);

    return 0;
}

int** build2DArray(int rows, int cols) {
    int** ary = calloc(rows, sizeof(int*));
    for(int i=0; i< rows; i++) {
        ary[i] = calloc(rows, sizeof(int));
    }
    return ary;
}

void input(int** ary, int rows, int cols) {
    for(int i=0;i<rows;i++) {
        for(int k=0;k<cols;k++) {
            fscanf(file, "%d", &ary[i][k]);
        }
    }
}

double calculate(int** ary, int rows, int cols) {
    double sum=0;
    for(int i=0; i<rows; i++) {
        for(int k=0; k<cols; k++) {
            sum += ary[i][k];
        }
    }
    double average = sum / (cols*rows);
    double t, tsum=0;
    for(int i=0; i<rows; i++) {
        for(int k=0; k<cols; k++) {
            t = (ary[i][k] - average)*(ary[i][k] - average);
            //t = ((double)ary[i][k] - average)*((double)ary[i][k] - average);
            tsum += t;
        }
    }
    // double average2 = tsum / (double)(cols*rows);
    // double cal = sqrt(average2);

    return sqrt(tsum/(cols*rows));
}