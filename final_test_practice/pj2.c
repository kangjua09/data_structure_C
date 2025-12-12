//tree
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef struct Node* TreePointer;
typedef struct {
    int data;
    TreePointer left;
    TreePointer right;
}Node;

int cnt1 = 0;
int cnt2 = 0;
int cnt0 = 0;

int last = 1;

void makeNode(char tree[], int cnt);
void countNum(char tree[], int cnt);
int getHeight(char tree[]);

int main() {
    char tree[100];
    tree[0] = NULL;
    int cnt = 16;
    for (int i = 1; i < cnt * 2 + 2; i++) {
        tree[i] = NULL;
    }
    makeNode(tree, cnt);
    countNum(tree, cnt);
    printf("height = %d", getHeight(tree));
    //printf("N1 = %d\nN2 = %d\nN3 = %d", cnt1, cnt2, cnt0);
}

void makeNode(char tree[], int cnt) {
    for (int i = 1; i < cnt + 1; i *= 2) {
        char a[2];
        scanf("%s", &a);
        tree[i] = *a;
        last = i;
    }
}

void countNum(char tree[], int cnt) {
    for (int i = 1; i < cnt + 1; i++) {
        if (tree[i] != NULL) {
            if (tree[2 * i] == NULL && tree[2 * i + 1] == NULL) {
                cnt0++;
            }
            else if (tree[2 * i] == NULL || tree[2 * i + 1] == NULL) {
                cnt1++;
            }
            else {
                cnt2++;
            }
        }
    }
}

int getHeight(char tree[]) {
    int check = 1;
    while (1) {
        if (last > pow(2, check - 1) - 1 && last <= pow(2, check) - 1) {
            return check;
        }
        check++;
    }
}

//order
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node* TreePointer;
typedef struct Node {
    TreePointer left;
    int data;
    TreePointer right;
}Node;

int front = 0, rear = -1;
TreePointer queue[100];
TreePointer stack[100];
int cnt = 0;
int top = -1;

void makeTree(TreePointer root);
void inorder(TreePointer root);
TreePointer copy(TreePointer root);
int equal(TreePointer first, TreePointer second);
TreePointer deleteq();
void addq(TreePointer data);
void levelOrder(TreePointer root);
void countLeaf(TreePointer root);
void recursivePreOrder(TreePointer root);
void push(TreePointer data);
TreePointer pop();
void iterativePreOrder(TreePointer root);

int main() {
    TreePointer root = (TreePointer)malloc(sizeof(Node));
    makeTree(root);

    inorder(root);

    TreePointer copied = copy(root);
    printf("\ncopy finished\n");

    if (equal(root, copied)) {
        printf("equal test success!\n");
    }
    else {
        printf("equal test failed!\n");
    }

    printf("copied inorder : ");
    inorder(copied);

    printf("\n");
    levelOrder(root);

    countLeaf(root);
    printf("\n%d\n", cnt);

    printf("recursive preorder : ");
    recursivePreOrder(root);
    printf("\n");

    printf("iterative preorder : ");
    iterativePreOrder(root);
    printf("\n");
}

void makeTree(TreePointer root) {
    TreePointer rt = root;
    rt->data = 4;
    TreePointer l = (TreePointer)malloc(sizeof(Node));
    TreePointer r = (TreePointer)malloc(sizeof(Node));
    TreePointer ll = (TreePointer)malloc(sizeof(Node));
    TreePointer lr = (TreePointer)malloc(sizeof(Node));
    TreePointer rr = (TreePointer)malloc(sizeof(Node));
    rt->left = l;
    rt->right = r;
    l->left = ll;
    l->right = lr;
    r->right = rr;
    l->data = 3;
    r->data = 6;
    ll->data = 2;
    lr->data = 5;
    rr->data = 8;
    ll->left = NULL;
    ll->right = NULL;
    lr->left = NULL;
    lr->right = NULL;
    r->left = NULL;
    rr->right = NULL;
    rr->left = NULL;
}

void inorder(TreePointer root) {
    TreePointer ptr = root;
    if (ptr) {
        inorder(ptr->left);
        printf("%d ", ptr->data);
        inorder(ptr->right);
    }
}

