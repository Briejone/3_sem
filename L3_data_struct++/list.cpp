#include "list.hpp"
#include <stdexcept>

LinkedList::LinkedList() : head(NULL), size(0) {}

LinkedList::~LinkedList() {
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

void LinkedList::add(const std::string& data) {
    Node* newNode = new Node(data);
    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    size++;
}

std::string LinkedList::remove() {
    if (isEmpty()) {
        throw std::out_of_range("List is empty");
    }
    Node* temp = head;
    head = head->next;
    std::string removedData = temp->data;
    delete temp;
    size--;
    return removedData;
}

bool LinkedList::remove(const std::string& data) {
    if (isEmpty()) {
        return false;
    }
    if (head->data == data) {
        Node* temp = head;
        head = head->next;
        delete temp;
        size--;
        return true;
    }

    Node* current = head;
    while (current->next != NULL && current->next->data != data) {
        current = current->next;
    }

    if (current->next != NULL) {
        Node* temp = current->next;
        current->next = temp->next;
        delete temp;
        size--;
        return true;
    }

    return false;
}

std::string LinkedList::get(int index) const {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of bounds");
    }
    Node* current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current->data;
}

int LinkedList::find(const std::string& data) const {
    Node* current = head;
    int index = 0;
    while (current != NULL) {
        if (current->data == data) {
            return index;
        }
        current = current->next;
        index++;
    }
    return -1;
}

int LinkedList::getSize() const {
    return size;
}

bool LinkedList::isEmpty() const {
    return head == NULL;
}
