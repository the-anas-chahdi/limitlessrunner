//
// Created by anasc on 25/03/2024.
//

#ifndef LIMITLESSRUNNER_PLAYER_H
#define LIMITLESSRUNNER_PLAYER_H
#include <ncurses.h>

class Player {
private:
    int posX, posY;

public:
    Player(int x = 2, int y = LINES - 2);
    int getX() const;
    int getY() const;
    void setX(int x);
    void setY(int y);
    void move(int dx, int dy);
};

#endif //LIMITLESSRUNNER_PLAYER_H