TreePointer copy(TreePointer root) {
    TreePointer original = root;
    TreePointer temp;
    if (original) {
        temp = (TreePointer)malloc(sizeof(Node));
        temp->left = copy(original->left);
        temp->right = copy(original->right);
        temp->data = original->data;
        return temp;
    }
    return NULL;
}

int equal(TreePointer first, TreePointer second) {
    return ((!first && !second) || (first && second &&
        (first->data == second->data) && equal(first->left, second->left) &&
        equal(first->right, second->right)));
}

void addq(TreePointer data) {
    queue[++rear] = data;
}

TreePointer deleteq() {
    return queue[front++];
}

void levelOrder(TreePointer root) {
    TreePointer ptr = root;
    if (!ptr) {
        return;
    }
    addq(ptr);
    for (;;) {
        ptr = deleteq();
        if (ptr) {
            printf("%d ", ptr->data);
            if (ptr->left) {
                addq(ptr->left);
            }
            if (ptr->right) {
                addq(ptr->right);
            }
        }
        else break;
    }

}

void countLeaf(TreePointer root) {
    TreePointer ptr = root;
    if (ptr) {
        countLeaf(ptr->left);
        countLeaf(ptr->right);
        if (!ptr->left && !ptr->right) {
            cnt++;
        }
    }
}

void recursivePreOrder(TreePointer root) {
    TreePointer ptr = root;
    if (ptr) {
        printf("%d ", ptr->data);
        recursivePreOrder(ptr->left);
        recursivePreOrder(ptr->right);
    }
}

void push(TreePointer data) {
    stack[++top] = data;
}

TreePointer pop() {
    return stack[top--];
}

void iterativePreOrder(TreePointer root) {
    TreePointer ptr = root;
    for (;;) {
        for (; ptr; ptr = ptr->left) {
            printf("%d ", ptr->data);
            push(ptr);
        }
        ptr = pop();
        if (!ptr) break;
        ptr = ptr->right;
    }
}

//heap
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    int key;
} Element;

int size = 1;

Element* heap;
void push(Element item, int n);
void levelOrder(int n);
Element deletion(int* n);

int main() {
    heap = (Element*)malloc(sizeof(Element) * size);
    FILE* fp = fopen("in.txt", "r");
    int n;
    fscanf(fp, "%d", &n);
    for (int i = 0; i < n; i++) {
        int temp;
        fscanf(fp, "%d", &temp);
        Element a;
        a.key = temp;
        push(a, i);
    }

    levelOrder(n);
    printf("\n");
    int m;
    fscanf(fp, "%d", &m);
    for (int i = 0; i < m; i++) {
        deletion(&n);
    }

    levelOrder(n);

}

void push(Element item, int n) {
    int i;
    if (n > 100) {
        size *= 2;
        Element* temp;
        temp = realloc(heap, sizeof(Element) * size);
        heap = temp;
    }
    i = ++(n);
    while ((i != 1) && (item.key > heap[i / 2].key)) {
        heap[i] = heap[i / 2];
        i /= 2;
    }
    heap[i] = item;
}

void levelOrder(int n) {
    for (int i = 1; i <= n; i++) {
        printf("%d ", heap[i]);
    }
}

Element deletion(int* n) {
    int parent, child;
    Element item, temp;
    if (*n > 100) {
        fprintf(stderr, "The heap is empty\n");
        exit(EXIT_FAILURE);
    }
    item = heap[1];
    temp = heap[(*n)--]; parent = 1;
    child = 2;
    while (child <= *n) {
        if ((child < *n) && (heap[child].key < heap[child + 1].key))
            child++;
        if (temp.key >= heap[child].key)
            break;
        heap[parent] = heap[child];
        parent = child; child *= 2;
    }
    heap[parent] = temp;
    return item;
}

//bst
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int iType;
typedef struct {
    int key;
    iType item;
}element;

typedef struct node* treePointer;
typedef struct node {
    element data;
    treePointer leftChild, rightChild;
}node;

treePointer a = NULL;

void insert(treePointer* node, int k, iType theItem);
treePointer modifiedSearch(treePointer node, int k);
element* search(treePointer root, int k);
treePointer deleteNode(treePointer root, int key);
void inorder(treePointer ptr);

