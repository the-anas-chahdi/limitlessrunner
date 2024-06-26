/**
 * @file Player.h
 * @author damiyine loubna - anas chahdi
 * @brief
 * @version 0.1
 * @date 2024-04-15
 *
 * @copyright Copyright (c) 2024
 *
 */
#ifndef LIMITLESSRUNNER_PLAYER_H
#define LIMITLESSRUNNER_PLAYER_H
#include <ncurses.h>

class Player {
private:
    int posX, posY;
    int lives;

public:
    Player(int x = 2, int y = LINES - 2, int startingLives = 3);
    int getX() const;
    int getY() const;
    void setX(int x);
    void setY(int y);
    int getLives() const;
    void setLives(int newLives);
    void loseLife();
};

#endif //LIMITLESSRUNNER_PLAYER_H