/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MALLOC(p, s)                            \
    if (!((p) = malloc(s)))                     \
    {                                           \
        fprintf(stderr, "Insufficient memory"); \
        exit(EXIT_FAILURE);                     \
    }
#define REALLOC(p, s)                           \
    if (!((p) = realloc(p, s)))                 \
    {                                           \
        fprintf(stderr, "Insufficient memory"); \
        exit(EXIT_FAILURE);                     \
    }

typedef struct
{
    int key;
} element;

element *queue;
int capacity = 1; // 초기값 설정
int front = 0;
int rear = 0;

void queueFull()
{
    element *newQueue;
    MALLOC(newQueue, 2 * capacity * sizeof(*queue));
    int start = (front + 1) % capacity;
    if (start < 2)
        copy(queue + start, queue + start + capacity - 1, newQueue);
    else
        copy(queue + start, queue + capacity, newQueue);
    copy(queue, queue + rear + 1, newQueue + capacity - start);

    front = 2 * capacity - 1;
    rear = capacity - 2;
    capacity *= 2;
    free(queue);
    queue = newQueue;
}

void addQ(element item)
{
    rear = (rear + 1) % capacity;
    if (front == rear)
    {
        queueFull();
    }
    queue[rear] = item;
}

element deleteQ()
{
    front = (front + 1) % capacity;
    if(front==rear) {
        fprintf(stderr, "fail\n");
        exit(EXIT_FAILURE);
    }
    // 이거는 메인에서 확인한다고 생각
    return queue[front];
}

int main()
{
    // 큐의 초기 메모리 할당
    MALLOC(queue, capacity * sizeof(element));

    char command;
    element item;
    int x;

    while (scanf(" %c", &command) == 1 && command != 'F')
    {
        if (command == 'I')
        {
            scanf(" %d", &x);
            item.key = x;
            addQ(item);
        }
        else if (command == 'D')
        {
            if (front == rear)
            {
                // 큐가 비어있으면 -1 출력 (요구사항 8)
                printf("-1 ");
            }
            else
            {
                item = deleteQ();
                printf("%d ", item.key);
            }
        }
    }

    while (front != rear)
    {
        item = deleteQ();
        printf("%d ", item.key);
    }
    printf("\n"); // 출력 완료 후 줄바꿈

    free(queue); // 할당된 메모리 해제
    return 0;
}
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MALLOC(p, s)                             \
    if (!((p) = malloc(s)))                      \
    {                                            \
        fprintf(stderr, "Inefficient memory\n"); \
        exit(EXIT_FAILURE);                      \
    }
#define REALLOC(p, s)                            \
    if (!((p) = realloc(p, s)))                  \
    {                                            \
        fprintf(stderr, "Inefficient memory\n"); \
        exit(EXIT_FAILURE);                      \
    }

typedef struct
{
    int key;
} element;

element *queue;
int front = 0;
int rear = 0;
int capacity = 1;

void queueFull()
{
    element *newQueue;
    MALLOC(newQueue, 2 * capacity * sizeof(*queue));
    int start = (front + 1) % capacity;
    if (start < 2)
        copy(queue + start, queue + start + capacity - 1, newQueue);
    else
        copy(queue + start, queue + capacity, newQueue);
    copy(queue, queue + rear + 1, newQueue + capacity - start);

    front = 2 * capacity - 1;
    rear = capacity - 2;
    capacity *= 2;
    free(queue);
    queue = newQueue;
}

void addQ(element item)
{
    rear = (rear + 1) % capacity;
    if (front == rear)
    {
        queueFull();
    }
    queue[rear] = item;
}

element deleteQ()
{
    front = (front + 1) % capacity;
    if (front == rear)
    {
        fprintf(stderr, "fail\n");
        exit(EXIT_FAILURE);
    }
    return queue[front];
}

int main()
{
    int n;
    char a;
    element item;
    MALLOC(queue, capacity * sizeof(element));

    while (1)
    {
        scanf(" %c", &a);
        if (a == 'F')
        {
            break;
        }
        else if (a == 'I')
        {
            scanf("%d", &n);
            item.key = n;
            addQ(item);
        }
        else if (a == 'D')
        {
            if (front == rear)
            {
                printf("-1 ");
            }
            element deletequeue = deleteQ();
            printf("%d ", deletequeue.key);
        }
    }
    while (front != rear)
    {
        item = deleteQ();
        printf("%d ", item.key);
    }
    printf("\n");
    // for문으로 배열출력하지 않는이유!!
    // -> stack은 배열 형식으로 순차적으로 출력해되지만 queue는 회전초밥 같은 형태이기 때문에 while반복문을 써야함

    free(queue);
    return 0;
}

/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *queue;   // 요소들이 들어갈 동적 배열
    int capacity; // 배열 용량
    int front;    // 항상 비어있는 칸
    int rear;     // 최근에 넣은 원소의 칸
} Queue;

// 배열 복사 함수
void copy(int *srcStart, int *srcEnd, int *dest)
{
    while (srcStart < srcEnd)
    {
        *dest++ = *srcStart++; // 구간 위치 복사
    }
}

// 큐 초기화
void init(Queue *q)
{
    q->capacity = 1; // 초기 크기 1
    q->queue = (int *)malloc(sizeof(int) * q->capacity);
    q->front = q->rear = 0; // 빈거랑 = 최근거(비엇음)
}

int isEmpty(Queue *q)
{
    return (q->front == q->rear); // 비엇음
}

// 큐 full 시 확장 (교재 Program 3.10 기반, 그대로 쓰니까 malloc이 오류가 떠서 리스트 형식으로 조금씩 바꿨습니다.)
void queueFull(Queue *q)
{
    int *newQueue = (int *)malloc(sizeof(int) * 2 * q->capacity);
    int start = (q->front + 1) % q->capacity;

    if (start < 2)
    {
        copy(q->queue + start, q->queue + start + q->capacity - 1, newQueue);
    }
    else
    {
        copy(q->queue + start, q->queue + q->capacity, newQueue);
        copy(q->queue, q->queue + q->rear + 1, newQueue + q->capacity - start);
    }

    q->front = 2 * q->capacity - 1;
    q->rear = q->capacity - 2;
    q->capacity *= 2;

    free(q->queue);
    q->queue = newQueue;
}

// 삽입
void addQ(Queue *q, int item)
{
    q->rear = (q->rear + 1) % q->capacity;
    if (q->front == q->rear)
    {
        queueFull(q);
        q->rear = (q->rear + 1) % q->capacity;
    }
    q->queue[q->rear] = item;
}

// 삭제
int deleteQ(Queue *q)
{
    if (isEmpty(q))
    {
        printf("-1 ");
        return -1;
    }
    q->front = (q->front + 1) % q->capacity;
    printf("%d ", q->queue[q->front]); // pop한 값 출력
    return q->queue[q->front];
}

// 최종 상태 출력
void printQueue(Queue *q)
{
    int i = (q->front + 1) % q->capacity;
    while (i != (q->rear + 1) % q->capacity)
    {
        printf("%d ", q->queue[i]);
        i = (i + 1) % q->capacity;
    }
}

int main()
{
    Queue q;
    init(&q);

    char cmd;
    int num;

    while (1)
    {
        scanf(" %c", &cmd);
        if (cmd == 'F')
            break;
        else if (cmd == 'I')
        {
            scanf("%d", &num);
            addQ(&q, num);
        }
        else if (cmd == 'D')
        {
            deleteQ(&q);
        }
    }

    printQueue(&q);

    free(q.queue);
    return 0;
}

*/