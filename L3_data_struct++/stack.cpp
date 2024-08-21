#include "stack.hpp"
#include <stdexcept>

Stack::Stack() : top(NULL), size(0) {}

Stack::~Stack() {
    while (top != NULL) {
        Node* temp = top;
        top = top->next;
        delete temp;
    }
}

void Stack::push(const std::string& data) {
    Node* newNode = new Node(data);
    newNode->next = top;
    top = newNode;
    size++;
}

std::string Stack::pop() {
    if (isEmpty()) {
        throw std::out_of_range("Stack is empty");
    }
    Node* temp = top;
    std::string poppedData = temp->data;
    top = top->next;
    delete temp;
    size--;
    return poppedData;
}

std::string Stack::peek() const {
    if (isEmpty()) {
        throw std::out_of_range("Stack is empty");
    }
    return top->data;
}

bool Stack::isEmpty() const {
    return top == NULL;
}
