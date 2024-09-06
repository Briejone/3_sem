#ifndef DEF
#define DEF

#include <stdio.h>
#define STRING_SIZE 1024
#define BD_SIZE 1024
#define QUERY_SIZE 1024
#define STRUCT_SIZE 1024
#define MAX_TOKENS 256

typedef struct Request{
    FILE* file;
    char* command;
    char* type;
    char* name;
    char* data;
    char* name_file;
} Request;

#endif