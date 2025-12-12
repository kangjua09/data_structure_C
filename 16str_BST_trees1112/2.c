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

treePointer search(treePointer root, int k)
{
    if (!root)
        return NULL;
    if (k == root->data)
        return root;
    if (k < root->data)
        return search(root->leftChild, k);
    return search(root->rightChild, k);
}

treePointer findMaxNode(treePointer root)
{
    while (root != NULL && root->rightChild != NULL)
    {
        root = root->rightChild;
    }
    return root;
}

treePointer deleteNode(treePointer root, int k)
{
    if (root == NULL)
        return root;

    if (k < root->data)
    {
        root->leftChild = deleteNode(root->leftChild, k);
    }
    else if (k > root->data)
    {
        root->rightChild = deleteNode(root->rightChild, k);
    }
    else
    {
        if (root->leftChild == NULL)
        {
            treePointer temp = root->rightChild;
            free(root);
            return temp;
        }
        else if (root->rightChild == NULL)
        {
            treePointer temp = root->leftChild;
            free(root);
            return temp;
        }

        treePointer temp = findMaxNode(root->leftChild);
        root->data = temp->data;
        root->leftChild = deleteNode(root->leftChild, temp->data);
    }
    return root;
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

int main()
{
    FILE *file = fopen("in.txt", "r");
    if (file == NULL)
    {
        fprintf(stderr, "Error opening file\n");
        return 1;
    }

    int n, m, data;
    treePointer root = NULL;

    fscanf(file, "%d", &n);
    for (int i = 0; i < n; i++)
    {
        fscanf(file, "%d", &data);
        insert(&root, data);
    }

    fscanf(file, "%d", &m);
    for (int i = 0; i < m; i++)
    {
        fscanf(file, "%d", &data);
        if (search(root, data) != NULL)
        {
            printf("S ");
            root = deleteNode(root, data);
        }
        else
        {
            printf("E ");
        }
    }

    inorder(root);
    printf("\n");

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
typedef int iType;
typedef struct
{
    int key;
    iType item;
} element;

typedef struct treeNode *treePointer;
typedef struct treeNode
{
    element data;
    treePointer leftChild;
    treePointer rightChild;
} treeNode;

treePointer modifiedSearch(treePointer node, int k)
{
    treePointer temp = NULL;
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

element *search(treePointer root, int k)
{
    if (!root)
        return NULL;
    if (k == root->data.key)
        return &(root->data);
    if (k < root->data.key)
        return search(root->leftChild, k);
    return search(root->rightChild, k);
}

void insert(treePointer *node, int k, iType theItem)
{
    treePointer ptr, temp = modifiedSearch(*node, k);
    if (temp || !(*node))
    {
        MALLOC(ptr, sizeof(*ptr));
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

void inorder(treePointer ptr)
{
    if (ptr)
    {
        inorder(ptr->leftChild);
        printf("%d ", ptr->data.key);
        inorder(ptr->rightChild);
    }
}

treePointer deleteNode(treePointer root, int key)
{
    if (root == NULL)
    {
        return root;
    }
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
            treePointer temp = root->rightChild;
            free(root);
            return temp;
        }
        else if (root->rightChild == NULL)
        {
            treePointer temp = root->leftChild;
            free(root);
            return temp;
        }
        else
        {
            treePointer temp = root->rightChild;
            while (temp->leftChild != NULL)
            {
                temp = temp->leftChild;
            }
            root->data = temp->data;
            root->rightChild = deleteNode(root->rightChild, temp->data.key);
        }
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
    treePointer root = NULL;
    int k = 0, n = 0, m = 0;
    fscanf(file, "%d", &n);
    for (int i = 1; i <= n; i++)
    {
        fscanf(file, "%d", &k);
        insert(&root, k, (iType)k);
    }
    fscanf(file, "%d", &m);
    for (int i = 1; i <= m; i++)
    {
        fscanf(file, "%d", &k);
        element *result = search(root, k);
        if (result != NULL)
        {
            printf("S ");
            root = deleteNode(root, k);
        }
        else
        {
            printf("E ");
        }
    }
    inorder(root);
    fclose(file);
    return 0;
}