#include <stdio.h>

double sumArray(double arr[], int size) { 
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

double averageArray(double arr[], int size) {
    return sumArray(arr, size) / size;
}

int main() {
    double array[10];
    int size = 10;

    for (int i = 0; i < size; i++) {
        scanf("%lf", &array[i]);
    }

    double sum = sumArray(array, size);
    double avg = averageArray(array, size);

    printf("합= %.2lf 평균= %.2lf\n", sum, avg);

    return 0;
}

/*
arr[]는 사실상 double *arr와 동일함
즉, 함수 안에서는 배열의 "시작 주소"만 알 수 있고, 원래 몇 개짜리 배열인지 알 수 없음
그래서 몇 개 원소를 합산할지 알려주기 위해 size를 인자로 따로 넘겨주는 거임
*/