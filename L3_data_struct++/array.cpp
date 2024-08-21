#include "array.hpp"
#include <iostream>
#include <cstring>
#include <cstdlib>

Array::Array(int size) : size(0) {
    for (int i = 0; i < size; i++) {
        data[i] = new char[CHAR_SIZE];
    }
}

Array::~Array() {
    for (int i = 0; i < size; i++) {
        delete[] data[i];
    }
}

char* Array::ArrAdd(const char* newData) {
    if (size < CHAR_SIZE) {
        std::strcpy(data[size], newData);
        return data[size++];
    }
    return NULL; // Ошибка, массив переполнен
}

char* Array::ArrDel() {
    if (size > 0) {
        char* deletedData = new char[CHAR_SIZE];
        std::strcpy(deletedData, data[size - 1]);
        delete[] data[size - 1];
        size --;
        return deletedData;
    }
    return NULL; // Ошибка, массив пуст
}

int Array::ArrIns(const char* newData, int pos) {
    if (pos >= 0 && pos <= size && size < CHAR_SIZE) {
        size++;
        for (int i = size - 1; i > pos; i--) {
            std::strcpy(data[i], data[i - 1]);
        }
        std::strcpy(data[pos], newData);
        return 0;
    }
    return -1; // Ошибка, неверная позиция или массив переполнен
}

char* Array::ArrRem(int pos) {
    if (pos >= 0 && pos < size) {
        char* removedData = new char[CHAR_SIZE];
        std::strcpy(removedData, data[pos]);
        delete[] data[pos];
        for (int i = pos; i < size - 1; i++) {
            data[i] = data[i + 1];
        }
        size--;
        return removedData;
    }
    return NULL; // Ошибка, неверная позиция
}

int Array::ArrChg(const char* newData, int pos) {
    if (pos >= 0 && pos < size) {
        std::strcpy(data[pos], newData);
        return 0;
    }
    return -1; // Ошибка, неверная позиция
}

char* Array::ArrGet(int pos) {
    if (pos >= 0 && pos < size) {
        return data[pos];
    }
    return NULL; // Ошибка, неверная позиция
}

void Array::print_array() const {
    for (int i = 0; i < size; i++) {
        std::cout << i << " = " << data[i] << std::endl;
    }
}

int Array::ArrSrch(const char* searchData) const {
    for (int i = 0; i < size; i++) {
        if (std::strcmp(data[i], searchData) == 0) {
            return i;
        }
    }
    return -1; // Не найдено
}
