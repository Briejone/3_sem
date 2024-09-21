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
int isValidExpression(char* expression);
int isOperator(char ch);

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
        printf("Stack underflow: too many operators or invalid expression\n");
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

int isValidExpression(char* expression) {
    int operands = 0;
    int operators = 0;

    for (int i = 0; expression[i] != '\0'; i++) {
        if (isdigit(expression[i])) {
            operands++;
        } else if (isOperator(expression[i])) {
            operators++;
            if (operators >= operands) {
                // Слишком много операторов по сравнению с операндами
                return 0;
            }
        } else {
            // Недопустимый символ
            return 0;
        }
    }
    return (operands == operators + 1); // Должно быть на 1 больше операндов, чем операторов
}

int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

int evaluatePostfix(char* expression) {
    Stack* stack = createStack();

    if (!isValidExpression(expression)) {
        printf("Invalid expression\n");
        free(stack);
        return -1;
    }

    for (int i = 0; expression[i] != '\0'; i++) {
        if (isdigit(expression[i])) {
            SPush(stack, expression[i] - '0');
        } else {
            int operand2 = SPop(stack);
            int operand1 = SPop(stack);

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
                    if (operand2 == 0) {
                        printf("Division by zero error\n");
                        free(stack);
                        exit(1);
                    }
                    SPush(stack, operand1 / operand2);
                    break;
            }
        }
    }

    int result = SPop(stack);
    free(stack);
    return result;
}

int main() {
    char expression[] = "314*+";
    int result = evaluatePostfix(expression);
    
    if (result != -1) {
        printf("Result of %s is %d\n", expression, result);
    }

    return 0;
}
