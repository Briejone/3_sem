#include "main.h"

int main(int argc, char* argv[]) {
    Request* req = create_request();
    
    char** strings;
    request_parser(argc, argv, req);
    strings = scan_file(req->file);

    return 0;
}