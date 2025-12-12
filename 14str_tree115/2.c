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

typedef struct node *treePointer;
typedef struct node
{
    int data;
    treePointer leftChild, rightChild;
} node;

treePointer newNode(int data);
void inorder(treePointer ptr);
treePointer copy(treePointer original);
int equal(treePointer first, treePointer second);

int main()
{
    treePointer root = newNode(4);
    root->leftChild = newNode(3);
    root->rightChild = newNode(6);
    root->leftChild->leftChild = newNode(2);
    root->leftChild->rightChild = newNode(5);
    root->rightChild->rightChild = newNode(8);

    printf("original inorder : ");
    inorder(root);
    printf("\n");

    treePointer copied_root = copy(root);
    printf("copy finished!\n");

    if (equal(root, copied_root))
    {
        printf("equal test success!\n");
    }
    else
    {
        printf("equal test failed!\n");
    }

    printf("copied inorder : ");
    inorder(copied_root);
    printf("\n");

    return 0;
}

treePointer newNode(int data)
{
    treePointer temp;
    MALLOC(temp, sizeof(*temp));
    temp->data = data;
    temp->leftChild = NULL;
    temp->rightChild = NULL;
    return temp;
}

void inorder(treePointer ptr)
{
    if (ptr)
    {
        inorder(ptr->leftChild);
        printf("%d ", ptr->data);
        inorder(ptr->rightChild);
    }
}

treePointer copy(treePointer original)
{
    treePointer temp;
    if (original)
    {
        MALLOC(temp, sizeof(*temp));
        temp->leftChild = copy(original->leftChild);
        temp->rightChild = copy(original->rightChild);
        temp->data = original->data;
        return temp;
    }
    return NULL;
}

int equal(treePointer first, treePointer second)
{
    return ((!first && !second) ||
            (first && second &&
             (first->data == second->data) &&
             equal(first->leftChild, second->leftChild) &&
             equal(first->rightChild, second->rightChild)));
}
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MALLOC(p, s)                            \
    if (!((p) = malloc(s)))                     \
    {                                           \
        fprintf(stderr, "Insufficient memory"); \
        exit(EXIT_FAILURE);                     \
    }

typedef struct node *treePointer;
typedef struct node
{
    int data;
    treePointer leftChild, rightChild;
};

treePointer newnode(int data)
{
    treePointer temp;
    MALLOC(temp, sizeof(*temp));
    temp->data = data;
    temp->leftChild = NULL;
    temp->rightChild = NULL;
    return temp;
}

void inorder(treePointer ptr)
{
    if (ptr)
    {
        inorder(ptr->leftChild);
        printf("%d ", ptr->data);
        inorder(ptr->rightChild);
    }
}

treePointer copy(treePointer original)
{
    treePointer temp;
    if (original)
    { // 원본노드가 존재하는경우
        MALLOC(temp, sizeof(*temp));
        temp->data = original->data;
        temp->leftChild = copy(original->leftChild);
        temp->rightChild = copy(original->rightChild);
        return temp;
    }
    return NULL;
}

int equal(treePointer first, treePointer second)
{ // 두개의 트리 구조가 같은지 확인하는 함수
    return ((!first && !second) ||
            (first && second &&
             first->data && second->data &&
             equal(first->leftChild, second->leftChild) &&
             equal(first->rightChild, second->rightChild)));
}
// 1. 둘다 NULL인 경우
// 2. 둘다 NULL이 아닐때
// 1) 데이터가 같고 2) 왼쪽 서브트리, 오른쪽 서브트리가 같을때

int main()
{
    treePointer root = newnode(4);
    root->leftChild = newnode(3);
    root->rightChild = newnode(6);
    root->leftChild->leftChild = newnode(2);
    root->leftChild->rightChild = newnode(5);
    root->rightChild->rightChild = newnode(8);

    printf("original inorder : ");
    inorder(root);
    printf("\n");

    treePointer copied_root = copy(root);
    printf("copy finished!\n");

    if (equal(root, copied_root))
    {
        printf("equal test succes!\n");
    }
    else
    {
        printf("equal test failed!\n");
    }
    printf("copied inorder : ");
    inorder(copied_root);
    printf("\n");

    return 0;
}