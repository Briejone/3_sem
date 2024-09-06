#include "Stack.h"


Stack* createStack() {
    Stack* stack = NULL;
    stack = (Stack*)malloc(sizeof(Stack));
    stack->size = 0;
    stack->top = NULL;
    return stack;
}

int SPush(Stack* stack, char* data) {
    Node *node = (Node*)malloc(sizeof(Node));
    if (data == NULL) {
        return 0;
    }
    if (stack->top == NULL) {
        stack->top = node;
        strcpy(stack->top->data, data);
    } else {
    node->next = stack->top;
    stack->top = node;
    strcpy(stack->top->data, data);
    }
    // printf("это очень весело");
    //printf("|%s\n", stack->top->data);
    stack->size++;
    return 0;
}


char* SPop(Stack* stack) {
    if (stack->top == NULL) {
        return NULL;
    }

    Node *temp = stack->top;
    stack->top = stack->top->next;
    stack->size--;
    //printf("%s", temp->data);
    char *data = (char*)malloc(sizeof(char) * CHAR_SIZE);
    if (data != NULL) {
        strcpy(data, temp->data);
    }

    free(temp);
    return data;
}

char* STop(Stack* stack) {
    if(stack->top == NULL) {
        return NULL;
    }
    return stack->top->data;
}

// int main() {
//     Stack* stack = createStack();
//     SPush(stack, "kryto");
//     SPush(stack, "brawl stars");
//     printf("%s\n", SPop(stack));
//     printf("%s", SPop(stack));

//     return 0;
// }