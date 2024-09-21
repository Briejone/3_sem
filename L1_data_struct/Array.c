#include "Array.h"

Array* create_array (int size) {
    Array* arr = (Array*)malloc(sizeof(Array));
    for ( int i = 0; i < size; i++ ) {
        arr->data[i] = (char*)malloc(CHAR_SIZE * sizeof(char));
    }
    return arr;
}

int ArrAdd (Array* arr, char* data) {
    strcpy(arr->data[arr->size++], data);
    return 0;
}

char* ArrDel (Array* arr) {
    char* data = (char*)malloc(CHAR_SIZE * sizeof(char));
    strcpy(data, arr->data[--arr->size]);
    arr->data[arr->size + 1] = 0;
    return data;
}

int ArrIns (Array* arr, char* data, int pos) {
    arr->size++;
    for(int i = arr->size - 1; i > pos; i--) {
        strcpy(arr->data[i], arr->data[i-1]);
    }
    strcpy(arr->data[pos], data);
    return 0;
}

char*  ArrRem (Array* arr, int pos) {
    char* data = (char*)malloc(CHAR_SIZE * sizeof(char));
    strcpy(data, arr->data[pos]);
    for (int i = pos; i < arr->size; i++) {
        arr->data[i] = arr->data[i+1];
    }
    arr->size--;
    return data;
}

int ArrChg(Array* arr, char* data, int pos) {
    strcpy(arr->data[pos], data);
    return 0;
}

char* ArrGet(Array* arr, int pos) {
    return arr->data[pos];
}

void print_array (Array* arr) {
    for( int i = 0; i < arr->size; i++ ) {
        printf("%d = %s\n",i , arr->data[i]);
    }
}

int ArrSrch(Array* arr, char* data) {
    for(int i = 0; i < arr->size; i++) {
        if(strcmp(arr->data[i], data) == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    Array* arr = create_array(5);
    ArrAdd(arr, "9");
    ArrAdd(arr, "8");
    ArrAdd(arr, "7");
    ArrAdd(arr, "6");
    ArrAdd(arr, "5");
    printf("%s\n", ArrGet(arr, 0));
    printf("%s\n", ArrDel(arr));
    printf("%d\n", ArrIns(arr,"ldld",  0));
    printf("%d\n", ArrSrch(arr, "7"));
    printf("%s\n", ArrGet(arr, 4));
    print_array(arr);

    return 0;   
}