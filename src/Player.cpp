//
// Created by anasc on 25/03/2024.
//

#include "Player.h"

Player::Player(int x, int y){
    posX = x;
    posY = y;
}

int Player::getX() const {
    return posX;
}

int Player::getY() const {
    return posY;
}

void Player::setX(int x){
    posX = x;
}

void Player::setY(int y){
    posY = y;
}

void Player::move(int dx, int dy){
    posX += dx;
    posY += dy;
}