#ifndef STACK_H
#define STACK_H

#include <string>

class Stack {
private:
    struct Node {
        std::string data;
        Node* next;
        Node(const std::string& data) : data(data), next(nullptr) {}
    };
    Node* top;
    int size;

public:
    Stack();
    ~Stack();
    void push(const std::string& data);
    std::string pop();
    std::string peek() const;
    bool isEmpty() const;
};

#endif // STACK_H
