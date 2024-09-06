#ifndef _GETOPT
#define _GETOPT

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>
#include "define.h"



int request_parser(int argc, char* argv[], Request* req);
Request* create_request();
Request* query_parser(char* query, Request* req);
Request* type_parser(Request* req);
#endif