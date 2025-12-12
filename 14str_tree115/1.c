/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void countNodes(char tree[], int size, int *n0, int *n1, int *n2)
{
    *n0 = 0;
    *n1 = 0;
    *n2 = 0;

    for (int i = 0; i < size; i++)
    {
        if (tree[i] == '\0')
        {
            continue;
        }

        int leftChildIndex = 2 * i + 1;
        int rightChildIndex = 2 * i + 2;
        int left_ = (leftChildIndex < size) && (tree[leftChildIndex] != '\0');
        int right_ = (rightChildIndex < size) && (tree[rightChildIndex] != '\0');
        if (left_ && right_)
        {
            (*n2)++;
        }
        else if (left_ || right_)
        {
            (*n1)++;
        }
        else
        {
            (*n0)++;
        }
    }
}

int main()
{
    int n0, n1, n2;

    char tree1[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I'};
    int size1 = sizeof(tree1) / sizeof(tree1[0]);

    countNodes(tree1, size1, &n0, &n1, &n2);

    printf("N1 = %d\n", n1);
    printf("N2 = %d\n", n2);
    printf("N0 = %d\n", n0);
    printf("\n");

    char tree2[] = {'A', 'B', '\0', 'C', '\0', '\0', '\0', 'D', '\0', '\0', '\0', '\0', '\0', '\0', '\0', 'E'};
    int size2 = sizeof(tree2) / sizeof(tree2[0]);

    countNodes(tree2, size2, &n0, &n1, &n2);

    printf("N1 = %d\n", n1);
    printf("N2 = %d\n", n2);
    printf("N0 = %d\n", n0);

    return 0;
}
*/

/*
typedef char DATA;
typedef int NODE;
DATA tree[MAX_TREE_NODE] = {0};

NODE makeRoot(DATA data) {
    tree[1] = data;
    return 1;
}

NODE makeLeftChild(NODE cur, DATA data) {
    tree[cur*2] = data;
    return cur*2;
}

NODE makeRightChild(NODE cur, DATA data) {
    tree[cur*2 +1] = data;
    return cur*2 +1;
}

DATA getCurData(NODE cur) {
    return tree[cur];
}

DATA getLeftData(NODE cur) {
    return tree[cur*2];
}

DATA getRightData(NODE cur) {
    return tree[cur*2+1];
}

int isTreeEmpty(NODE root) {
    if(tree[root] == 0) {
        return 1;
    }
    else
        return 0;
}
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_TREE1_SIZE 16
#define MAX_TREE2_SIZE 33

void countNodes(char tree[], int max_tree_size)
{
    int n0 = 0;
    int n1 = 0;
    int n2 = 0;

    for (int i = 1; i < max_tree_size; i++)
    {
        if (tree[i] == '\0')
        {
            continue;
        }
        int has_left = 0;
        int has_right = 0;

        int leftChildIndex = 2 * i;
        int rightChildIndex = 2 * i + 1;
        if (leftChildIndex < max_tree_size && tree[leftChildIndex] != '\0')
        {
            has_left = 1;
        }
        if (rightChildIndex < max_tree_size && tree[rightChildIndex] != '\0')
        {
            has_right = 1;
        }

        int child_count = has_left + has_right;
        if (child_count == 0)
        {
            n0++;
        }
        else if (child_count == 1)
        {
            n1++;
        }
        else
            n2++;
    }
    printf("N1 = %d\n", n1);
    printf("N2 = %d\n", n2);
    printf("N0 = %d\n", n0);
}

int main()
{
    char tree1[MAX_TREE1_SIZE] = {'\0'};
    tree1[1] = 'A';
    tree1[2] = 'B';
    tree1[3] = 'C';
    tree1[4] = 'D';
    tree1[5] = 'E';
    tree1[6] = 'F';
    tree1[7] = 'G';
    tree1[8] = 'H';
    tree1[9] = 'I';
    countNodes(tree1, MAX_TREE1_SIZE);

    char tree2[MAX_TREE2_SIZE] = {'\0'};
    tree2[1] = 'A';
    tree2[2] = 'B';
    tree2[4] = 'C';
    tree2[8] = 'D';
    tree2[16] = 'E';
    countNodes(tree2, MAX_TREE2_SIZE);

    return 0;
}