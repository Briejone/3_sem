#ifndef STACK
#define STACK

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "define.h"

typedef struct Node {
    char data[CHAR_SIZE];
    struct Node* next;
} Node;

typedef struct Stack {
    Node* top;
    int size;
}Stack;

Stack* createStack();
int SPush(Stack* stack, char* data);
char* SPop(Stack* stack);
char* STop(Stack* stack);

#endif