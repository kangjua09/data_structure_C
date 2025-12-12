#define MAX_SIZE 100  // 배열의 최대크기
#include <stdio.h>

void inputScores(int scores[], int size) {
    for(int i=0; i<size; i++)
        scanf("%d", &scores[i]);
}

void printScores(int scores[], int size) {
    for(int i=0;i<size;i++)
        printf("%d ", scores[i]);
}

int findMax(int scores[], int size) { // max/min을 scores[0]으로 다시 설정해서, 첫 번째와 마지막 값만 비교한 결과가 나옵니다.
    int max= scores[0];
    for(int i=0; i<size; i++) {
        if(max < scores[i])
            max = scores[i];
    }
    return max;
}
int findMin(int scores[], int size) {
    int min = scores[0];
    for(int i=0; i<size; i++) {
        if(min > scores[i])
            min = scores[i];
    }
    return min;
}

int main() {
    int scores[MAX_SIZE];
    int size = 5;
    printf("Enter 5 scores:\n");
    inputScores(scores, size);
    printf("Scores: ");
    printScores(scores, size);
    printf("\n");
    printf("Hightes score: %d\nLowest score: %d", findMax(scores, size), findMin(scores, size));

    return 0;
}