//
// Created by anas on 13/04/24.
//

#include "PlayerSDL.h"

PlayerSDL::PlayerSDL(int x, int y, int startingLives) {
    posX = x;
    posY = y;
    lives = startingLives;
}

int PlayerSDL::getX() const {
    return posX;
}

int PlayerSDL::getY() const {
    return posY;
}

void PlayerSDL::setX(int x) {
    posX = x;
}

void PlayerSDL::setY(int y) {
    posY = y;
}

int PlayerSDL::getLives() const {
    return lives;
}

void PlayerSDL::setLives(int newLives) {
    lives = newLives;
}

void PlayerSDL::loseLife() {
    lives--;
}
