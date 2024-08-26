#ifndef DLLIST
#define DLLIST

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHAR_SIZE 256

typedef struct Node_Dlist {
    char data[CHAR_SIZE];
    struct Node_Dlist* prev;
    struct Node_Dlist* next;
} Node_Dlist;

typedef struct DList {
    Node_Dlist* head;
    Node_Dlist* tail;   
    char* name;
    int size;
} DList;

DList* createDList();
Node_Dlist* createDNode(char* data);
DList* DLLAdd(DList* list, char* data);
DList* DLLAddr(DList* list, char* data);
int DLLGet(DList* list, char* string);
void printDLL(DList* list);
void DLLDel(DList* list);
void DLLRem(DList* list, int index);
void DLLRemr (DList* list);
void DLLDel_Val(DList* list, char* data);
void DLLIns(DList* list, int index, char* data);


#endif