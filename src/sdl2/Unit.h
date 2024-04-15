
/**
 * @file Unit.h
 * @author damiyine loubna - anas chahdi
 * @brief
 * @version 0.1
 * @date 2024-04-15
 *
 * @copyright Copyright (c) 2024
 *
 */
#ifndef LIMITLESSRUNNER_UNIT_H
#define LIMITLESSRUNNER_UNIT_H
#include <SDL2/SDL.h>
#include "Drawing.h"
#include "PlayerSDL.h"
#include <iostream>

using namespace std;

class Unit{

protected:
    SDL_Rect srcRect, moverRect;

public:
    virtual void draw() = 0;
    virtual void move() = 0;
    friend class RunningPlayer;
    virtual ~Unit();
};



#endif //LIMITLESSRUNNER_UNIT_H
