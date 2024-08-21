#ifndef QUEUE_H
#define QUEUE_H

#include <string>

class Queue {
private:
    struct Node {
        std::string data;
        Node* next;
        Node(const std::string& data) : data(data), next(nullptr) {}
    };
    Node* head;
    Node* tail;
    int size;

public:
    Queue();
    ~Queue();
    void enqueue(const std::string& data);
    std::string dequeue();
    std::string front() const;
    bool isEmpty() const;
};

#endif // QUEUE_H
