#include "queue.hpp"
#include <stdexcept>

Queue::Queue() : head(NULL), tail(NULL), size(0) {}

Queue::~Queue() {
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

void Queue::enqueue(const std::string& data) {
    Node* newNode = new Node(data);
    if (isEmpty()) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
    size++;
}

std::string Queue::dequeue() {
    if (isEmpty()) {
        throw std::out_of_range("Queue is empty");
    }
    Node* temp = head;
    std::string dequeuedData = temp->data;
    head = head->next;
    delete temp;
    size--;
    return dequeuedData;
}

std::string Queue::front() const {
    if (isEmpty()) {
        throw std::out_of_range("Queue is empty");
    }
    return head->data;
}

bool Queue::isEmpty() const {
    return head == NULL;
}
