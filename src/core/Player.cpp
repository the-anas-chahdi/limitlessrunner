
/**
 * @file Player.cpp
 * @author damiyine loubna - anas chahdi
 * @brief
 * @version 0.1
 * @date 2024-04-15
 *
 * @copyright Copyright (c) 2024
 *
 */
#include "Player.h"
/** @brief définir les coordonnées du joueur et obtenir  le nombre de vies du joueur et pour réduire le nombre de vies du joueur.
*/
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