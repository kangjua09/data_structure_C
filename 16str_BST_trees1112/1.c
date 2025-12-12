/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode *treePointer;
typedef struct treeNode
{
    int data;
    treePointer leftChild;
    treePointer rightChild;
} treeNode;

void insert(treePointer *node, int data)
{
    if (*node == NULL)
    {
        treePointer newNode = (treePointer)malloc(sizeof(treeNode));
        if (newNode == NULL)
        {
            fprintf(stderr, "Memory allocation failed\n");
            exit(EXIT_FAILURE);
        }
        newNode->data = data;
        newNode->leftChild = NULL;
        newNode->rightChild = NULL;
        *node = newNode;
        return;
    }

    if (data < (*node)->data)
    {
        insert(&((*node)->leftChild), data);
    }
    else if (data > (*node)->data)
    {
        insert(&((*node)->rightChild), data);
    }
}

void inorder(treePointer root)
{
    if (root)
    {
        inorder(root->leftChild);
        printf("%d ", root->data);
        inorder(root->rightChild);
    }
}

treePointer findMax(treePointer root)
{
    if (root == NULL)
    {
        return NULL;
    }
    while (root->rightChild != NULL)
    {
        root = root->rightChild;
    }
    return root;
}

int main()
{
    FILE *file = fopen("in.txt", "r");
    if (file == NULL)
    {
        fprintf(stderr, "Error opening file\n");
        return 1;
    }

    int n, data;
    while (fscanf(file, "%d", &n) == 1)
    {
        treePointer root = NULL;
        for (int i = 0; i < n; i++)
        {
            fscanf(file, "%d", &data);
            insert(&root, data);
        }

        inorder(root);
        printf("\n");

        treePointer maxNode = findMax(root);
        if (maxNode != NULL)
        {
            printf("%d\n", maxNode->data);
        }
    }

    fclose(file);
    return 0;
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

typedef struct treeNode *treePointer;
typedef struct treeNode
{
    int data;
    treePointer leftChild;
    treePointer rightChild;
} treeNode;

void insert(treePointer *node, int k)
{ // 들어갈 parent자리를 찾고, 자식으로 새 노드를 붙임.
    treePointer ptr, temp = NULL, parent = NULL;
    ptr = *node; // 루트 설정
    while (ptr != NULL)
    {
        if (k == ptr->data)
        {
            return;
        }
        parent = ptr;
        if (k < ptr->data)
            ptr = ptr->leftChild;
        else
            ptr = ptr->rightChild;
    }
    treePointer newnode;
    MALLOC(newnode, sizeof(treeNode));
    newnode->data = k;
    newnode->leftChild = newnode->rightChild = NULL;
    if (*node == NULL)
    {
        *node = newnode;
    }
    else if (k < parent->data)
        parent->leftChild = newnode;
    else
        parent->rightChild = newnode;
}

treePointer findMax(treePointer root)
{
    if (root == NULL)
    {
        return NULL;
    }
    treePointer ptr = root;
    while (ptr->rightChild != NULL)
    {
        ptr = ptr->rightChild;
    }
    return ptr;
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

int main()
{
    FILE *file = fopen("in.txt", "r");
    if (file == NULL)
    {
        fprintf(stderr, "Error opening file\n");
        return 1;
    }
    treePointer root = NULL;
    int num_size, num_input;
    fscanf(file, "%d", &num_size);
    for (int i = 0; i < num_size; i++)
    {
        fscanf(file, "%d", &num_input);
        insert(&root, num_input);
    }
    inorder(root);
    printf("\n");
    treePointer maxnode = findMax(root);
    if (maxnode != NULL)
    {
        printf("%d\n", maxnode->data);
    }
    fclose(file);
    return 0;
}