#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <string>

class LinkedList {
private:
    struct Node {
        std::string data;
        Node* next;
        Node(const std::string& data) : data(data), next(nullptr) {}
    };

    Node* head;
    int size;

public:
    LinkedList();
    ~LinkedList();

    void add(const std::string& data);
    std::string remove();
    bool remove(const std::string& data);
    std::string get(int index) const;
    int find(const std::string& data) const;
    int getSize() const;
    bool isEmpty() const;
};

#endif // LINKEDLIST_H
