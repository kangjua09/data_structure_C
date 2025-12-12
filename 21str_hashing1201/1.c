#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define KEY_STR_LENGTH 4

typedef struct
{
    char key_str[KEY_STR_LENGTH];
    int key;
} element;

element **ht;
int b;
element *search(int k);

int stringToInt(char *key)
{
    int number = 0;
    while (*key)
    {
        number += *key++;
    }
    return number;
}

int h(int k)
{
    return k % b;
}

void Insert(element *item)
{
    int homeBucket, currentBucket;
    int k = item->key;
    homeBucket = h(k);

    for (currentBucket = homeBucket; ht[currentBucket] != NULL;)
    {
        currentBucket = (currentBucket + 1) % b;
        if (currentBucket == homeBucket)
        {
            printf("Overflow: Hash table is full or cannot insert key %s (%d)\n", item->key_str, k);
            return;
        }
    }
    ht[currentBucket] = item;
}

element *search(int k)
{
    int homeBucket, currentBucket;
    homeBucket = h(k);

    for (currentBucket = homeBucket; ht[currentBucket] && ht[currentBucket]->key != k;)
    {
        currentBucket = (currentBucket + 1) % b;
        if (currentBucket == homeBucket)
            return NULL;
    }
    if (ht[currentBucket] != NULL && ht[currentBucket]->key == k)
        return ht[currentBucket];

    return NULL;
}

int main()
{
    scanf("%d", &b);

    ht = (element **)calloc(b, sizeof(element *)); // 안전성 확보(ai)
    if (ht == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    char key_buffer[KEY_STR_LENGTH];

    FILE *file_in = fopen("in.txt", "r");
    if (file_in == NULL)
    {
        printf("Failed to open in.txt.\n");
        free(ht);
        return 1;
    }

    while (fscanf(file_in, "%s", key_buffer) == 1)
    {
        element *new_element = (element *)malloc(sizeof(element));
        if (new_element == NULL)
        {
            printf("Element memory allocation failed.\n");
            break;
        }
        strcpy(new_element->key_str, key_buffer);
        new_element->key = stringToInt(key_buffer);
        Insert(new_element);
    }

    FILE *file_search = fopen("search.txt", "r");
    if (file_search == NULL)
    {
        printf("Failed to open search.txt.\n");
        fclose(file_in);
        return 1;
    }

    while (fscanf(file_search, "%s", key_buffer) == 1)
    {
        int search_code = stringToInt(key_buffer);
        element *result = search(search_code);

        if (result != NULL)
        {
            printf("S\n");
        }
        else
        {
            printf("E\n");
        }
    }

    printf("/* Hash Table */\n");
    for (int i = 0; i < b; i++)
    {
        printf("%d: ", i);
        if (ht[i] != NULL)
        {
            printf("%s (%d)", ht[i]->key_str, ht[i]->key);
        }
        printf("\n");
    }
    for (int i = 0; i < b; i++)
    {
        if (ht[i] != NULL)
        {
            free(ht[i]);
        }
    }
    free(ht);

    fclose(file_in);
    fclose(file_search);

    return 0;
}