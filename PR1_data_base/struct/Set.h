#ifndef HASHSET
#define HASHSET

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "define.h"

typedef struct Node_set {
    char* data;
    struct Node_set* next;
} Node_set;

typedef struct HashSet {
    Node_set** table;
    int size;
} HashSet;

HashSet* createHashSet(int size);
int HashCalc(char* data);
int HSetAdd(HashSet *hashset, char *data);
char* HSetRemove(HashSet* hashset, char* data);
int HSetContains(HashSet* hashset, char* data);

#endif