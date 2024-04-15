/**
 * @file Lives.h
 * @author damiyine loubna - anas chahdi
 * @brief
 * @version 0.1
 * @date 2024-04-15
 *
 * @copyright Copyright (c) 2024
 *
 */
#ifndef LIMITLESSRUNNER_LIVES_H
#define LIMITLESSRUNNER_LIVES_H
#include<SDL2/SDL.h>
#include "Drawing.h"
#include "Unit.h"

class Lives {
    SDL_Rect srcRect, moverRect;
    friend class RunningMan;
public:
    void draw();
    Lives();
    void operator--();
    int l_left = 3;
    ~Lives();
};


#endif //LIMITLESSRUNNER_LIVES_H
