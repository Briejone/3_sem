#include "scan_file.h"

char** scan_file(FILE* file) {
    char** strings = (char**)calloc(BD_SIZE, sizeof(char*));
    for (int i = 0; i < BD_SIZE; i++) {
        strings[i] = (char*)malloc(sizeof(char) * STRING_SIZE);
    }
    int i = 0;
    while (fgets(strings[i++], STRING_SIZE, file) != NULL);
    strings[i - 1] = NULL;
    
    return strings;
}

void write_strings_to_file(Request* req, char** strings) {
    fclose(req->file);
    FILE* file = fopen(req->name_file, "w");

    // Удаляем '\n' только в последней строке
    remove_newline_from_last_string(strings);

    int i = 0;
    while (strings[i] != NULL) {
        fprintf(file, "%s", strings[i]);
        i++;
    }

    fclose(file);
}

void remove_newline_from_last_string(char** strings) {
    int i = 0;
    
    // Находим последнюю строку
    while (strings[i] != NULL) {
        i++;
    }
    
    if (i > 0) { // Проверка, что массив содержит хотя бы одну строку
        int len_last = strlen(strings[i - 1]);
        
        // Убираем '\n', если он есть в конце последней строки
        if (len_last > 0 && strings[i - 1][len_last - 1] == '\n') {
            strings[i - 1][len_last - 1] = '\0';
        }
    }
}