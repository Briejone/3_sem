#include "Stack.h"


Stack* createStack() {
    Stack* stack = NULL;
    stack = (Stack*)malloc(sizeof(Stack));
    stack->size = 0;
    stack->top = NULL;
    return stack;
}

void SPush(Stack* stack, char* data) {
    Node* node = (Node*)malloc(sizeof(Node));
    if (stack->top == NULL) {
        stack->top = node;
        strcpy(stack->top->data, data);
    } else {
    node->next = stack->top;
    stack->top = node;
    strcpy(stack->top->data, data);
    }
    stack->size++;
}


char* SPop(Stack* stack) {
    if (stack->top == NULL) {
        return NULL;
    } else {
        char *data = (char*)malloc(sizeof(stack->top->data));
        strcpy(data,stack->top->data);
        stack->top = stack->top->next;
        stack->size--;
        return data;
    }
}

char* STop(Stack* stack) {
    if(stack->top == NULL) {
        return NULL;
    }
    return stack->top->data;
}

int main() {
    Stack* stack = createStack();
    SPush(stack, "kryto");
    SPush(stack, "brawl stars");
    printf("%s\n", SPop(stack));
    printf("%s", SPop(stack));

    return 0;
}