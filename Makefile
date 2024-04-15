# Compiler
CC = g++

# Compiler flags
CFLAGS = -std=c++14 -Wall -I/opt/homebrew/include -D_THREAD_SAFE -fsanitize=address -g -O1

# SDL2 library path
SDL2_LIB_DIR = /opt/homebrew/lib

# Source directory
SRC_DIR = src
# Object directory
OBJ_DIR = obj
# Binary directory
BIN_DIR = bin
# Documentation directory
DOC_DIR = docs
HTML_DIR = html
LATEX_DIR = latex

# Source files
SRCS_TXT = $(wildcard $(SRC_DIR)/txt/*.cpp) $(wildcard $(SRC_DIR)/core/*.cpp)
SRCS_SDL2 = $(wildcard $(SRC_DIR)/sdl2/*.cpp) $(wildcard $(SRC_DIR)/core/*.cpp)
# Object files
OBJS_TXT = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS_TXT))
OBJS_SDL2 = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS_SDL2))
# Executable
EXEC_TXT = $(BIN_DIR)/LimitlessRunner_txt
EXEC_SDL2 = $(BIN_DIR)/LimitlessRunner_sdl2

# Default rule
all: directories $(EXEC_TXT) $(EXEC_SDL2)

# Create necessary directories
directories:
	mkdir -p $(OBJ_DIR) $(BIN_DIR) $(OBJ_DIR)/core $(OBJ_DIR)/txt $(OBJ_DIR)/sdl2 $(DOC_DIR)

# Linking for txt version
$(EXEC_TXT): $(OBJS_TXT)
	$(CC) $(CFLAGS) $^ -o $@ -lncurses

# Linking for sdl2 version
$(EXEC_SDL2): $(OBJS_SDL2)
	$(CC) $(CFLAGS) -L$(SDL2_LIB_DIR) $^ -o $@ -lSDL2 -lSDL2_image -lSDL2_mixer -lncurses

# Compilation
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Generate Doxygen documentation
documentation:
	doxygen Doxyfile

# Clean
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

# Clean documentation
cleandoc:
	rm -rf $(DOC_DIR) $(HTML_DIR) $(LATEX_DIR) $(LATEX_DIR)
