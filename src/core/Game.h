/**
 * @file Game.h
 * @author damiyine loubna - anas chahdi
 * @brief 
 * @version 0.1
 * @date 2024-04-15
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef LIMITLESSRUNNER_GAME_H
#define LIMITLESSRUNNER_GAME_H
#include "Obstacle.h"
#include "Player.h"
#include <ncurses.h>
#include <iostream>
#include <cstdlib>
#include <ctime>

class Game {
private:
    bool isRunning;
    Player player;
    int maxObstacles;
    Obstacle* obstacles;
    bool isJumping;
    int jumpVelocity;
    int gravity;
    int score;
    bool canDoubleJump;

public:
    Game();
    ~Game();
    void run();
    void handleInput();
    void update();
    void render();
    void checkCollisions();
};

#endif //LIMITLESSRUNNER_GAME_H