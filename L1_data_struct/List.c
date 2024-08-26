#include "List.h"

List* create_list() {
    List* list = (List*)malloc(sizeof(List));
    list->head = NULL;
    list->size = 0;
    return list;
}

Lnode* create_node(char* data) {
    if (strlen(data) > CHAR_SIZE) {
        perror("Error: data size > CHAR_SIZE\n");
        exit(1);
    }
    Lnode* node = (Lnode*)malloc(sizeof(Lnode));
    strcpy(node->data, data);
    node->next = NULL;
    return node;
}

Lnode* LAdd(List* list, char* data) {
    Lnode* node = create_node(data);
    if (list->head == NULL) {
        list->head = node;
        list->size++;
    } else {
        node->next = list->head;
        list->head = node;
        list->size++;
    }
    return node;
}

Lnode* LAddr(List* list, char* data) {
    Lnode* node = create_node(data);
    Lnode* tmp = list->head;
    list->size++;
    if (list->head == NULL) {
        list->head = node;
    } else {
        while(tmp->next != NULL) {
            tmp = tmp->next;
        }
        tmp->next = node;
    }
    return node;
}

Lnode* LIns(List* list, int index, char* data) {
    Lnode* node = create_node(data);
    Lnode* tmp = list->head;
    strcpy(node->data, data);
    int count = 0;
    if (list->size < index - 1) {
        perror("ERROR: index is of range");
        return NULL;
    }
    if (list->head == NULL && index == 0) {
        list->head = node;
        list->size++;
        return node;
    }
    while(count < index - 1) {
        tmp = tmp->next;
        count++;
    }
    if (index == 0) {
        LAdd(list, data);
        return node;
    } else if (index == list->size) {
        LAddr(list, data);
        return node;
    } else if (count == index - 1) {
        node->next = tmp->next;
        tmp->next = node;
        list->size++;
    }
    
    return node;
}

char* LDel(List* list) {
    char* data = list->head->data;
    if(list->head == NULL) {
        perror("null");
        return NULL;
    } else {
        list->head = list->head->next;
        list->size--;
    }
    return data;
}

int LDel_val(List* list, char* data) {
    int index = LGet(list, data);
    int counter = 0;
    Lnode* tmp = list->head;
    while(counter < index - 1) {
        tmp = tmp->next;
        counter++;
    }
    tmp->next = tmp->next->next;
    list->size--;
    return index;
}

int LGet(List* list, char* data) {
    Lnode* tmp = list->head;
    int index = 0;
    if (tmp == NULL) {
        return -1;
    } 
    while (tmp != NULL && strcmp(tmp->data, data) != 0) {
        tmp = tmp->next;
        index++;
    }
    if(tmp == NULL) {
        return -1;
    } else {
        return index;
    }
}


// int main() {
//     printf("stupid huina");
//     return 0;
// }