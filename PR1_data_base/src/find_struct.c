
#include "find_struct.h"

char* find_struct(char** strings, char* name, char* type) {
    for (int i = 0; strings[i] != NULL; i++) {
        char* temp_str = strdup(strings[i]);
        char* token_type = strtok(temp_str, ":");
        char* token_name = strtok(NULL, ":");
        
        if (token_name != NULL && strcmp(token_name, name) == 0 && strcmp(token_type, type) == 0 && token_type != NULL) {
            free(temp_str);
            return strings[i];
        }

        free(temp_str);
    }
    return NULL;
}

char* create_string(char** tokens, char* string, Request* req) {
    if(string == NULL) {
        string = (char*)malloc(sizeof(char) * STRING_SIZE);
        int  i;
        for(i = 0; tokens[i] != NULL; i++);
            // Удаляем '\n' в конце строки, если он присутствует
    char* end = strchr(tokens[i - 1], '\0');
    if (end != NULL) {
        *end = '\n';
    }
        strcat(string, req->type);
        strcat(string, ":");
        strcat(string, req->name);
        strcat(string, ":");
        strcat(string, " ");
        //printf("%s", string);
        tokens[i] = string;
        //printf("%s", tokens[i]);
        //tokens[i + 1] = NULL;
        
        printf("%s", string);
    }
    return string;
}
// char* new_struct(req) {
//     char * new_string = malloc(sizeof(char) * STRING_SIZE);

// }