int main() {
    FILE* f = fopen("in.txt", "r");
    int k = 0;
    int n = 0;
    int m = 0;
    fscanf(f, "%d", &n);
    for (int i = 1; i <= n; i++) {
        fscanf(f, "%d", &k);
        insert(&a, k, (iType)k);
    }
    fscanf(f, "%d", &m);
    for (int i = 1; i <= m; i++) {
        fscanf(f, "%d", &k);
        element* result = search(a, k);
        if (result != NULL) {
            printf("S ");
            a = deleteNode(a, k);
        }
        else {
            printf("E ");
        }
    }
    inorder(a);
    return 0;
}

void insert(treePointer* node, int k, iType theItem)
{/* if k is in the tree pointed at by node do nothing;
 otherwise add a new node with data = (k, theitem) */
    treePointer ptr, temp = modifiedSearch(*node, k);
    if (temp || !(*node)) {
        /* k is not in the tree */
        //MALLOC(ptr, sizeof(*ptr));
        ptr = (treePointer)malloc(sizeof(*ptr));
        ptr->data.key = k;
        ptr->data.item = theItem;
        ptr->leftChild = ptr->rightChild = NULL;
        if (*node) /* insert as child of temp */
            if (k < temp->data.key) temp->leftChild = ptr;
            else temp->rightChild = ptr;
        else *node = ptr;
    }
}

treePointer modifiedSearch(treePointer node, int k)
{
    treePointer temp = NULL;
    if (!node) return NULL;      // empty BST
    while (node) {
        temp = node;
        if (k == node->data.key) return NULL; // k is present
        if (k < node->data.key)
            node = node->leftChild;
        else
            node = node->rightChild;
    }
    return temp;
}

element* search(treePointer root, int k)
{/* return a pointer to the element whose key is k, if
there is no such element, return NULL. */
    if (!root) return NULL;
    if (k == root->data.key) return &(root->data);
    if (k < root->data.key)
        return search(root->leftChild, k);
    return search(root->rightChild, k);
}

treePointer deleteNode(treePointer root, int key) {
    if (root == NULL) return root;

    if (key < root->data.key) {
        root->leftChild = deleteNode(root->leftChild, key);
    }
    else if (key > root->data.key) {
        root->rightChild = deleteNode(root->rightChild, key);
    }
    else {
        if (root->leftChild == NULL) {
            treePointer temp = root->rightChild;
            free(root);
            return temp;
        }
        else if (root->rightChild == NULL) {
            treePointer temp = root->leftChild;
            free(root);
            return temp;
        }

        treePointer temp = root->rightChild;
        while (temp && temp->leftChild != NULL) {
            temp = temp->leftChild;
        }
        root->data = temp->data;
        root->rightChild = deleteNode(root->rightChild, temp->data.key);
    }
    return root;
}

void inorder(treePointer ptr) {
    if (ptr) {
        inorder(ptr->leftChild);
        printf("%d ", ptr->data.key);
        inorder(ptr->rightChild);
    }
}

//DFS
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 2

/*
0 1 1 0 1
1 0 1 0 1
1 1 0 0 0
0 0 0 0 1
1 1 0 1 0
*/

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct Graph {
    int numVertices;
    Node** adjLists;
} Graph;


Node* createNode(int v);
Graph* createGraph(int vertices);
void addEdge(Graph* graph, int src, int dest);
void printGraph(Graph* graph);
int DFS(Graph* graph, int v, int endVertex, int* visited, int* path, int pathIndex);

int main() {
    FILE* fp = fopen("in.txt", "r");

    int vertices;
    fscanf(fp, "%d", &vertices);

    Graph* graph = createGraph(vertices);

    for (int i = 0; i < vertices; i++) {
        for (int j = i + 1; j < vertices; j++) {
            int edge;
            fscanf(fp, "%d", &edge);
            if (edge == 1) {
                addEdge(graph, i, j);
            }
        }
    }
    fclose(fp);
    int startVertex, endVertex;
    scanf("%d %d", &startVertex, &endVertex);
    startVertex--;
    endVertex--;
    int* visited = malloc(vertices * sizeof(int));
    int* path = malloc(vertices * sizeof(int));
    for (int i = 0; i < vertices; i++) {
        visited[i] = 0;
    }
    if (!DFS(graph, startVertex, endVertex, visited, path, 0)) {
        printf("No path found.\n");
    }

}

