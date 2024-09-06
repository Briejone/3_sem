# Makefile

# Compiler and flags
CC = g++
CFLAGS = -Wall -Wextra

# Directories
BUILD_DIR = build

# Source files
SRC_FILES = src/main.c src/request_parser.c src/scan_file.c src/find_struct.c src/command_rewrite.c
STRUCT_FILES = struct/Array.c struct/Hash_table.c struct/Queue.c struct/Stack.c
all: bd 

bd:
	$(CC) $(SRC_FILES) $(STRUCT_FILES) -o bd.exe $(CFLAGS)

debug:
	$(CC) $(SRC_FILES) $(STRUCT_FILES) -g -o bd_test.exe $(CFLAGS)