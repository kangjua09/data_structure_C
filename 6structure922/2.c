#define _CRT_SECURE_NO_WARNINGS
#define MAX_TERMS 100
#define COMPARE(x, y) (((x) < (y)) ? -1 : ((x) == (y) ? 0 : 1))
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    float coef;
    int expon;
} polynomial;

// 함수 원형
void readPoly(FILE *file, polynomial terms[], int *avail, int *start, int *finish);
void attach(polynomial terms[], int *avail, float coefficient, int exponent);
void printPoly(polynomial terms[], int start, int finish);
void padd(polynomial terms[], int *avail, int starta, int finisha, int startb, int finishb, int *startd, int *finishd);
float evalPoly(polynomial terms[], int start, int finish, float x);

int main()
{
    polynomial terms[MAX_TERMS];
    int avail = 0;

    int startA, finishA, startB, finishB, startD, finishD;
    float x;

    FILE *file = fopen("f1.txt", "r");
    if (file == NULL)
    {
        printf("Failed to open file.\n");
        exit(1);
    }

    readPoly(file, terms, &avail, &startA, &finishA);
    readPoly(file, terms, &avail, &startB, &finishB);
    fclose(file);

    printf("A(x) = ");
    printPoly(terms, startA, finishA);

    printf("B(x) = ");
    printPoly(terms, startB, finishB);

    padd(terms, &avail, startA, finishA, startB, finishB, &startD, &finishD);

    printf("D(x) = ");
    printPoly(terms, startD, finishD);

    printf("x : ");
    scanf("%f", &x);

    float value = evalPoly(terms, startD, finishD, x);
    printf("D(%.2f) = %.2f\n", x, value);

    return 0;
}

// 다항식 입력
void readPoly(FILE *file, polynomial terms[], int *avail, int *start, int *finish)
{
    int n;
    fscanf(file, "%d", &n);

    *start = *avail;
    for (int i = 0; i < n; i++)
    {
        float coef;
        int expon;
        fscanf(file, "%f %d", &coef, &expon);
        attach(terms, avail, coef, expon);
    }
    *finish = *avail - 1;
}

// 항 추가
void attach(polynomial terms[], int *avail, float coefficient, int exponent)
{
    if (*avail >= MAX_TERMS)
    {
        fprintf(stderr, "Too many terms in the polynomial\n");
        exit(EXIT_FAILURE);
    }
    terms[*avail].coef = coefficient;
    terms[*avail].expon = exponent;
    (*avail)++;
}

// 다항식 출력
void printPoly(polynomial terms[], int start, int finish)
{
    for (int i = start; i <= finish; i++)
    {
        printf("%.0fx^%d", terms[i].coef, terms[i].expon);
        if (i < finish)
            printf(" + ");
    }
    printf("\n");
}

// 다항식 덧셈
void padd(polynomial terms[], int *avail, int starta, int finisha, int startb, int finishb, int *startd, int *finishd)
{
    float coefficient;
    *startd = *avail;

    while (starta <= finisha && startb <= finishb)
    {
        switch (COMPARE(terms[starta].expon, terms[startb].expon))
        {
        case -1:
            attach(terms, avail, terms[startb].coef, terms[startb].expon);
            startb++;
            break;
        case 0:
            coefficient = terms[starta].coef + terms[startb].coef;
            if (coefficient)
                attach(terms, avail, coefficient, terms[starta].expon);
            starta++;
            startb++;
            break;
        case 1:
            attach(terms, avail, terms[starta].coef, terms[starta].expon);
            starta++;
            break;
        }
    }

    for (int i = starta; i <= finisha; i++)
    {
        attach(terms, avail, terms[i].coef, terms[i].expon);
    }

    for (int j = startb; j <= finishb; j++)
    {
        attach(terms, avail, terms[j].coef, terms[j].expon);
    }

    *finishd = *avail - 1;
}

// 다항식 계산
float evalPoly(polynomial terms[], int start, int finish, float x)
{
    float result = 0.0;
    for (int i = start; i <= finish; i++)
    {
        float termValue = 1.0;
        for (int j = 0; j < terms[i].expon; j++)
        {
            termValue *= x;
        }
        result += terms[i].coef * termValue;
    }
    return result;
}
