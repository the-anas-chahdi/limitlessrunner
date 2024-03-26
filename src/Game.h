//
// Created by anasc on 25/03/2024.
//

#ifndef LIMITLESSRUNNER_GAME_H
#define LIMITLESSRUNNER_GAME_H

#include "Player.h"
#include "C:/msys64/mingw64/include/ncurses/ncurses.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

class Game {
private:
    bool isRunning;
    Player player;
    int maxObstacles;
    int* obstacles;

public:
    Game();
    ~Game();
    void run();
    void handleInput();
    void update();
    void render();
};

#endif //LIMITLESSRUNNER_GAME_H