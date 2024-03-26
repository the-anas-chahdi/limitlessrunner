//
// Created by anasc on 25/03/2024.
//

#include "Player.h"
class Player{
private:
    int posX, posY;
public:
    Player(){
        posX=0;
        posY=0;
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
};