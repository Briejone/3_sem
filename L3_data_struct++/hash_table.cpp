#include "hash_table.hpp"
#include <iostream>

HashTable::HashTable(int capacity) : size(0), capacity(capacity) {
    table = new Node*[capacity];
    for (int i = 0; i < capacity; i++) {
        table[i] = NULL;
    }
}

HashTable::~HashTable() {
    for (int i = 0; i < capacity; i++) {
        Node* current = table[i];
        while (current != NULL) {
            Node* toDelete = current;
            current = current->next;
            delete toDelete;
        }
    }
    delete[] table;
}

int HashTable::hashCalc(const std::string& key) const {
    int hash_val = 0;
    for (char ch : key) {
        hash_val += static_cast<int>(ch);
    }
    return hash_val % capacity;
}

void HashTable::insert(const std::string& key, const std::string& data) {
    int index = hashCalc(key);
    Node* newNode = new Node(key, data);
    if (table[index] == NULL) {
        table[index] = newNode;
    } else {
        Node* current = table[index];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
    size++;
}

std::string HashTable::remove(const std::string& key) {
    int index = hashCalc(key);
    Node* current = table[index];
    Node* prev = NULL;

    while (current != NULL && current->key != key) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        return ""; // Key not found
    }

    std::string removedData = current->data;
    if (prev == NULL) {
        table[index] = current->next;
    } else {
        prev->next = current->next;
    }

    delete current;
    size--;
    return removedData;
}

std::string HashTable::get(const std::string& key) const {
    int index = hashCalc(key);
    Node* current = table[index];

    while (current != NULL && current->key != key) {
        current = current->next;
    }

    if (current == NULL) {
        return ""; // Key not found
    }

    return current->data;
}
