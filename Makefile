# Compiler
CC = g++

# Compiler flags
CFLAGS = -std=c++14 -Wall

# Source files
SRCS = main.cpp Game.cpp Player.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Executable
EXEC = LimitlessRunner.exe

# Default rule
all: $(EXEC)

# Linking
$(EXEC): $(OBJS)
    $(CC) $(CFLAGS) $^ -o $@ -lncurses

# Compilation
%.o: %.cpp
    $(CC) $(CFLAGS) -c $< -o $@

# Clean
clean:
    rm -f $(EXEC) $(OBJS)
