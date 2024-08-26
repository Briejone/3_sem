#include "scan_file.h"

char** scan_file(FILE* file) {
    char** strings = (char**)calloc(BD_SIZE, sizeof(char*));
    for (int i = 0; i < BD_SIZE; i++) {
        strings[i] = (char*)malloc(sizeof(char) * STRING_SIZE);
    }
    int i = 0;
    while (fgets(strings[i++], STRING_SIZE, file) != NULL);
    
    return strings;
}