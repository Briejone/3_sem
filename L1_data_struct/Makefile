# Makefile

# Compiler and flags
CC = g++
CFLAGS = -Wall -Wextra
LDFLAGS = -lgtest -lgtest_main -pthread

# Directories
SRC_DIR = .
BUILD_DIR = build
BIN_DIR = bin

# Source files
SRC_CPP_FILES = $(wildcard $(SRC_DIR)/*.cpp)
SRC_C_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_CPP_FILES = $(SRC_CPP_FILES:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)
OBJ_C_FILES = $(SRC_C_FILES:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
OBJ_FILES = $(OBJ_CPP_FILES) $(OBJ_C_FILES)
TARGET = $(BIN_DIR)/test

# Rules
all: $(TARGET)

$(TARGET): $(OBJ_FILES)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $(OBJ_FILES) $(LDFLAGS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c -o $@ $<

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)

.PHONY: all clean
