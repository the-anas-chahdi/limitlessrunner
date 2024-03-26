cmake_minimum_required(VERSION 3.20)
project(LimitlessRunner)

set(CMAKE_CXX_STANDARD 14)

# Add the executable
add_executable(LimitlessRunner main.cpp Game.cpp Player.cpp)

# Link ncurses library
target_link_libraries(LimitlessRunner ncurses)