Node* createNode(int v) {
    Node* newNode = malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

Graph* createGraph(int vertices) {
    Graph* graph = malloc(sizeof(Graph));
    graph->numVertices = vertices;

    graph->adjLists = malloc(vertices * sizeof(Node*));
    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
    }
    return graph;
}

void addEdge(Graph* graph, int src, int dest) {
    Node* temp = graph->adjLists[src];
    while (temp) {
        if (temp->vertex == dest) return;
        temp = temp->next;
    }

    Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    temp = graph->adjLists[dest];
    while (temp) {
        if (temp->vertex == src) return;
        temp = temp->next;
    }

    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

void printGraph(Graph* graph) {
    for (int v = 0; v < graph->numVertices; v++) {
        Node* temp = graph->adjLists[v];
        printf("Vertex %d: ", v + 1);
        while (temp) {
            printf("%d ", temp->vertex + 1);
            temp = temp->next;
        }
        printf("\n");
    }
}

int DFS(Graph* graph, int v, int endVertex, int* visited, int* path, int pathIndex) {
    visited[v] = 1;
    path[pathIndex] = v;
    pathIndex++;

    if (v == endVertex) {
        for (int i = 0; i < pathIndex; i++) {
            printf("%d ", path[i] + 1);
        }
        printf("\n");
        return TRUE;
    }

    Node* adjList = graph->adjLists[v];
    Node* temp = adjList;

    while (temp != NULL) {
        int connectedVertex = temp->vertex;

        if (!visited[connectedVertex]) {
            if (DFS(graph, connectedVertex, endVertex, visited, path, pathIndex)) {
                return TRUE;
            }
        }
        temp = temp->next;
    }

    pathIndex--;
    visited[v] = 0;
    return FALSE;
}
//simple real
void DFS(Graph* graph, int startVertex, int* visited) {
    visited[startVertex] = 1;
    printf("%d ", startVertex + 1);

    Node* adjList = graph->adjLists[startVertex];
    Node* temp = adjList;

    while (temp != NULL) {
        int connectedVertex = temp->vertex;

        if (!visited[connectedVertex]) {
            DFS(graph, connectedVertex, visited);
        }
        temp = temp->next;
    }
}

//insertion sort

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int key;
    char name[20];
    int grade;
} Element;

void insert(Element e, Element arr[], int i);
void insertionSort(Element arr[], int n);
int binarySearch(Element arr[], int item, int low, int high);

int main() {
    FILE* fp = fopen("in.txt", "r");

    int n;
    fscanf(fp, "%d", &n);

    Element* arr = (Element*)malloc(sizeof(Element) * (n + 1));

    for (int i = 1; i <= n; i++) {
        fscanf(fp, "%d %s %d", &arr[i].key, arr[i].name, &arr[i].grade);
    }

    insertionSort(arr, n);

    for (int i = 1; i <= n; i++) {
        printf("%d %s %d\n", arr[i].key, arr[i].name, arr[i].grade);
    }

    fclose(fp);
    free(arr);
}

void insert(Element e, Element arr[], int i) {
    arr[0] = e;
    while (e.key < arr[i].key) {
        arr[i + 1] = arr[i];
        i--;
    }
    arr[i + 1] = e;
}

void insertionSort(Element arr[], int n) {
    int i, j, loc;
    Element selected;

    for (i = 2; i <= n; i++) {
        selected = arr[i];
        loc = binarySearch(arr, selected.key, 1, i - 1);

        for (j = i - 1; j >= loc; j--) {
            arr[j + 1] = arr[j];
        }

        arr[loc] = selected;
    }
}

int binarySearch(Element arr[], int item, int low, int high) {
    if (high <= low) {
        return (item > arr[low].key) ? (low + 1) : low;
    }

    int mid = (low + high) / 2;

    if (item == arr[mid].key) {
        return mid + 1;
    }

    if (item > arr[mid].key) {
        return binarySearch(arr, item, mid + 1, high);
    }

    return binarySearch(arr, item, low, mid - 1);
}

//merge sort
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void merge(int arr[], int temp[], int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int k = left;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }
}

