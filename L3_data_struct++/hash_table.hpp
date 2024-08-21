#ifndef HASH_TABLE_HPP
#define HASH_TABLE_HPP

#include <string>

class HashTable {
private:
    struct Node {
        std::string key;
        std::string data;
        Node* next;

        Node(const std::string& k, const std::string& d) : key(k), data(d), next(nullptr) {}
    };

    Node** table;
    int size;
    int capacity;

    int hashCalc(const std::string& key) const;

public:
    HashTable(int capacity);
    ~HashTable();

    void insert(const std::string& key, const std::string& data);
    std::string remove(const std::string& key);
    std::string get(const std::string& key) const;
    int getSize() const { return size; }
};

#endif // HASH_TABLE_HPP
