/*
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

polynomial terms[MAX_TERMS];
int avail = 0;

void readPoly(FILE *file, int *start, int *finish);
void attach(float coefficient, int exponent);
void printPoly(int start, int finish);
void padd(int starta, int finisha, int startb, int finishb, int *startd, int *finishd);
float evalPoly(int startD, int finishD, float x);

int main()
{
    float x;
    int startA, startB, startD;
    int finishA, finishB, finishD;

    FILE *file = fopen("f1.txt", "r");
    if (file == NULL)
    {
        printf("Failed to open file.\n");
        exit(1);
    }

    readPoly(file, &startA, &finishA);
    readPoly(file, &startB, &finishB);

    printf("A(x) = ");
    printPoly(startA, finishA);

    printf("B(x) = ");
    printPoly(startB, finishB);

    padd(startA, finishA, startB, finishB, &startD, &finishD);

    printf("D(x) = ");
    printPoly(startD, finishD);

    printf("x : ");
    scanf("%f", &x);

    float value = evalPoly(startD, finishD, x);
    printf("D(%.2f) = %.2f\n", x, value);

    fclose(file);
    return 0;
}

void readPoly(FILE *file, int *start, int *finish)
{
    int n;
    float coef;
    int expon;
    fscanf(file, "%d", &n);

    *start = avail;
    for (int i = 0; i < n; i++)
    {
        fscanf(file, "%f %d", &coef, &expon);
        attach(coef, expon);
    }
    *finish = avail - 1;
}

void attach(float coefficient, int exponent)
{
    if (avail >= MAX_TERMS)
    {
        fprintf(stderr, "Too many terms in the polynomial\n");
        exit(EXIT_FAILURE);
    }
    terms[avail].coef = coefficient;
    terms[avail++].expon = exponent;
}

void printPoly(int start, int finish)
{
    for (int i = start; i <= finish; i++)
    {
        printf("%.0fx^%d", terms[i].coef, terms[i].expon);
        if (i < finish)
            printf(" + ");
    }
    printf("\n");
}

void padd(int starta, int finisha, int startb, int finishb, int *startd, int *finishd)
{
    float coefficient;
    *startd = avail;

    while (starta <= finisha && startb <= finishb)
    {
        switch (COMPARE(terms[starta].expon, terms[startb].expon))
        {
        case -1:
            attach(terms[startb].coef, terms[startb].expon);
            startb++;
            break;
        case 0:
            coefficient = terms[starta].coef + terms[startb].coef;
            if (coefficient)
                attach(coefficient, terms[starta].expon);
            starta++;
            startb++;
            break;
        case 1:
            attach(terms[starta].coef, terms[starta].expon);
            starta++;
        }
    }

    for (int i = starta; i <= finisha; i++)
    {
        attach(terms[i].coef, terms[i].expon);
    }

    for (int j = startb; j <= finishb; j++)
    {
        attach(terms[j].coef, terms[j].expon);
    }

    *finishd = avail - 1;
}

float evalPoly(int start, int finish, float x)
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
*/

#define _CRT_SECURE_NO_WARNINGS
#define MAX_TERMS 100
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct
{
    float coef;
    int expon;
} polynomial;

polynomial terms[MAX_TERMS];
int avail = 0;

void readPoly(FILE *file, int *start, int *finish);
void attach(float coefficient, int exponent);
void printPoly(int start, int finish);

int main()
{

    FILE *file = fopen("f1.txt", "r");
    if (file == NULL)
    {
        printf("fail\n");
        return 1;
    }
}

void readPoly(FILE *file, int *start, int *finish)
{
    int degree;
    float coef;
    int expon;
    *start = avail;
    for (int i = 0; i < degree; i++)
    {
        fscanf(file, "%f %d", &coef, &expon);
        attach(coef, expon);
    }
    *finish = avail - 1;
}

void attach(float coefficient, int exponent)
{
    if (avail >= MAX_TERMS)
    {
        fprintf(stderr, "Too many terms in the polynomial\n");
        exit(EXIT_FAILURE);
    }
    terms[avail].coef = coefficient;
    terms[avail++].expon = exponent;
}