void mergeSortIterative(int arr[], int n) {
    int temp[100];

    for (int size = 1; size <= n - 1; size = 2 * size) {
        for (int left_start = 0; left_start < n - 1; left_start += 2 * size) {
            int mid = left_start + size - 1;
            int right_end = (left_start + 2 * size - 1 < n - 1) ? (left_start + 2 * size - 1) : (n - 1);
            if (mid < right_end) {
                merge(arr, temp, left_start, mid, right_end);
            }
        }
    }
}

int main() {
    FILE* fp = fopen("in.txt", "r");
    int arr[100];
    int cnt = 0;
    while (fscanf(fp, "%d", &arr[cnt]) == 1) {
        cnt++;
    }

    mergeSortIterative(arr, cnt);


    for (int i = 0; i < cnt; i++) {
        printf("%d ", arr[i]);
    }
}

//quick sort
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[20];
    int num;
    double grade;
} Record;

void swap(Record* a, Record* b);
int partition(Record arr[], int low, int high);
void quicksort(Record arr[], int low, int high);
void printRecords(Record arr[], int size);

int main() {
    FILE* fp = fopen("in.txt", "r");
    int n;
    fscanf(fp, "%d", &n);

    Record* record = (Record*)malloc(sizeof(Record) * n);

    for (int i = 0; i < n; i++) {
        fscanf(fp, "%s %d %lf", &record[i].name, &record[i].num, &record[i].grade);
    }

    quicksort(record, 0, n - 1);

    printRecords(record, n);

}

void swap(Record* a, Record* b) {
    Record temp = *a;
    *a = *b;
    *b = temp;
}

