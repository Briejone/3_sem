#ifndef HASHTABLE
#define HASHTABLE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHAR_SIZE 256
#define MAX_SIZE 256
#define _CRT_SECURE_NO_WARNINGS

typedef struct Node_hash {
    char* data;
    char* key;
    struct Node_hash* next;
} Node_hash;

typedef struct HashTable {
    Node_hash** table;
    int size;
    int capacity;
} HashTable;

HashTable* createHashTable(int size);
int HashCalc(char* key);
char* HSet(HashTable *hashtable, char *key, char *data);
char *HDel(HashTable *hashtable, char *key);
char *HGet(HashTable *hashtable, char *key);

#endif