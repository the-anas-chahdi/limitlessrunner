# Compiler
CC = g++

# Compiler flags
CFLAGS = -std=c++14 -Wall

# Source directory
SRC_DIR = src
# Object directory
OBJ_DIR = obj
# Binary directory
BIN_DIR = bin

# Source files
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
# Object files
OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))
# Executable
EXEC = $(BIN_DIR)/LimitlessRunner

# Default rule
all: directories $(EXEC)

# Create necessary directories
directories:
	mkdir -p $(OBJ_DIR) $(BIN_DIR)

# Linking
$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ -lncurses

# Compilation
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Clean
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)