int partition(Record arr[], int low, int high) {
    char* pivot = arr[high].name; // pivot
    int i = low - 1; // Index of smaller element

    for (int j = low; j <= high - 1; j++) {
        if (strcmp(arr[j].name, pivot) <= 0) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quicksort(Record arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

void printRecords(Record arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("이름: %s, 학번: %d, 평균성적: %.2f\n", arr[i].name, arr[i].num, arr[i].grade);
    }
}

//heap sort
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//stable하지 않다.

#define SWAP(x,y,temp) temp = y; y = x; x = temp;

typedef struct {
    int intKey;
    char charKey;
} Element;

void adjust(Element a[], int root, int n);
void heapSort(Element a[], int n);

int main() {
    FILE* fp = fopen("in.txt", "r");

    Element a[100];
    int cnt = 0;
    while (fscanf(fp, "%d %c", &a[cnt].intKey, &a[cnt].charKey) != EOF) {
        cnt++;
    }

    heapSort(a, cnt);

    for (int i = 0; i < cnt; i++) {
        printf("%d %c\n", a[i].intKey, a[i].charKey);
    }
}

void adjust(Element a[], int root, int n) {
    int child, rootintKey;
    Element temp;
    temp = a[root];
    rootintKey = a[root].intKey;
    child = 2 * root + 1;
    while (child < n) {
        if (child < n - 1 && a[child].intKey > a[child + 1].intKey)
            child++;
        if (rootintKey <= a[child].intKey) {
            break;
        }
        else {
            a[(child - 1) / 2] = a[child];
            child = 2 * child + 1;
        }
    }
    a[(child - 1) / 2] = temp;
}

void heapSort(Element a[], int n) {
    int i;
    Element temp;

    for (i = n / 2 - 1; i >= 0; i--) {
        adjust(a, i, n);
    }
    for (i = n - 1; i > 0; i--) {
        SWAP(a[0], a[i], temp);
        adjust(a, 0, i);
    }
}

//radix sort
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef struct node {
    int key;
} Element;

Element a[100];
int link[100];

int radixSort(Element a[], int link[], int d, int n);
int digit(Element a, int dNum, int d);

int main() {
    int cnt = 1, first;
    FILE* f = fopen("in.txt", "r");

    while (fscanf(f, "%d", &a[cnt].key) != EOF) {
        cnt++;
    }
    cnt--;

    first = radixSort(a, link, 3, cnt);

    int temp = first;

    for (int i = 0; i < cnt; i++) {
        printf("%d ", a[temp]);
        temp = link[temp];
    }


}

int radixSort(Element a[], int link[], int d, int n) {
    int front[10], rear[10];
    int i, bin, current, first, last;

    first = 1;
    for (i = 1; i < n; i++) link[i] = i + 1;
    link[n] = 0;

    for (i = d - 1; i >= 0; i--) {
        for (bin = 0; bin < 10; bin++)
            front[bin] = 0;

        for (current = first; current; current = link[current]) {
            bin = digit(a[current], i, 10);
            if (front[bin] == 0)
                front[bin] = current;
            else
                link[rear[bin]] = current;
            rear[bin] = current;
        }

        for (bin = 0; !front[bin]; bin++);
        first = front[bin]; last = rear[bin];

        for (bin++; bin < 10; bin++)
            if (front[bin]) {
                link[last] = front[bin];
                last = rear[bin];
            }
        link[last] = 0;
    }
    return first;
}

int digit(Element a, int dNum, int d) {
    if (dNum == 2) {
        return a.key % 10;
    }
    else if (dNum == 1) {
        return (int)((a.key % 100) / 10);
    }
    else if (dNum == 0) {
        return (int)(a.key / 100);
    }
}

//radix sort - string
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char key[20];
} Element;

Element a[100];

void radixSort(Element a[], int n, int d, int r);
int digit(char temp[], int position);

int main() {
    FILE* f = fopen("in.txt", "r");
    int r = 26;
    int count = 0;
    while (fscanf(f, "%s", a[count].key) != EOF) {
        count++;
    }

    radixSort(a, count, 5, r);

    for (int j = 0; j < count; j++) {
        printf("%s ", a[j].key);
    }
}

void radixSort(Element a[], int n, int d, int r) {
    int i, j, k, bin;
    int* count = (int*)malloc(r * sizeof(int));
    Element* temp = (Element*)malloc(n * sizeof(Element));

    for (int pos = d - 1; pos >= 0; pos--) {
        for (i = 0; i < r; i++) count[i] = 0;

        for (i = 0; i < n; i++) {
            bin = digit(a[i].key, pos);
            count[bin]++;
        }

        for (i = 1; i < r; i++) count[i] += count[i - 1];

        for (i = n - 1; i >= 0; i--) {
            bin = digit(a[i].key, pos);
            temp[--count[bin]] = a[i];
        }

        for (i = 0; i < n; i++) {
            a[i] = temp[i];
        }
    }

}

int digit(char temp[], int position) {
    if (position < strlen(temp)) {
        return temp[position] - 'a';
    }
    else {
        return 0;
    }
}

//hashing - linear probing
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int key;
    char value[100];
}Element;

int stringToInt(char key[]);
void insert(Element* ht, int D, char* value);
Element* search(Element* ht, int b, int k);
int hashing(int k, int b);

int main() {
    int D;
    scanf("%d", &D);
    Element* ht = (Element*)calloc(D, sizeof(Element));
    FILE* fpIn = fopen("in.txt", "r");
    char in[100];
    while (fscanf(fpIn, "%s", in) != EOF)
        insert(ht, D, in);
    printf("\n");
    FILE* fpSearch = fopen("search.txt", "r");
    while (fscanf(fpSearch, "%s", in) != EOF)
    {
        Element* e = search(ht, D, stringToInt(in));
        printf("%s\n", e != NULL ? "S" : "E");
    }
    printf("\n");

    for (int i = 0; i < D; i++)
        if (ht[i].key != 0)
            printf("%d: %s (%u)\n", i, ht[i].value, ht[i].key);
        else
            printf("%d:\n", i);
}

int stringToInt(char key[]) {
    int number = 0;
    int cnt = 0;
    while (key[cnt]) {
        number += key[cnt];
        cnt++;
    }
    return number;
}

void insert(Element* ht, int D, char* value) {
    int k = stringToInt(value);
    int homeBucket = hashing(k, D);
    int currentBucket = homeBucket;

    while (ht[currentBucket].key != 0)
    {
        currentBucket = (currentBucket + 1) % D;
        if (currentBucket == homeBucket)
        {
            printf("Hash table overflow\n");
            return;
        }
    }
    ht[currentBucket].key = k;
    strcpy(ht[currentBucket].value, value);
}

