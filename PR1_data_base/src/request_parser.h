#ifndef _GETOPT
#define _GETOPT

#include <stdio.h>
#include <getopt.h>
#include <string.h>
#include "define.h"
typedef struct Request{
    FILE* file;
    char* query;
} Request;

int request_parser(int argc, char* argv[], Request* req);
Request* create_request();

#endif