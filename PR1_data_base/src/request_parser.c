#include "request_parser.h"


int request_parser(int argc, char* argv[], Request* req) {
    static struct option long_options[] = {
        {"query", required_argument, 0,  'q' },
        {"file",   required_argument, 0,  'f' },
        {0,        0,                 0,  0   }
    };

    int option_index = 0;
    int option;
    while ((option = getopt_long(argc, argv, "q:f:", long_options, &option_index)) != -1) {
        switch (option) {
            case 'f':
                //printf("%s", optarg);
                req->file = fopen(optarg, "r+"); 
                strcpy(req->name_file, optarg);
                break;
            case 'q':
                query_parser(optarg, req);
                
                break;
            case '?':
                fprintf(stderr, "Unknown option: %d\n", option);
                return 1;
            default:
                break;
        }
    }
    return 0;
}

Request* create_request() {
    Request* req = (Request*)malloc(sizeof(Request));
    req->type = (char*)malloc(sizeof(char) * STRING_SIZE);
    req->name = (char*)malloc(sizeof(char) * STRING_SIZE);
    req->command = (char*)malloc(sizeof(char) * STRING_SIZE);
    req->data = (char*)malloc(sizeof(char) * STRING_SIZE);
    req->name_file = (char*)malloc(sizeof(char) * STRING_SIZE);
    return req;
}

Request* query_parser(char* query, Request* req)  {
    req->command = strtok(query, " ");
    type_parser(req);
    req->name = strtok(NULL, " ");
    if (query != NULL) {
       req->data = strtok(NULL,"");
    }
    return req;
}

Request* type_parser(Request* req) {
    if (strcmp(req->command, "SADD") == 0 || 
        strcmp(req->command, "SREM") == 0 || 
        strcmp(req->command, "SISMEMBER") == 0) {
        strcpy(req->type, "set");
        //printf("%s\n", req->type);
    } else if (strcmp(req->command, "SPUSH") == 0 || 
               strcmp(req->command, "SPOP") == 0) {
        strcpy(req->type, "stack");
        //printf("%s\n", req->type);
    } else if (strcmp(req->command, "QPUSH") == 0 || 
               strcmp(req->command, "QPOP") == 0) {
        strcpy(req->type, "queue");
        //printf("%s\n", req->type);
    } else if (strcmp(req->command, "HSET") == 0 || 
               strcmp(req->command, "HDEL") == 0 || 
               strcmp(req->command, "HGET") == 0) {
        strcpy(req->type, "hash_table");
        //printf("%s\n", req->type);
    } else {
        req->type = NULL;
    }
    return req;
}
