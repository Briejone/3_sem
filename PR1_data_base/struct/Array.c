#include "Array.h"

Array* create_array(int capacity) {
    Array* arr = (Array*)malloc(sizeof(Array));
    if (arr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    for (int i = 0; i < capacity; i++) {
        arr->data[i] = (char*)malloc(CHAR_SIZE * sizeof(char));
        if (arr->data[i] == NULL) {
            fprintf(stderr, "Memory allocation failed for element %d\n", i);
            for (int j = 0; j < i; j++) {
                free(arr->data[j]);
            }
            free(arr);
            return NULL;
        }
    }
    arr->size = 0;
    arr->capacity = capacity;
    return arr;
}

int ARRAdd(Array* arr, char* data) {
    // printf("%s\n", data);
    if (arr->size >= arr->capacity) {
        fprintf(stderr, "Array is full\n");
        return -1;
    }
    if(data == NULL || strcmp(data, "  ") == 0) {
        //printf("%s", data);
        return 0;
    }
    strcpy(arr->data[arr->size++], data);
    

    return 0;
}

char* ARRDel (Array* arr) {
    char* data = (char*)malloc(CHAR_SIZE * sizeof(char));
    strcpy(data, arr->data[--arr->size]);
    arr->data[arr->size + 1] = 0;
    return data;
}

char* ARRDelr(Array* arr) {
    if (arr->size == 0) {
        return NULL;
    }
    char* data = arr->data[0];
    for (int i = 0; i < arr->size - 1; i++) {
        //printf("%s", arr->data[i]);
        arr->data[i] = arr->data[i + 1];
    }

    arr->size--;

    arr->data[arr->size] = 0;
    //printf("tut:%s", data);
    return data;
}

int ARRIns (Array* arr, char* data, int pos) {
    arr->size++;
    for(int i = arr->size - 1; i > pos; i--) {
        strcpy(arr->data[i], arr->data[i-1]);
    }
    strcpy(arr->data[pos], data);
    return 0;
}

char*  ARRem (Array* arr, int pos) {
    char* data = (char*)malloc(CHAR_SIZE * sizeof(char));
    strcpy(data, arr->data[pos]);
    for (int i = pos; i < arr->size; i++) {
        arr->data[i] = arr->data[i+1];
    }
    arr->size--;
    return data;
}

int ARRChg(Array* arr, char* data, int pos) {
    strcpy(arr->data[pos], data);
    return 0;
}

char* ARRGet(Array* arr, int pos) {
    return arr->data[pos];
}

void print_array (Array* arr) {
    for( int i = 0; i < arr->size; i++ ) {
        printf("%d = %s\n",i , arr->data[i]);
    }
}

int ARRSrch(Array* arr, char* data) {
    for(int i = 0; i < arr->size; i++) {
        if(strcmp(arr->data[i], data) == 0) {
            return i;
        }
    }
    return -1;
}

// int main() {
//     Array* arr = create_array(5);
//     ARRAdd(arr, "9");
//     ARRAdd(arr, "8");
//     ARRAdd(arr, "7");
//     ARRAdd(arr, "6");
//     ARRAdd(arr, "5");
//     printf("%s\n", ARRDelr(arr));
//     printf("%s\n", ARRDelr(arr));
//     printf("%s\n", ARRDelr(arr));
//     printf("%s\n", ARRDelr(arr));
//     printf("%s\n", ARRDelr(arr));
//     //printf("%s\n", ArrGet(arr, 1));
//     // printf("%s\n", ArrGet(arr, 2));
//     // printf("%s\n", ArrGet(arr, 3));
//     // printf("%s\n", ArrGet(arr, 4));

//     return 0;   
// }