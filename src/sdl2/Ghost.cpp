/**
 * @file Ghost.cpp
 * @author damiyine loubna - anas chahdi
 * @brief
 * @version 0.1
 * @date 2024-04-15
 *
 * @copyright Copyright (c) 2024
 *
 */
#include "Ghost.h"
/** @brief draw pour dessiner le fantôme sur l'écran on utilise le rendu SDL pour copier la texture du fantôme sur la surface de rendu
*/

Ghost::Ghost()
{
    moverRect = {980, 500, 50, 50};
    srcRect = {67, 12, 119, 240};
}

void Ghost::draw()
{
    SDL_RenderCopy(Drawing::gRenderer, Drawing::Ghost, &srcRect, &moverRect);
    if (frame == 0)
    {
        srcRect = {110, 53, 722, 1142};
    }
    else if (frame == 1)
    {
        srcRect = {1069, 38, 546, 1161};
    }
    else if (frame == 2)
    {
        srcRect = {1982, 52, 721, 1143};
    }
    frame++;
    if (frame == 3)
    {
        frame = 0;
    }
}

void Ghost::move()
{
    moverRect.x -= 15;
}

Ghost ::~Ghost()
{
}