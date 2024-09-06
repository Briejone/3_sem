#include "main.h"

int main(int argc, char* argv[]) {
    Request* req = create_request();
    
    char** strings;
    request_parser(argc, argv, req);
    strings = scan_file(req->file);
    char* string = find_struct(strings, req->name, req->type);
    string = create_string(strings, string, req);
    char** tokens = tok_string(string);
    char* new_string = command_menu(tokens, req);
    strcpy(string, new_string);
    write_strings_to_file(req, strings);
    return 0;
}