/**
 * @file Coins_a.cpp
 * @author damiyine loubna - anas chahdi
 * @brief
 * @version 0.1
 * @date 2024-04-15
 *
 * @copyright Copyright (c) 2024
 *
 */
/** @brief représente un type spécifique de pièces dans le jeu elle contient des méthodes pour dessiner la pièce et la faire bouger sur l'écran.
*/
#include "Coins_a.h"

Coins_a::Coins_a()
{
    moverRect = {980, 500, 50, 50};
    srcRect = {0, 0, 30, 50};
}

void Coins_a::draw()
{
    SDL_RenderCopy(Drawing::gRenderer, Drawing::tt, &srcRect, &moverRect);
}

void Coins_a::move()
{
    moverRect.x -= 20;
}

Coins_a ::~Coins_a()
{
}