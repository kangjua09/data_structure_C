#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode
{
    int coef;  // 계수
    int expon; // 차수
    struct ListNode *link;
} ListNode;

// 리스트의 끝에 새로운 항을 추가하는 함수
void insert_last(ListNode **head, ListNode **tail, int coef, int expon)
{
    // 계수가 0이면 항을 추가하지 않음
    if (coef == 0)
    {
        return;
    }

    ListNode *new_node = (ListNode *)malloc(sizeof(ListNode));
    if (new_node == NULL)
    {
        fprintf(stderr, "메모리 할당 오류\n");
        return;
    }
    new_node->coef = coef;
    new_node->expon = expon;
    new_node->link = NULL;

    if (*head == NULL)
    { // 리스트가 비어있을 경우
        *head = new_node;
        *tail = new_node;
    }
    else
    { // 리스트에 노드가 있을 경우
        (*tail)->link = new_node;
        *tail = new_node;
    }
}

// 파일에서 다항식을 읽어 연결 리스트로 생성하는 함수
ListNode *read_poly(FILE *fp)
{
    ListNode *head = NULL;
    ListNode *tail = NULL;
    int n, c, e;

    // 1. 항의 개수(n) 읽기
    if (fscanf(fp, "%d", &n) != 1)
    {
        return NULL; // 파일 읽기 실패
    }

    // 2. n개의 (계수, 차수) 쌍 읽기
    for (int i = 0; i < n; i++)
    {
        if (fscanf(fp, "%d %d", &c, &e) != 2)
        {
            return head; // 파일 형식 오류
        }
        // 리스트의 끝에 항 추가
        insert_last(&head, &tail, c, e);
    }
    return head;
}

// 다항식 뺄셈 (C = A - B)을 수행하는 함수
ListNode *poly_sub(ListNode *polyA, ListNode *polyB)
{
    ListNode *headC = NULL; // 결과 다항식 C의 헤드
    ListNode *tailC = NULL; // 결과 다항식 C의 테일
    ListNode *pA = polyA;   // A를 순회하는 포인터
    ListNode *pB = polyB;   // B를 순회하는 포인터
    int diff_coef;

    // A와 B 리스트를 동시에 순회
    while (pA != NULL && pB != NULL)
    {
        if (pA->expon > pB->expon)
        {
            // Case 1: A의 차수가 더 높음 (A항만 존재)
            // A의 항을 그대로 C에 추가
            insert_last(&headC, &tailC, pA->coef, pA->expon);
            pA = pA->link;
        }
        else if (pA->expon < pB->expon)
        {
            // Case 2: B의 차수가 더 높음 (B항만 존재)
            // (A - B)이므로, B의 계수 부호를 바꿔 C에 추가
            insert_last(&headC, &tailC, -pB->coef, pB->expon);
            pB = pB->link;
        }
        else
        {                                    // Case 3: A와 B의 차수가 같음
            diff_coef = pA->coef - pB->coef; // 계수 뺄셈
            insert_last(&headC, &tailC, diff_coef, pA->expon);
            pA = pA->link;
            pB = pB->link;
        }
    }

    // A에 남은 항들 처리
    while (pA != NULL)
    {
        insert_last(&headC, &tailC, pA->coef, pA->expon);
        pA = pA->link;
    }
    // B에 남은 항들 처리
    while (pB != NULL)
    {
        insert_last(&headC, &tailC, -pB->coef, pB->expon);
        pB = pB->link;
    }

    return headC;
}

// 다항식 리스트를 출력하는 함수 (문제에서 요구하는 형식)
void print_poly(ListNode *head)
{
    ListNode *p = head;
    while (p != NULL)
    {
        printf("%d %d ", p->coef, p->expon);
        p = p->link;
    }
    printf("\n");
}

// 다항식 리스트의 메모리를 해제하는 함수
void free_poly(ListNode *head)
{
    ListNode *p = head;
    while (p != NULL)
    {
        ListNode *temp = p;
        p = p->link;
        free(temp);
    }
}

// 메인 함수
int main()
{
    FILE *fp1, *fp2;
    ListNode *polyA, *polyB, *polyC;

    // 1. 파일 열기
    fp1 = fopen("in11.txt", "r");
    fp2 = fopen("in12.txt", "r");
    if (fp1 == NULL || fp2 == NULL)
    {
        fprintf(stderr, "오류: 'in11.txt' 또는 'in12.txt' 파일을 열 수 없습니다.\n");
        return 1;
    }

    // 2. 파일에서 다항식 읽어 리스트 생성
    polyA = read_poly(fp1);
    polyB = read_poly(fp2);

    // 3. 파일 닫기
    fclose(fp1);
    fclose(fp2);

    // 4. 다항식 뺄셈 수행
    polyC = poly_sub(polyA, polyB);

    // 5. 결과 다항식 출력
    print_poly(polyC);

    // 6. 할당된 메모리 해제
    free_poly(polyA);
    free_poly(polyB);
    free_poly(polyC);

    return 0;
}