#include "command_rewrite.h"

char* command_menu(char** tokens, Request* req) {
    char* string = (char*)malloc(sizeof(char) * STRING_SIZE);
    if(strcmp(req->type, "set") == 0 ) {
        HashSet* set = string_to_set(tokens);
        query_to_set(set, req);
        set_to_string(set, string, req);
    } else if(strcmp(req->type, "stack") == 0 ) {
        Stack* st = string_to_stack(tokens);
        query_to_stack(st, req);
        stack_to_string(st, string, req);
    } else if(strcmp(req->type, "queue")  == 0) {
        Queue* queue = string_to_queue(tokens);
        query_to_queue(queue, req);
        queue_to_string(queue, string, req);
    }else if(strcmp(req->type, "hash_table") == 0 ) {
        HashTable* ht = string_to_ht(tokens);
        query_to_ht(ht, req);
        //query_to_ht(ht, req);
        ht_to_string(ht, string, req);
    }
    return string;
}

char* set_to_string(HashSet* set, char* string, Request* req) {
    strcat(string, req->type);
    strcat(string, ":");
    strcat(string, req->name);
    strcat(string, ":");
    strcat(string, " ");
    for (int i = 0; i < set->size; i++) {
        if(set->table[i] == NULL) {
            continue;
        }
        Node_set* current = set->table[i];
        while(current != NULL) {
            strcat(string, current->data);
            strcat(string, " ");
            current = current->next;
        }
    }
    strcat(string, "\n");
    return string;
}
// char* array_to_string(Array* arr, char* string, Request* req) {
//     int size = arr->size;
//     if(size == 0) {
//         fprintf(stdout,"array %s deleted", req->name);
//         strcpy(string, "\0");
//         return string;
//     }
//     strcat(string, req->type);
//     strcat(string, ":");
//     strcat(string, req->name);
//     strcat(string, ":");
//     strcat(string, " ");
//     for (int i = 0; i < size - 1; i++) {
//         strcat(string, ARRDelr(arr));
//         strcat(string, " ");
//     }
//     strcat(string, ARRDelr(arr));
//     strcat(string, "\n");
// //    printf("%s", string);
//     return string;
// }

char* queue_to_string(Queue* queue, char* string,  Request* req) {
    int size = queue->size;
    if(size == 0) {
        fprintf(stdout,"queue %s deleted", req->name);
        strcpy(string, "\0");
        return string;
    }
    strcat(string, req->type);
    strcat(string, ":");
    strcat(string, req->name);
    strcat(string, ":");
    strcat(string, " ");
    for (int i = 0; i < size - 1; i++) {
        strcat(string, QPop(queue));
        strcat(string, " ");
    }

    strcat(string, QPop(queue));
    strcat(string, "\n");
    return string;
}
char* stack_to_string(Stack* st,char* string,  Request* req) {
    int size = st->size;
    if(size == 0) {
        fprintf(stdout,"stack %s deleted\n", req->name);
        strcpy(string, "\0");
        return string;
    }
    Stack* st_tmp = createStack();
    for(int i = 0; i < size; i++) {
        SPush(st_tmp, SPop(st));
    }
    strcat(string, req->type);
    strcat(string, ":");
    strcat(string, req->name);
    strcat(string, ":");
    strcat(string, " ");
    for (int i = 0; i < size - 1; i++) {
        strcat(string, SPop(st_tmp));
        strcat(string, " ");
    }
    strcat(string, SPop(st_tmp));
    strcat(string, "\n");
    return string;
}
char* ht_to_string(HashTable* ht, char* string, Request* req) {
    strcat(string, req->type);
    strcat(string, ":");
    strcat(string, req->name);
    strcat(string, ":");
    strcat(string, " ");
    for (int i = 0; i < ht->size; i++) {
        if(ht->table[i] == NULL) {
            continue;
        }
        Node_hash* current = ht->table[i];
        while(current != NULL) {
            strcat(string, current->key);
            strcat(string, " ");
            strcat(string, current->data);
            strcat(string, " ");
            current = current->next;
        }
    }
    strcat(string, "\n");
    return string;
} 

// Array* query_to_array(Array* arr, Request* req) {
//     if(strcmp(req->command, "SADD") == 0) {
//         char** tokens = tokenize_string(req->data);
//         for(int i = 0; tokens[i] != 0; i++) {
//             ARRAdd(arr, tokens[i]);
//         }

//         return arr;
//     } else if(strcmp(req->command, "SREM") == 0) {
//         char* del_string = ARRDel(arr);
//         fprintf(stdout, "%s\n", del_string);
    // } else if(strcmp(req->command, "SISMEMBER") == 0) {
    //     char* token = req->data;
    //     int size = arr->size;
    //     int flag = 0;
    //     for (int i = 0; i < size; i++) {
    //         if(strcmp(arr->data[i], token) == 0) {
    //             flag = 1;
    //         }
