//
// Created by anasc on 25/03/2024.
//

#include "Player.h"
class Player{
private:
    int posX, posY;
public:
    Player(int x=0, int y=0){
        posX(x);
        posY(y);
    }

    int getX() const {
        return posX;
    }

    int getY() const {
        return posY;
    }

    void setX(int x){
        posX = x;
    }

    void setY(int y){
        posY = y;
    }

    void move(int dx, int dy){
        posX += dx;
        posY += dy;
    }
};