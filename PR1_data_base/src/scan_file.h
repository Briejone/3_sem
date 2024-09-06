#ifndef SCAN_FILE
#define SCAN_FILE

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "define.h"


char** scan_file(FILE* file);
void write_strings_to_file(Request* req, char** strings);
void remove_newline_from_last_string(char** strings);
#endif