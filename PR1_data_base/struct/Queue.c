#include "Queue.h"

Queue* createQueue() {
    Queue* queue = NULL;
    queue = (Queue*) malloc(sizeof(Queue));
    queue->size = 0;
    queue->head = NULL;
    queue->tail = NULL;
    return queue;
}

queue_node* QPush (Queue* queue, char* data) {
    queue_node* node = (queue_node*)malloc(sizeof(queue_node*));
    if(data == NULL) {
        return 0;
    }
    node->next = NULL;  
    strcpy(node->data, data);
    if (queue->head == NULL) {
        queue->head = node;
        queue->tail = node;
    } else {
        queue->tail->next = node;
        queue->tail = node;
    }
    queue->size++;
    //printf("%s\n", queue->tail->data);
    return node;
}

char* QPop(Queue* queue) {
    char* data = queue->head->data;
    if (queue->head == NULL) {
        return 0;
    } else {
        queue->head = queue->head->next;
        queue->size--;
    }
    //printf("%s\n", data);
    return data;
}

// int main() {
//     Queue* queue = createQueue();
//     QPush(queue, "kryto");
//     QPush(queue, "brawl stars");
//     printf("%s\n", QPop(queue));
//     printf("%s", QPop(queue));
//     return 0;
// }