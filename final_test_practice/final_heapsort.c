//2023015950 - »≤¡÷«ı

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SWAP(x,y,temp) temp = y; y = x; x = temp;

typedef struct {
	int schNum;
	char name[10];
	int grade;
} Element;

void adjust(Element a[], int root, int n);
void heapSort(Element a[], int n);

int main() {
	FILE* fp = fopen("in1.txt", "r");
    int top = -1;
    int size = 5;
    Element* heap = (Element*)malloc(sizeof(Element) * size);
    int cnt = 0;
    while (fscanf(fp, "%d %s %d", &heap[cnt].schNum, heap[cnt].name, &heap[cnt].grade) != EOF) {
        cnt++;
        if (cnt >= size) {
            size *= 2;
            Element* temp = realloc(heap, sizeof(Element) * size);
            heap = temp;
        }
    }

    heapSort(heap, cnt);

    for (int i = 0; i < cnt; i++) {
        printf("%d %s %d\n", heap[i].schNum, heap[i].name, heap[i].grade);
    }

}

void adjust(Element a[], int root, int n) {
    int child, rootintKey;
    Element temp;
    temp = a[root];
    rootintKey = a[root].grade;
    child = 2 * root + 1;
    while (child < n) {
        if (child < n - 1 && a[child].grade > a[child + 1].grade)
            child++;
        if (rootintKey <= a[child].grade) {
            break;
        }
        else {
            a[(child - 1) / 2] = a[child];
            child = 2 * child + 1;
        }
    }
    a[(child - 1) / 2] = temp;
    if (a[(child - 1) / 2 + 1].grade == temp.grade) {
        Element tmp;
        tmp = a[(child - 1) / 2];
        a[(child - 1) / 2] = a[(child - 1) / 2 + 1];
        a[(child - 1) / 2 + 1] = tmp;
    }
}


void heapSort(Element a[], int n) {
    int i;
    Element temp;

    for (i = n / 2 - 1; i >= 0; i--) {
        adjust(a, i, n);
    }
    for (i = n - 1; i > 0; i--) {
        SWAP(a[0], a[i], temp);
        adjust(a, 0, i);
    }
}
