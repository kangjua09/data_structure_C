#include <stdio.h>

void fillArray(int table[][4], int muRows, int numCols);
void printfArray(int table[][4], int numRows, int muCols);

int main() {
    int table [5][4] = {0}; // original data 0밖에 없는거 or 직접 작성해도됨.
    printfArray(ary, 5, 4);
    printf("\n");

    fillArray(ary, 5);
    printArray(ary, 5, 4);

    return 0;
}

void fillArray(int table[][4], int numRows) {
    for(int row =0; row<numRows; row++) {
        table[row][0] = row * 10;
        for(int col = 1; col<4; col++) {
            table[row][col] = table[row][col-1] +1;
        }
    }
}

