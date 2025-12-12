#include <stdio.h>

int count(FILE* f);
int sum(FILE* f);

int main() {
    FILE* f = fopen("output.txt", "r");

    if(f == NULL) {
        printf("Failed to open file.\n");
        return 1;
    }

    int countResult = count(f);
    printf("Numbeer of data: %d\n", countResult);

    fseek(f, 0, SEEK_SET);

    int totalSum = sum(f);
    printf("Cumulative sum: %d\n", totalSum);

    fclose(f);

    return 0;
}




#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int count(FILE* file);
int sum(FILE* file);

int main()
{
    FILE* file = fopen("output.txt", "w");

    if (file == NULL) {
        printf("Failed to open file.\n");
        return 1;
    }

    srand(time(NULL));

    for (int i = 0; i < 10000; i++) {
        fprintf(file, "%d\n", rand());
    }

    fclose(file);
    printf("Done.\n");

    file = fopen("output.txt", "r");
    if (file == NULL) {
        printf("Failed to open file.\n");
        return 1;
    }

    int countResult = count(file);
    rewind(file); 
    int totalSum = sum(file);

    printf("Number of data : %d\n", countResult);
    printf("Cumulative sum : %d\n", totalSum);

    fclose(file);
    return 0;
}

int count(FILE* file)
{
    int num;
    int cnt = 0;
    while (fscanf(file, "%d", &num) == 1) {
        cnt++;
    }
    return cnt;
}

int sum(FILE* file)
{
    int num;
    int total = 0;
    while (fscanf(file, "%d", &num) == 1) {
        total += num;
    }
    return total;
}