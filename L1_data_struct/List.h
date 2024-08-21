#ifndef LIST
#define LIST

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHAR_SIZE 256

typedef struct ListNode {
    struct ListNode* next;
    char data[CHAR_SIZE];
}Lnode;

typedef struct List {
    Lnode* head;
    int size;
}List;

List* create_list();
Lnode* create_node(char* data);
Lnode* LAdd(List* list, char* data);
Lnode* LAddr(List* list, char* data);
Lnode* LIns(List* list, int index, char* data);
char* LDel(List* list);
int LDel_val(List* list, char* data);
int LGet(List* list, char* data);

#endif