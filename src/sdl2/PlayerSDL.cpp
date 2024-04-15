/**
 * @file PlayerSDL.cpp
 * @author damiyine loubna - anas chahdi
 * @brief
 * @version 0.1
 * @date 2024-04-15
 *
 * @copyright Copyright (c) 2024
 *
 */
#include "PlayerSDL.h"

PlayerSDL::PlayerSDL()
{

    srcRect = {63, 619, 151, 166};
    i = 0;

    moverRect = {30, 500, 50, 50};
}

void PlayerSDL::draw()
{
    SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect, &moverRect);
}

void PlayerSDL::jump()
{
    if (frame == 0)
    {
        srcRect = {0, 218, 85, 154};
    }
    else if (frame == 1)
    {
        srcRect = {103, 190, 86, 154};
    }
    else if (frame == 2)
    {
        srcRect = {210, 159, 86, 154};
    }
    else if (frame == 3)
    {
        srcRect = {300, 178, 88, 149};
    }
    else if (frame == 4)
    {
        srcRect = {391, 215, 88, 150};
    }

    frame++;
    if (moverRect.x >= 950)
    {
        moverRect.x = 950;
    }

    moverRect.x += 20;

    if (frame < 3)
    {
        moverRect.y -= 90;
    }
    else
    {
        moverRect.y += 60;
    }
    if (frame == 5)
    {
        frame = 0;
        check = false;
    }
}

void PlayerSDL::moving()
{

    if (i == 0)
    {
        srcRect = {207, 2, 95, 141};
    }
    else if (i == 1)
    {
        srcRect = {326, 2, 80, 141};
    }
    else if (i == 2)
    {
        srcRect = {434, 0, 72, 143};
    }
    else if (i == 3)
    {
        srcRect = {535, 2, 86, 141};
    }
    else if (i == 4)
    {
        srcRect = {0, 6, 66, 137};
    }
    else if (i == 5)
    {
        srcRect = {95, 0, 84, 143};
    }
    i++;

    if (i == 6)
    {
        i = 0;
    }
}

PlayerSDL ::~PlayerSDL()
{
}