# Compiler
CC = g++

# Compiler flags
CFLAGS = -std=c++14 -Wall

# SDL2 library path
SDL2_LIB_DIR = /usr/local/lib

# Source directory
SRC_DIR = src
# Object directory
OBJ_DIR = obj
# Binary directory
BIN_DIR = bin

# Source files
SRCS_TXT = $(wildcard $(SRC_DIR)/txt/*.cpp)
SRCS_SDL2 = $(wildcard $(SRC_DIR)/sdl2/*.cpp)
SRCS_CORE = $(wildcard $(SRC_DIR)/core/*.cpp)
# Object files
OBJS_TXT = $(patsubst $(SRC_DIR)/txt/%.cpp,$(OBJ_DIR)/txt/%.o,$(SRCS_TXT))
OBJS_SDL2 = $(patsubst $(SRC_DIR)/sdl2/%.cpp,$(OBJ_DIR)/sdl2/%.o,$(SRCS_SDL2))
OBJS_CORE = $(patsubst $(SRC_DIR)/core/%.cpp,$(OBJ_DIR)/core/%.o,$(SRCS_CORE))
# Executable
EXEC_TXT = $(BIN_DIR)/LimitlessRunner_txt
EXEC_SDL2 = $(BIN_DIR)/LimitlessRunner_sdl2

# Default rule
all: directories $(EXEC_TXT) $(EXEC_SDL2)

# Create necessary directories
directories:
	mkdir -p $(OBJ_DIR) $(BIN_DIR) $(OBJ_DIR)/core $(OBJ_DIR)/txt $(OBJ_DIR)/sdl2

# Linking for txt version
$(EXEC_TXT): $(OBJS_TXT) $(OBJS_CORE)
	$(CC) $(CFLAGS) $^ -o $@ -lncurses

# Linking for sdl2 version
$(EXEC_SDL2): $(OBJS_SDL2) $(OBJS_CORE)
	$(CC) $(CFLAGS) -L$(SDL2_LIB_DIR) $^ -o $@ -lSDL2 -lSDL2_image -lncurses

# Compilation for txt files
$(OBJ_DIR)/txt/%.o: $(SRC_DIR)/txt/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Compilation for sdl2 files
$(OBJ_DIR)/sdl2/%.o: $(SRC_DIR)/sdl2/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Compilation for core files
$(OBJ_DIR)/core/%.o: $(SRC_DIR)/core/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Clean
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)