Element* search(Element* ht, int D, int k) {
    int homeBucket = hashing(k, D);
    int currentBucket = homeBucket;

    while (ht[currentBucket].key != 0 && ht[currentBucket].key != k)
    {
        currentBucket = (currentBucket + 1) % D;
        if (currentBucket == homeBucket)
            return NULL;
    }
    return (ht[currentBucket].key == k) ? &ht[currentBucket] : NULL;
}

int hashing(int k, int D) {
    return k % D;
}


//hashing - chaining

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node* nodePointer;
typedef struct node {
    char name[20];
    int key;
    nodePointer next;
} node;

nodePointer* head;

void insert(int b, char* str);
int stringToInt(char* key);
int hashing(int name, int b);
int search(int b, char* str);

int main() {
    int D;
    scanf("%d", &D);
    head = (nodePointer*)malloc(sizeof(nodePointer) * D);
    for (int i = 0; i < D; i++)
        head[i] = NULL;

    FILE* fp = fopen("in.txt", "r");

    char str[4];
    while (fscanf(fp, "%s", str) != EOF)
        insert(D, str);

    printf("\n");
    FILE* fpSearch = fopen("search.txt", "r");
    while (fscanf(fpSearch, "%s", str) != EOF) {
        if (search(D, str)) {
            printf("%c\n", 'S');
        }
        else {
            printf("%c\n", 'E');
        }
    }
    printf("\n");

    for (int i = 0; i < D; i++) {
        nodePointer temp = head[i];
        printf("%d : ", i);
        while (temp) {
            printf("%s (%d) ", temp->name, temp->key);
            temp = temp->next;
        }
        printf("\n");
    }

    fclose(fp);
    fclose(fpSearch);
}

void insert(int D, char* str) {
    nodePointer newnode = (nodePointer)malloc(sizeof(node));
    int name = stringToInt(str);
    int bucketIndex = hashing(name, D);

    strcpy(newnode->name, str);
    newnode->key = name;
    newnode->next = NULL;

    nodePointer temp = head[bucketIndex];
    nodePointer prev = NULL;

    if (!temp) {
        head[bucketIndex] = newnode;
    }
    else {
        while (temp && temp->key < newnode->key) {
            prev = temp;
            temp = temp->next;
        }
        if (prev == NULL) {
            newnode->next = head[bucketIndex];
            head[bucketIndex] = newnode;
        }
        else {
            newnode->next = temp;
            prev->next = newnode;
        }
    }
}

int stringToInt(char* key) {
    int number = 0;
    while (*key) {
        number += *key++;
    }
    return number;
}

int hashing(int name, int D) {
    return name % D;
}

