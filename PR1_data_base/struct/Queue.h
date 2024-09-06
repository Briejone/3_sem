#ifndef QUEUE
#define QUEUE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "define.h"

typedef struct queue_node {
    char data[256];
    struct queue_node* next;
}queue_node;

typedef struct Queue {
    queue_node* head;
    queue_node* tail;
    int size;
}Queue;


Queue* createQueue();
queue_node* QPush (Queue* queue, char* data);
char* QPop(Queue* queue);

#endif
