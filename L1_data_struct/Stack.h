#ifndef STACK
#define STACK

#define CHAR_SIZE 256

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

typedef struct Node {
    char data[CHAR_SIZE];
    struct Node* next;
} Node;

typedef struct Stack {
    char name[CHAR_SIZE];
    Node* top;
    int size;
}Stack;

Stack* createStack();
void SPush(Stack* stack, char* data);
char* SPop(Stack* stack);
char* STop(Stack* stack);

#endif