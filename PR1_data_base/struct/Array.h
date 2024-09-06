#ifndef ARRAY
#define ARRAY

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include "define.h"


typedef struct Array {
    char* data[CHAR_SIZE];
    int size;
    int capacity;
} Array;

Array* create_array (int size);
int ARRAdd (Array* arr, char* data);
char* ARRDel (Array* arr);
char* ARRDelr (Array* arr);
int ARRIns (Array* arr, char* data, int pos);
char*  ARRem (Array* arr, int pos);
int ARRChg(Array* arr, char* data, int pos);
char* ARRGet(Array* arr, int pos);
void print_array (Array* arr);
int ARRSrch(Array* arr, char* data);

#endif