//         }
//         if (flag == 1) {
//             fprintf(stdout, "TRUE\n");
//         } if (flag == 0) {
//             fprintf(stdout, "FALSE\n");
//         }
//     }
//     return arr;
// }
// (strcmp(req->command, "SPUSH") == 0 || 
//  strcmp(req->command, "SPOP") == 0) 
HashSet* query_to_set(HashSet* set, Request* req) {
    if(strcmp(req->command, "SADD") == 0) {
        char** tokens = tokenize_string(req->data);
        for(int i = 0; tokens[i] != 0; i++) {
            HSetAdd(set, tokens[i]);
        }
        return set;
    } else if(strcmp(req->command, "SREM") == 0) {
        char* del_string = HSetRemove(set, req->data);
        fprintf(stdout, "%s\n", del_string);
    } else if(strcmp(req->command, "SISMEMBER") == 0) {
        int flag = HSetContains(set, req->data);
        if (flag == 1) {
            fprintf(stdout, "TRUE\n");
        } else {
            fprintf(stdout, "FALSE\n");
        }
    }
    return set;
}
Queue* query_to_queue(Queue* queue, Request* req) {
    if(strcmp(req->command, "QPUSH") == 0) {
        char** tokens = tokenize_string(req->data);
        for(int i = 0; tokens[i] != 0; i++) {
            QPush(queue, tokens[i]);
        }
        return queue;
    } else if(strcmp(req->command, "QPOP") == 0) {
        char* del_string = QPop(queue);
        fprintf(stdout, "%s", del_string);
    }
    return queue;
}
Stack* query_to_stack(Stack* stack, Request* req) {
    if(strcmp(req->command, "SPUSH") == 0) {
        char** tokens = tokenize_string(req->data);
        for(int i = 0; tokens[i] != 0; i++) {
            SPush(stack, tokens[i]);
        }
        return stack;
    } else if(strcmp(req->command, "SPOP") == 0) {
        char* del_string = SPop(stack);
        fprintf(stdout, "%s\n", del_string);
    }
    return stack;
}
HashTable* query_to_ht(HashTable* ht, Request* req) {
    if(strcmp(req->command, "HSET") == 0) {
        char** tokens = tokenize_string(req->data);
        for(int i = 0; tokens[i] != 0; i += 2) {
            HSet(ht, tokens[i], tokens[i + 1]);
        }
        return ht;
    } else if (strcmp(req->command, "HDEL") == 0) {
        char* del_string = HDel(ht, req->data);
        fprintf(stdout, "%s\n", del_string);
    } else if (strcmp(req->command, "HGET") == 0) {
        fprintf(stdout, "%s\n", HGet(ht, req->data));
    }
    return ht;
}


// Array* string_to_array(char** tokens) {
//     Array* arr = create_array(MAX_TOKENS);
//     for(int i = 0; tokens[i] != NULL; i++) {
//         ARRAdd(arr, tokens[i]);
//         //printf("%s", tokens[i]);
//     }
//     return arr;
// }
HashSet* string_to_set(char** tokens) {
    HashSet* hs = createHashSet(STRUCT_SIZE);
    for (int i = 0; tokens[i] != NULL; i++) {
        HSetAdd(hs, tokens[i]);
    }
    return hs;
}

Stack* string_to_stack(char** tokens) {
    Stack* stack = createStack();
    for(int i = 0; tokens[i] != NULL; i++) {
        SPush(stack, tokens[i]);
    }
    return stack;
}

Queue* string_to_queue(char** tokens) {
    Queue* queue = createQueue();
    
    for(int i = 0; tokens[i] != NULL; i++) {
        QPush(queue, tokens[i]);
    }
    return queue;
}

HashTable* string_to_ht(char** tokens) {
    HashTable* ht = createHashTable(STRUCT_SIZE);
    for (int i = 0; tokens[i] != NULL; i += 2) {
        HSet(ht, tokens[i], tokens[i + 1]);
    }
    return ht;
}

/*  Множество SADD SREM SISMEMBER
    Стек SPUSH SPOP SPOP
    Очередь QPUSH QPOP QPOP
    Хеш-таблица HSET HDEL HGET*/

char** tokenize_string(const char* string) {
    char* str_copy = strdup(string);
    if (str_copy == NULL) {
        return NULL;
    }


    const char* delimiters = " ";


    int token_count = 0;
    char* token = strtok(str_copy, delimiters);
    while (token != NULL) {
        token_count++;
        token = strtok(NULL, delimiters);
    }


    char** tokens = (char**)malloc((token_count + 1) * sizeof(char*));
    if (tokens == NULL) {
        free(str_copy);
        return NULL;
    }


    strcpy(str_copy, string);
    token = strtok(str_copy, delimiters);
    int i = 0;
    while (token != NULL) {
        tokens[i] = strdup(token);
        if (tokens[i] == NULL) {
            for (int j = 0; j < i; j++) {
                free(tokens[j]);
            }
            free(tokens);
            free(str_copy);
            return NULL;
        }
        i++;
        token = strtok(NULL, delimiters);
    }
    tokens[i] = NULL;

    free(str_copy);
    return tokens;
}

char** tok_string(char* string) {
    // Очищаем указатель на строки
    char** tokens = (char**) malloc(MAX_TOKENS * sizeof(char*));
    int token_count = 0;
    //printf("kryto");
    // Удаляем префикс "stack:2: " из строки
    char* start = strchr(string, ' ') + 1;
    //printf("%s", start);
    if (start == NULL) {
        return NULL;
    }

    // Удаляем '\n' в конце строки, если он присутствует
    char* end = strchr(start, 13);
    if (end != NULL) {
        *end = '\0';
        //printf("end = %s\n", end);
    }
    end = strchr(start, '\n');
    if (end != NULL) {
        *end = '\0';
        //printf("end = %s\n", end);
    }
    // Разбиваем строку на токены
    char* token = strtok(start, " ");
    //printf("%s", token);
    while (token != NULL && token_count < MAX_TOKENS) {
        //printf("%d|%s\n", token_count, token);
        tokens[token_count] = (char*)malloc(strlen(token) + 1);
        strcpy(tokens[token_count], token);
        token_count++;
        token = strtok(NULL, " ");
    }
    tokens[token_count] = NULL; // Завершающий NULL для списка токенов

    return tokens;
}