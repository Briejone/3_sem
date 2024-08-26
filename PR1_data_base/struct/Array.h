#ifndef ARRAY
#define ARRAY

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

#define CHAR_SIZE 256

typedef struct Array {
    char* data[CHAR_SIZE];
    int size;
} Array;

Array* create_array (int size);
int ArrAdd (Array* arr, char* data);
char* ArrDel (Array* arr);
int ArrIns (Array* arr, char* data, int pos);
char*  ArrRem (Array* arr, int pos);
int ArrChg(Array* arr, char* data, int pos);
char* ArrGet(Array* arr, int pos);
void print_array (Array* arr);
int ArrSrch(Array* arr, char* data);

#endif