/**
 * @file Explosion.cpp
 * @author damiyine loubna - anas chahdi
 * @brief
 * @version 0.1
 * @date 2024-04-15
 *
 * @copyright Copyright (c) 2024
 *
 */
#include "Explosion.h"
/**

@brief initialise les coordonnées et les dimensions de l'explosion avec des valeurs par défaut
*/
Explosion::Explosion()
{
    moverRect = {980, 500, 70, 70};
    srcRect = {17, 0, 223, 240};
}

Explosion::Explosion(int x, int y)
{
    moverRect = {x, y, 80, 80};
    srcRect = {17, 0, 223, 240};
}

void Explosion::draw()
{
    SDL_RenderCopy(Drawing::gRenderer, Drawing::exp, &srcRect, &moverRect);
}

Explosion ::~Explosion()
{
}