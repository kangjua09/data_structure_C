#define _CRT_SECURE_NO_WARNINGS
#define SIZE 10000
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void createfile(const char* filename);
void storage(const char* filename, int arr[]);
int findMax(int arr[]);
int findMin(int arr[]);

int main() {
    const char* filename = "f1.txt";
    int arr[SIZE];

    createfile(filename);
    storage(filename, arr); 
    printf("최대값 = %d\n", findMax(arr));
    printf("최소값 = %d\n", findMin(arr));

    return 0;
}

void createfile(const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Failed to open file.\n");
    }

    srand(time(NULL));

    for (int i = 0; i < SIZE; i++) {
        fprintf(file, "%d\n", rand()%10000);
    }

    fclose(file);
    printf("Done.\n");
}

void storage(const char* filename, int arr[]) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Failed to open file.\n");
    }
    
    for(int i=0; i<SIZE; i++) {
        fscanf(file,"%d", &arr[i]);
    }

    fclose(file);
}

int findMax(int arr[]) { // max/min을 scores[0]으로 다시 설정해서, 첫 번째와 마지막 값만 비교한 결과가 나옵니다.
    int max= arr[0];
    for(int i=1; i<SIZE ; i++) {
        if(max < arr[i])
            max = arr[i];
    }
    return max;
}

int findMin(int arr[]) {
    int min = arr[0];
    for(int i=1; i<SIZE; i++) {
        if(min > arr[i])
            min = arr[i];
    }
    return min;
}

