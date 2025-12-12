#define _CRT_SECURE_NO_WARNINGS
#define MAX_STACK_SIZE 1000
#define EXIT_ROW (m)
#define EXIT_COL (p)
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    short vert, horiz;
} offsets; // 8방향 이동 오프셋
offsets move[8] = {
    {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}}; // 8방향

typedef struct
{
    short row, col, dir;
} element;

element stack[MAX_STACK_SIZE];
int top = -1;
int **maze; // 미로 배열
int **mark; // 방문 체크
int m, p;   // 입력 크기

void push(element item)
{
    stack[++top] = item;
}

element pop(void)
{
    return stack[top--];
}

void path(void)
{
    int row, col, nextRow, nextCol, dir, found = 0;
    element position;

    mark[1][1] = 1; // 시작점
    top = 0;
    stack[0].row = 1;
    stack[0].col = 1;
    stack[0].dir = 1;

    while (top > -1 && !found)
    {
        position = pop();
        row = position.row;
        col = position.col;
        dir = position.dir;

        while (dir < 8 && !found)
        {
            nextRow = row + move[dir].vert;
            nextCol = col + move[dir].horiz;

            if (nextRow == EXIT_ROW && nextCol == EXIT_COL && maze[nextRow][nextCol] == 0)
            {
                found = 1;
            }
            else if (maze[nextRow][nextCol] == 0 && !mark[nextRow][nextCol])
            {
                mark[nextRow][nextCol] = 1;
                position.row = row;
                position.col = col;
                position.dir = ++dir;
                push(position);

                row = nextRow;
                col = nextCol;
                dir = 0;
            }
            else
                ++dir;
        }
    }

    if (found)
    {
        printf("The path is:\n");
        printf("row col\n");
        for (int i = 0; i <= top; i++)
            printf("%d %d\n", stack[i].row, stack[i].col);
        printf("%d %d\n", row, col);
        printf("%d %d\n", EXIT_ROW, EXIT_COL);
    }
    else
    {
        printf("The maze does not have a path\n");
    }
}

int main(void)
{
    FILE *fp = fopen("in.txt", "r");
    if (!fp)
    {
        printf("입력 파일 열기 실패\n");
        return 1;
    }

    fscanf(fp, "%d %d", &m, &p);
    int R = m + 2, C = p + 2;

    // 동적 배열 할당
    maze = (int **)malloc(sizeof(int *) * R);
    mark = (int **)malloc(sizeof(int *) * R);
    for (int i = 0; i < R; i++)
    {
        maze[i] = (int *)malloc(sizeof(int) * C);
        mark[i] = (int *)malloc(sizeof(int) * C);
    }

    // 테두리를 1로 채움, mark=0 초기화
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            maze[i][j] = 1;
            mark[i][j] = 0;
        }
    }

    // 내부 미로 데이터 입력받음
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= p; j++)
            fscanf(fp, "%d", &maze[i][j]);
    fclose(fp);

    path(); // 탐색 실행

    return 0;
}