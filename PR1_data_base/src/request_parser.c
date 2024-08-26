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
                break;
            case 'q':
                strcpy(req->query, optarg);
                //fprintf(stdout, "query - %s\n", optarg);
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
    req->query = (char*)malloc(sizeof(char) * QUERY_SIZE);
    return req;
}