int search(int D, char* str) {
    int name = stringToInt(str);
    int bucketIndex = hashing(name, D);

    nodePointer temp = head[bucketIndex];

    while (temp) {
        if (strcmp(temp->name, str) == 0) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

//hashing - bst
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LOAD_FACTOR_THRESHOLD 0.75

typedef struct bstNode
{
    char name[10];
    unsigned int key;
    struct bstNode* left, * right;
} bstNode;

typedef bstNode* nodePointer;

typedef struct
{
    nodePointer* table;
    int size;
    int itemCount;
} HashTable;

HashTable* createHashTable(int size);
void insert(HashTable* hashTable, char* str, int isRehashing);
int stringToInt(char* key);
int hashing(int name, int size);
nodePointer insertBST(nodePointer root, char* str, unsigned int key);
void expandHashTable(HashTable* hashTable);
void rehashing(HashTable* hashTable, nodePointer* oldTable, int oldSize);
void freeBST(nodePointer root);
void traverseAndInsert(HashTable* hashTable, nodePointer root);
void inorderTraversal(nodePointer root);
int searchBST(nodePointer root, char* str);

int main()
{
    int D;
    scanf("%d", &D);
    HashTable* hashTable = createHashTable(D);

    FILE* fp = fopen("in.txt", "r");

    char str[4];
    while (fscanf(fp, "%3s", str) != EOF) {
        insert(hashTable, str, 0);
    }

    FILE* fpSearch = fopen("search.txt", "r");

    while (fscanf(fpSearch, "%3s", str) != EOF) {
        int check = 0;
        for (int i = 0; i < hashTable->size && !check; i++) {
            if (searchBST(hashTable->table[i], str)) {
                printf("S\n");
                check = 1;
            }
        }
        if (!check) {
            printf("E\n");
        }
    }
    printf("\n");


    for (int i = 0; i < hashTable->size; i++) {
        printf("%d: ", i);
        inorderTraversal(hashTable->table[i]);
        printf("\n");
    }

    for (int i = 0; i < hashTable->size; i++) {
        freeBST(hashTable->table[i]);
    }

    free(hashTable->table);
    free(hashTable);
    fclose(fp);
    fclose(fpSearch);
}

HashTable* createHashTable(int size)
{
    HashTable* hashTable = (HashTable*)malloc(sizeof(HashTable));
    hashTable->size = size;
    hashTable->itemCount = 0;
    hashTable->table = (nodePointer*)malloc(sizeof(nodePointer) * size);
    for (int i = 0; i < size; i++)
        hashTable->table[i] = NULL;
    return hashTable;
}

void insert(HashTable* hashTable, char* str, int isRehashing)
{
    int name = stringToInt(str);
    int bucketIndex = hashing(name, hashTable->size);

    hashTable->table[bucketIndex] = insertBST(hashTable->table[bucketIndex], str, name);

    if (!isRehashing) {
        hashTable->itemCount++;
        double loadFactor = (double)hashTable->itemCount / hashTable->size;
        if (loadFactor > LOAD_FACTOR_THRESHOLD) {
            expandHashTable(hashTable);
        }
    }
}

int stringToInt(char* key) {
    int number = 0;
    while (*key)
        number += *key++;
    return number;
}

int hashing(int name, int size)
{
    return name % size;
}

nodePointer insertBST(nodePointer root, char* str, unsigned int key)
{
    if (root == NULL)
    {
        nodePointer newNode = (nodePointer)malloc(sizeof(bstNode));
        strcpy(newNode->name, str);
        newNode->key = key;
        newNode->left = newNode->right = NULL;
        return newNode;
    }
    if (key < root->key) {
        root->left = insertBST(root->left, str, key);
    }
    else if (key > root->key) {
        root->right = insertBST(root->right, str, key);
    }
    else {
        if (root->left == NULL) {
            root->left = insertBST(root->left, str, key);
        }
        else {
            root->right = insertBST(root->right, str, key);
        }
    }

    return root;
}

void expandHashTable(HashTable* hashTable)
{
    int oldSize = hashTable->size;
    nodePointer* oldTable = hashTable->table;

    hashTable->size = 2 * oldSize + 1;  // Resize hash table
    hashTable->table = (nodePointer*)malloc(sizeof(nodePointer) * hashTable->size);
    for (int i = 0; i < hashTable->size; i++)
        hashTable->table[i] = NULL;

    rehashing(hashTable, oldTable, oldSize);

    free(oldTable);
}

void rehashing(HashTable* hashTable, nodePointer* oldTable, int oldSize)
{
    int oldItemCount = hashTable->itemCount;
    hashTable->itemCount = 0;
    for (int i = 0; i < oldSize; i++)
    {
        nodePointer currentNode = oldTable[i];
        if (currentNode != NULL)
            traverseAndInsert(hashTable, currentNode);
    }
    hashTable->itemCount = oldItemCount;
}

void traverseAndInsert(HashTable* hashTable, nodePointer root)
{
    if (root != NULL)
    {
        traverseAndInsert(hashTable, root->left);
        insert(hashTable, root->name, 1);
        traverseAndInsert(hashTable, root->right);
    }
}

void inorderTraversal(nodePointer root)
{
    if (root != NULL)
    {
        inorderTraversal(root->left);
        printf("%s (%d) ", root->name, root->key);
        inorderTraversal(root->right);
    }
}

void freeBST(nodePointer root)
{
    if (root)
    {
        freeBST(root->left);
        freeBST(root->right);
        free(root);
    }
}

int searchBST(nodePointer root, char* str)
{
    if (root == NULL)
        return 0;

    if (strcmp(str, root->name) == 0)
        return 1;
    else if (strcmp(str, root->name) < 0)
        return searchBST(root->left, str);
    else
        return searchBST(root->right, str);
}
