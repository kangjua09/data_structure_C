#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// O(n1+n2) 시간 복잡도를 만족하는 교집합 출력 함수
void printIntersect_str(char **arr1, int n1, char **arr2, int n2);

// 파일에서 문자열을 읽어 동적 배열을 생성하는 헬퍼 함수
char **load_strings(FILE *file, int *count);

// 2단계로 할당된 메모리를 해제하는 함수
void free_list(char **list, int n);

int main()
{
    int n1 = 0, n2 = 0; // 실제 데이터 개수

    // --- file1 읽기 ---
    FILE *file1 = fopen("f3_1.txt", "r");
    if (file1 == NULL)
    {
        printf("fail\n");
        return 1;
    }
    char **list1 = load_strings(file1, &n1);

    // --- file2 읽기 ---
    FILE *file2 = fopen("f3_2.txt", "r");
    if (file2 == NULL)
    {
        printf("fail\n");
        free_list(list1, n1); // 이전에 할당된 list1 해제
        return 1;
    }
    char **list2 = load_strings(file2, &n2);

    // --- 파일 닫기 및 처리 ---
    fclose(file1);
    fclose(file2);

    printIntersect_str(list1, n1, list2, n2);

    // --- 메모리 해제 ---
    free_list(list1, n1);
    free_list(list2, n2);
    return 0;
}

/**
 * [realloc 로직 구현 함수 - 문자열 버전]
 * 파일을 읽으면서 10단위로 배열 크기를 확장합니다.
 */
char **load_strings(FILE *file, int *count)
{
    int n = 0;             // 현재 데이터 개수
    int capacity = 10;     // 초기 용량 (10)
    char temp_buffer[256]; // 문자열 임시 저장소

    // 1. (1단계 할당) 초기 10개 크기의 "포인터 목록" 할당
    char **list = (char **)malloc(capacity * sizeof(char *));
    if (list == NULL)
    {
        fprintf(stderr, "Initial malloc failed\n");
        exit(1);
    }

    // 2. 파일 끝(EOF)까지 문자열 1개씩 읽기
    while (fscanf(file, "%s", temp_buffer) == 1)
    {
        // 3. realloc 검사: 개수가 용량과 같아지면 확장
        if (n == capacity)
        {
            capacity += 10; // 용량을 10 늘림 (10 -> 20 -> 30 ...)

            // (1단계 realloc) "포인터 목록"의 크기를 늘림
            char **temp_list = (char **)realloc(list, capacity * sizeof(char *));
            if (temp_list == NULL)
            {
                fprintf(stderr, "Realloc failed\n");
                free_list(list, n); // 실패 시 이전 메모리 해제
                exit(1);
            }
            list = temp_list; // 새 주소로 갱신
        }

        // 4. (2단계 할당) "개별 문자열"을 저장할 공간을 malloc
        list[n] = (char *)malloc(strlen(temp_buffer) + 1);
        if (list[n] == NULL)
        {
            fprintf(stderr, "String malloc failed\n");
            free_list(list, n);
            exit(1);
        }
        // 임시 저장소에서 실제 메모리로 문자열 복사
        strcpy(list[n], temp_buffer);

        n++; // 데이터 개수 증가
    }

    *count = n;  // 최종 데이터 개수를 main의 변수(n1, n2)에 저장
    return list; // 최종 배열의 주소 반환
}

/**
 * [교집합 출력 함수 - O(n1+n2) - 문자열 버전]
 */
void printIntersect_str(char **arr1, int n1, char **arr2, int n2)
{
    int i = 0, j = 0;
    while (i < n1 && j < n2)
    {
        // strcmp를 사용하여 사전 순으로 비교
        int cmp = strcmp(arr1[i], arr2[j]);

        if (cmp == 0) // 같으면 출력 (교집합)
        {
            printf("%s ", arr1[i]);
            i++;
            j++;
        }
        else if (cmp < 0) // arr1이 앞서면 arr1 이동
        {
            i++;
        }
        else // arr2가 앞서면 arr2 이동
        {
            j++;
        }
    }
    printf("\n");
}

/**
 * [메모리 해제 함수 - 문자열 버전]
 */
void free_list(char **list, int n)
{
    // 1. (2단계 해제) 개별 문자열들을 먼저 해제
    for (int i = 0; i < n; i++)
    {
        free(list[i]);
    }
    // 2. (1단계 해제) 포인터 목록을 마지막에 해제
    free(list);
}