#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Stack {
    Node* top;
    int size;
} Stack;

Stack* createStack();
void SPush(Stack* stack, int data);
int SPop(Stack* stack);
int STop(Stack* stack);
int evaluatePostfix(char* expression);

Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->size = 0;
    stack->top = NULL;
    return stack;
}

void SPush(Stack* stack, int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = stack->top;
    stack->top = node;
    stack->size++;
}

int SPop(Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack underflow\n");
        exit(1);
    } else {
        Node* temp = stack->top;
        int data = temp->data;
        stack->top = stack->top->next;
        free(temp);
        stack->size--;
        return data;
    }
}

int STop(Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack is empty\n");
        exit(1);
    }
    return stack->top->data;
}

int evaluatePostfix(char* expression) {
    Stack* stack = createStack();
    for (int i = 0; expression[i] != '\0'; i++) {
        if (isdigit(expression[i])) {
            // Преобразуем символ цифры в целое число и кладем его в стек
            SPush(stack, expression[i] - '0');
        } else {
            // Операция: извлекаем два элемента из стека
            int operand2 = SPop(stack);
            int operand1 = SPop(stack);

            // Выполняем операцию и кладем результат обратно в стек
            switch (expression[i]) {
                case '+':
                    SPush(stack, operand1 + operand2);
                    break;
                case '-':
                    SPush(stack, operand1 - operand2);
                    break;
                case '*':
                    SPush(stack, operand1 * operand2);
                    break;
                case '/':
                    SPush(stack, operand1 / operand2);
                    break;
            }
        }
    }

    // Результат будет на вершине стека
    int result = SPop(stack);
    free(stack);
    return result;
}

int main() {
    char expression[] = "314+-";
    printf("Result of %s is %d\n", expression, evaluatePostfix(expression));
    return 0;
}
