#include "DLList.h"

DList* createDList() {
    DList* list = (DList*)malloc(sizeof(DList));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;

}


Node_Dlist* createDNode(char* data) {
    if (strlen(data) > CHAR_SIZE) {
        perror("Error: data size > CHAR_SIZE\n");
        exit(1);
    }
    Node_Dlist* newNode = (Node_Dlist*)malloc(sizeof(Node_Dlist));
    strcpy(newNode->data, data);
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

DList* DLLAdd(DList* list, char* data) {
    Node_Dlist* newNode = createDNode(data);
    if (list->head == NULL) {
        list->head = newNode;
        list->tail = newNode;
        list->size++;
    }
    else {
        Node_Dlist* old_head = list->head;
        list->head = newNode;
        list->head->next = old_head;
        old_head->prev = list->head;
        list->size++;

        //list->tail->next = newNode;
    }
    return list;
}

DList* DLLAddr(DList* list, char* data) {
    Node_Dlist* newNode = createDNode(data);
    if (list->head == NULL) {
        list->head = newNode;
        list->tail = newNode;
        list->size++;
    }
    else {
        Node_Dlist* old_tail = list->tail;
        list->tail = newNode;
        list->tail->prev = old_tail;
        old_tail->next = list->tail;
        list->size++;
        //printf("Nikita molodec\n");
    }
    return list;
}

int DLLGet(DList* list, char* string) {
    Node_Dlist* current = list->head;
    int index = 0;
    if (current == NULL) {
        return -1;
    }
    while (current != NULL && strcmp(current->data, string) != 0) {
        current = current->next;
        index++;
    }
    if (current == NULL) {
        return -1;
    }
    else {
        return index;
    }
}

void printDLL(DList* list) {
    Node_Dlist* tmp = list->head;
    while (tmp) {
        printf("%s\n", tmp->data);
        tmp = tmp->next;
    }
}

void DLLDel(DList* list) {
    if (list->head == NULL) {
        exit (0);
    }
    else {
        Node_Dlist* nextNode = list->head->next;
        if (nextNode != NULL) {
            Node_Dlist* old_head = list->head;
            free(old_head);
            nextNode->prev = NULL;
        }
        list->head = nextNode;
        list->size--;
    }
}


void DLLRem(DList* list, int index) {
  if(list->head == NULL){
    return;
  }
  if(index > list->size || index < 0) {
    perror("ERROR: index is out of range");
    return;
    //exit(1);
  }
  Node_Dlist* tmp = list->head;
  int index_c = 0;
  while(index_c < index) {
    index_c++;
    tmp = tmp->next;
  }
  Node_Dlist* tmp_prev = tmp->prev;
  Node_Dlist* tmp_next = tmp->next;

  if (tmp_prev) {
    tmp_prev->next = tmp_next;
  } else {
    list->head = tmp_next;
  }
  if (tmp_next) {
    tmp_next->prev = tmp_prev;
  } else {
    list->tail = tmp_prev;
  }
  list->size--;
  free(tmp);
}

void DLLRemr (DList* list) {
  DLLRem(list, list->size - 1);
}
void DLLDel_Val(DList* list, char* data) {
    int index = DLLGet(list, data);
    DLLRem(list, index);
}

void DLLIns(DList* list, int index, char* data) {
    Node_Dlist* newNode = createDNode(data);
    if (list->size < index) {
        perror("ERROR: index is of range");
    }
    if (list->head == NULL && index == 0) {
        list->head = newNode;
        list->tail = newNode;
        list->size++;
    } else {
        Node_Dlist* current = list->head;
        Node_Dlist* previous = NULL;
        int count = 0;
        list->size++;
        while (current != NULL && count < index) {
            previous = current;
            current = current->next;
            count++;
        }
        if (count == index) {
            newNode->next = current;
            newNode->prev = previous;
            if (current != NULL) {
                current->prev = newNode;
            } else {
                list->tail = newNode;
            }
            if (previous != NULL) {
                previous->next = newNode;
            } else {
                list->head = newNode;
            }
        }
    }
}
// int main() {
//     DList* list = createDList();
//     printf("Add:\n");
//     DLLAdd(list,"1.Terrorist wins");    //добавление в начало
//     DLLAdd(list,"0");
//     DLLAddr(list, "2.kryto");            //Добавление в конец
//     DLLAddr(list, "3.kryto");
//     DLLAddr(list, "4.kryto");
//     DLLAddr(list, "5.kryto");
//     DLLIns(list, 5, "6.kryto");
//     DLLAddr(list, "7.kryto");
//     DLLIns(list, 8, "8.kryto");             //Добавление по индексу
//     printDLL(list);
//     printf("Delete 0:\n");
//     DLLDel(list);                       //удаляет из начала
//     printf("Delete 1:\n");
//     DLLRem(list, 0);                    //Удаляет по индексу
//     printf("Delete 2:\n");
//     DLLRem(list, 1);
//     printf("Delete 3:\n");
//     DLLRemr(list);                      //Удаляет из конца
//     printDLL(list);
//     printf("poisk:\n");
//     printf("%d", DLLGet(list, "5.kryto"));                    //индекс по значению

//     return 0;
// }