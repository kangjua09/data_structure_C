// 2023015950 - Ȳ����

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int iType;
typedef struct
{
    int key;
    iType item;
} element;

typedef struct node *TreePointer;
typedef struct node
{
    element data;
    TreePointer leftChild, rightChild;
} node;
TreePointer a = NULL;
void insert(TreePointer *node, int k, iType theItem);
TreePointer modifiedSearch(TreePointer node, int k);
element *search(TreePointer root, int k);
TreePointer deleteNode(TreePointer root, int key);
void inorder(TreePointer ptr);

int main()
{
    FILE *f = fopen("in1.txt", "r");
    int k = 0, n = 0, m = 0;
    fscanf(f, "%d", &n);
    for (int i = 1; i <= n; i++)
    {
        fscanf(f, "%d", &k);
        insert(&a, k, (iType)k);
    }
    fscanf(f, "%d", &m);
    for (int i = 1; i <= m; i++)
    {
        fscanf(f, "%d", &k);
        element *result = search(a, k);
        if (result != NULL)
        {
            printf("S ");
            a = deleteNode(a, k);
        }
        else
        {
            printf("E ");
        }
    }
    inorder(a);
    fclose(f);
    return 0;
}

void insert(TreePointer *node, int k, iType theItem)
{
    TreePointer ptr, temp = modifiedSearch(*node, k);
    if (temp || !(*node))
    {
        ptr = (TreePointer)malloc(sizeof(*ptr));
        ptr->data.key = k;
        ptr->data.item = theItem;
        ptr->leftChild = ptr->rightChild = NULL;
        if (*node)
            if (k < temp->data.key)
                temp->leftChild = ptr;
            else
                temp->rightChild = ptr;
        else
            *node = ptr;
    }
}

TreePointer modifiedSearch(TreePointer node, int k)
{
    TreePointer temp = NULL;
    if (!node)
        return NULL;
    while (node)
    {
        temp = node;
        if (k == node->data.key)
            return NULL;
        if (k < node->data.key)
            node = node->leftChild;
        else
            node = node->rightChild;
    }
    return temp;
}

element *search(TreePointer root, int k)
{
    if (!root)
        return NULL;
    if (k == root->data.key)
        return &(root->data);
    if (k < root->data.key)
        return search(root->leftChild, k);
    return search(root->rightChild, k);
}

TreePointer deleteNode(TreePointer root, int key)
{
    if (root == NULL)
        return root;

    if (key < root->data.key)
    {
        root->leftChild = deleteNode(root->leftChild, key);
    }
    else if (key > root->data.key)
    {
        root->rightChild = deleteNode(root->rightChild, key);
    }
    else
    {
        if (root->leftChild == NULL)
        {
            TreePointer temp = root->rightChild;
            free(root);
            return temp;
        }
        else if (root->rightChild == NULL)
        {
            TreePointer temp = root->leftChild;
            free(root);
            return temp;
        }

        TreePointer temp = root->rightChild;
        while (temp && temp->leftChild != NULL)
        {
            temp = temp->leftChild;
        }
        root->data = temp->data;
        root->rightChild = deleteNode(root->rightChild, temp->data.key);
    }
    return root;
}

void inorder(TreePointer ptr)
{
    if (ptr)
    {
        inorder(ptr->leftChild);
        printf("%d ", ptr->data.key);
        inorder(ptr->rightChild);
    }
}