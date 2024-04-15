/**
 * @file Coins_b.cpp
 * @author damiyine loubna - anas chahdi
 * @brief
 * @version 0.1
 * @date 2024-04-15
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "Coins_b.h"

Coins_b::Coins_b()
{
    moverRect = {20, 130, 50, 50};
    srcRect = {0, 0, 30, 50};
}

void Coins_b::operator++()
{
    counts++;
}

void Coins_b::draw()
{
    moverRect = {20, 130, 50, 50};
    for (int i = 0; i < counts; i++)
    {
        SDL_RenderCopy(Drawing::gRenderer, Drawing::tt, &srcRect, &moverRect);
        moverRect.x += 40;
    }
}

Coins_b ::~Coins_b()
{
}