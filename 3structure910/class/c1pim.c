#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr = (int *)malloc(3 * sizeof(int));
    if(arr ==NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return 1;
    }

    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;

    arr[3] = 40;

    printf("%d %d %d %d\n", arr[0], arr[1], arr[2], arr[3]);

    free(arr);

    return 0;
}