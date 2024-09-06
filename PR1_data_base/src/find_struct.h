#ifndef FIND_STRUCT
#define FIND_STRUCT
#include <stdio.h>
#include <stdlib.h>
#include "request_parser.h"
#include "define.h"

char* find_struct(char** strings, char* name, char* type);
char* create_string(char** tokens, char* string, Request* req);

#endif