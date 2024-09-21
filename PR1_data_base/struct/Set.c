#include "Set.h"

HashSet* createHashSet(int size) {
    HashSet* hashset = (HashSet*)malloc(sizeof(HashSet));
    hashset->size = size;
    hashset->table = (Node_set**)malloc(sizeof(Node_set **) * size);
    for (int i = 0; i < size; i++) {
        hashset->table[i] = NULL;
    }
    return hashset;
}

int HashCalcSet(char* data) {
    int hash_val = 0;
    for (int i = 0; i < (int)strlen(data); i++) {
        hash_val += (int)data[i];
    }
    return hash_val % CHAR_SIZE;
}

int HSetAdd(HashSet* hashset, char* data) {
    int index = HashCalcSet(data) % hashset->size;
    Node_set* newNode = (Node_set*)malloc(sizeof(Node_set));
    newNode->data = data;
    newNode->next = NULL;

    if (hashset->table[index] == NULL) {
        hashset->table[index] = newNode;
        return 1;
    } else {
        Node_set* current = hashset->table[index];
        while (current != NULL) {
            if (strcmp(current->data, data) == 0) {
                // Элемент уже существует в множестве
                return 0;
            }
            if (current->next == NULL) {
                current->next = newNode;
                return 1;
            }
            current = current->next;
        }
    }
    return 1;
}

char* HSetRemove(HashSet* hashset, char* data) {
    int index = HashCalcSet(data);
    if (hashset->table[index] == NULL) {
        return NULL;  // Элемент не найден
    } else {
        Node_set* current = hashset->table[index];
        Node_set* prev = NULL;
        while (current != NULL) {
            if (strcmp(current->data, data) == 0) {
                if (prev == NULL) {
                    hashset->table[index] = current->next;
                } else {
                    prev->next = current->next;
                }

                char* removedData = strdup(current->data);
                
                free(current);
                
                return removedData;
            }
            prev = current;
            current = current->next;
        }
    }
    return NULL;
}
int HSetContains(HashSet* hashset, char* data) {
    int index = HashCalcSet(data);
    Node_set* current = hashset->table[index];
    while (current != NULL) {
        if (strcmp(current->data, data) == 0) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

// Пример использования

// int main() {
//     HashSet* set = createHashSet(MAX_SIZE);
//     HSetAdd(set, "Hello");
//     HSetAdd(set, "World");
//     printf("%d\n", HSetContains(set, "Hello")); // 1
//     printf("%d\n", HSetContains(set, "C"));     // 0
//     HSetRemove(set, "Hello");
//     printf("%d\n", HSetContains(set, "Hello")); // 0
//     return 0;
// }
