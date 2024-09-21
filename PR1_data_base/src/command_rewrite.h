#ifndef COMMAND_REWRITE
#define COMMAND_REWRITE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../struct/Struct.h"
#include "define.h"

char* command_menu(char** tokens, Request* req);
HashSet* string_to_set(char** tokens);
Stack* string_to_stack(char** tokens);
Queue* string_to_queue(char** tokens);
HashTable* string_to_ht(char** tokens);
char** tok_string(char* string);
char** tokenize_string(const char* string);
HashSet* query_to_set(HashSet* set, Request* req);
Queue* query_to_queue(Queue* queue, Request* req);
Stack* query_to_stack(Stack* stack, Request* req);
HashTable* query_to_ht(HashTable* ht, Request* req);
char* set_to_string(HashSet* set, char* string, Request* req);
char* stack_to_string(Stack* st,char* string,  Request* req);
char* queue_to_string(Queue* queue, char* string,  Request* req);
char* ht_to_string(HashTable* ht, char* string,  Request* req);
#endif