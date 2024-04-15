/**
 * @file PlayerSDL.h
 * @author damiyine loubna - anas chahdi
 * @brief
 * @version 0.1
 * @date 2024-04-15
 *
 * @copyright Copyright (c) 2024
 *
 */
#ifndef LIMITLESSRUNNER_PLAYERSDL_H
#define LIMITLESSRUNNER_PLAYERSDL_H
#include <SDL2/SDL.h>
#include "Drawing.h"
#include "Unit.h"

class PlayerSDL {
    SDL_Rect srcRect, moverRect;
    friend class RunningPlayer;

public:
    void draw();
    PlayerSDL();
    bool check;
    void moving();
    void jump();
    int i;
    int frame = 0;
    ~PlayerSDL();
};

#endif //LIMITLESSRUNNER_PLAYERSDL_H
