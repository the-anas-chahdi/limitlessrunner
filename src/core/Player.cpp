//
// Created by anasc on 25/03/2024.
//

#include "Player.h"

Player::Player(int x, int y, int startingLives){
    posX = x;
    posY = y;
    lives = startingLives;
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

int Player::getLives() const{
    return lives;
}

void Player::setLives(int newLives){
    lives = newLives;
}

void Player::loseLife() {
    lives--;
}