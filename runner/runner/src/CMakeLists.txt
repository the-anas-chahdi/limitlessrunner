cmake_minimum_required(VERSION 3.10)
project(RunnerGame)

set(CMAKE_CXX_STANDARD 14)
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

set(SOURCES
        src/core/Game.cpp
        src/core/Runner.cpp
        src/core/Zombie.cpp
        src/core/Coin.cpp
        src/sdl2/SDLGame.cpp
        src/sdl2/SDLTextures.cpp
        src/main.cpp
)
add_executable(RunnerGame ${SOURCES})
target_link_libraries(RunnerGame ${SDL2_LIBRARIES})


