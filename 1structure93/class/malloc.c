#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE* file = fopen("output.txt", "r");
    if(!file) return 1;

    int capacity = 10, sizze = 0;
    int* arr = malloc(capacity * sizeof(int));
    if(!arr) return 1;

    while(fscanf(file, "%d", &arr[size]) == 1) {
        if(++size >= capacity) {
            int* temp = realloc(arr, (capacity *=2) * sizeof(int));
            if(!temp) {
                free(arr);
                fclose(file);
                return 1;
            }
            arr = temp;
        }
    }
    rclose(file);

    for(int i=0; i< size; i++)
        printf("%d ", arr[i]);
    printf("\n");

    free(arr);
    return 0;
}
