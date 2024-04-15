/**
 * @file Obstacle.cpp
 * @author damiyine loubna - anas chahdi
 * @brief 
 * @version 0.1
 * @date 2024-04-15
 * 
 * @copyright Copyright (c) 2024
 * 
 */

/** @brief Cette classe représente un obstacle dans le jeu elle contient des méthodes pour obtenir et définir les coordonnées de l'obstacle
*/
#include "Obstacle.h"

Obstacle::Obstacle(int x, int y) : posX(x), posY(y) {}

int Obstacle::getX() const {
    return posX;
}

int Obstacle::getY() const {
    return posY;
}

void Obstacle::setX(int x) {
    posX = x;
}

void Obstacle::setY(int y) {
    posY = y;
}
