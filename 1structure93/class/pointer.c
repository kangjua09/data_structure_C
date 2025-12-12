#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* createArray(int size) {
    int *array = (int *)malloc(size *sizeof(int));
    if(array == NULL) {
        return NULL;
    }

    srand(time(NULL));

    for(int i=0; i<size; i++) {
        array[i]= rand() % 100 + 1;
    }

    return array;
}

void printArray(int *array, int size) {
    for(int i=0; i<size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}
void printSumAndAverage(int * array, int size) {
    int sum = 0;
    sum =+ *array;
}

int main() {
    int size;
    printf("Enter size: ");
    scanf("%d", &size);

    int* arr = createArray(size);
    if(arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printArray(arr, size);
    printSumAndAverage(arr, size);

    free(arr);

    return 0;
}