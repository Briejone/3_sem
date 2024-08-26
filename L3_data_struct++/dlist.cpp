#include "dlist.hpp"
#include <stdexcept>

DoublyLinkedList::DoublyLinkedList() : head(NULL), tail(NULL), size(0) {}

DoublyLinkedList::~DoublyLinkedList() {
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

void DoublyLinkedList::addFront(const std::string& data) {
    Node* newNode = new Node(data);
    if (head == NULL) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    size++;
}

void DoublyLinkedList::addBack(const std::string& data) {
    Node* newNode = new Node(data);
    if (tail == NULL) {
        head = tail = newNode;
    } else {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
    size++;
}

std::string DoublyLinkedList::removeFront() {
    if (isEmpty()) {
        throw std::out_of_range("List is empty");
    }
    Node* temp = head;
    std::string removedData = temp->data;
    if (head == tail) {
        head = tail = NULL;
    } else {
        head = head->next;
        head->prev = NULL;
    }
    delete temp;
    size--;
    return removedData;
}

std::string DoublyLinkedList::removeBack() {
    if (isEmpty()) {
        throw std::out_of_range("List is empty");
    }
    Node* temp = tail;
    std::string removedData = temp->data;
    if (head == tail) {
        head = tail = NULL;
    } else {
        tail = tail->prev;
        tail->next = NULL;
    }
    delete temp;
    size--;
    return removedData;
}

bool DoublyLinkedList::remove(const std::string& data) {
    if (isEmpty()) {
        return false;
    }
    if (head->data == data) {
        removeFront();
        return true;
    } else if (tail->data == data) {
        removeBack();
        return true;
    }

    Node* current = head->next;
    while (current != NULL && current->data != data) {
        current = current->next;
    }

    if (current != NULL) {
        current->prev->next = current->next;
        if (current->next != NULL) {
            current->next->prev = current->prev;
        }
        delete current;
        size--;
        return true;
    }

    return false;
}

std::string DoublyLinkedList::get(int index) const {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of bounds");
    }
    Node* current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current->data;
}

int DoublyLinkedList::find(const std::string& data) const {
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

int DoublyLinkedList::getSize() const {
    return size;
}

bool DoublyLinkedList::isEmpty() const {
    return head == NULL;
}
