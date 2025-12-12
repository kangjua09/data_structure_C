#define _CRT_SECURE_NO_WARNINGS
#define MAX_STACK_SIZE 1000
#define EXIT_ROW (m)
#define EXIT_COL (p)
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    short vert, horiz; // 8방향 이동 오프셋
} offsets;
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

int startRow, startCol, endRow, endCol;

void path(void)
{
    int row, col, nextRow, nextCol, dir, found = 0;
    element position;

    mark[startRow][startCol] = 1; // 시작점
    top = 0;
    stack[0].row = startRow;
    stack[0].col = startCol;
    stack[0].dir = 0;

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

            if (nextRow == endRow && nextCol == endCol && maze[nextRow][nextCol] == 0)
            {
                found = 1;
                // 경로 저장
                maze[nextRow][nextCol] = -1;
                maze[row][col] = -1;
                for (int i = 0; i <= top; i++)
                    maze[stack[i].row][stack[i].col] = -1;
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
			maze[startRow][startCol] = -1;
			maze[endRow][endCol] = -1;
			for (int i = 0; i <= top; i++)
    		maze[stack[i].row][stack[i].col] = -1;


        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= p; j++)
            {
                if (maze[i][j] == -1)
                    printf("x ");
                else
                    printf("%d ", maze[i][j]);
            }
            printf("\n");
        }
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

    maze = (int **)malloc(sizeof(int *) * R);
    mark = (int **)malloc(sizeof(int *) * R);
    for (int i = 0; i < R; i++)
    {
        maze[i] = (int *)malloc(sizeof(int) * C);
        mark[i] = (int *)malloc(sizeof(int) * C);
    }

    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
        {
            maze[i][j] = 1;
            mark[i][j] = 0;
        }

    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= p; j++)
            fscanf(fp, "%d", &maze[i][j]);
    fclose(fp);

    scanf("%d %d %d %d", &startRow, &startCol, &endRow, &endCol);

    path();

    return 0;
}