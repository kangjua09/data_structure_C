#include <stdio.h>

int squaure(int n) {
    return n*n;
}

int main() {
    int n;
    printf("Enter an integer: ");
    scanf("%d", &n);
    printf("%d^2 = %d", n, squaure(n));
    return 0;
}