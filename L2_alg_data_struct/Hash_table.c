#include "Hash_table.h"

HashTable* createHashTable(int size) {
    HashTable* hashtable = (HashTable*)malloc(sizeof(HashTable));
    hashtable->size = size;
    hashtable->table = malloc(sizeof(Node_hash **) * size);
    for (int i = 0; i < size; i++) {
        hashtable->table[i] = NULL;
    }
    return hashtable;
}

int HashCalc(char* key) {
    int hash_val = 0;
    for (int i = 0; i < (int)strlen(key); i++) {
        hash_val += (int)key[i];
    }
    return hash_val % CHAR_SIZE;
}

char* HSet(HashTable* hashtable, char* key, char* data) {
    int index = HashCalc(key) % hashtable->size;
    Node_hash *newNode = (Node_hash *)malloc(sizeof(Node_hash));
    newNode->key = key;
    newNode->data = data;
    newNode->next = NULL;
    if (hashtable->table[index] == NULL) {
        hashtable->table[index] = newNode;
    } else {
        Node_hash *current = hashtable->table[index];
        while (current->next != NULL) {
            if (strcmp(current->key, key) == 0) {
                strcpy(current->data, data);
                return data;
            }
            current = current->next;
        }
        current->next = newNode;
    }
    
    return data;
}

char *HDel(HashTable* hashtable, char* key) {
    int index = HashCalc(key);
    if (hashtable->table[index] == NULL) {
        return NULL;
    } else {
        Node_hash *current = hashtable->table[index];
        Node_hash *prev = NULL;
        while (current != NULL) {
            if (strcmp(current->key, key) == 0) {
                char *data = current->data;
                if (prev == NULL) {
                    hashtable->table[index] = current->next;
                } else {
                    prev->next = current->next;
                }
                return data;
            }
            prev = current;
            current = current->next;
        }
    }
    return NULL;
}

char* HGet(HashTable* hashtable, char* key) {
    int index = HashCalc(key);
    Node_hash *current = hashtable->table[index];
    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            return current->data;
        }
        current = current->next;
    }
    return NULL;
}

// int main() {
//     HashTable* table = createHashTable(MAX_SIZE);
//     HSet(table, "1", "kruto");
//     HSet(table, "1", "brawl stars");
//     HSet(table, "3", "chinazes");
//     printf("%s\n", HDel(table, "1"));
//     printf("%s\n", HDel(table, "1"));
//     printf("%s\n", HGet(table, "3"));
//     return 0;
// }