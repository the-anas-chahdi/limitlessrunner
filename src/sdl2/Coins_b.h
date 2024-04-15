/**
 * @file Coins_b.h
 * @author damiyine loubna - anas chahdi
 * @brief
 * @version 0.1
 * @date 2024-04-15
 *
 * @copyright Copyright (c) 2024
 *
 */
/**

@brief c les piéce que le joueur incrémente
*/
#ifndef LIMITLESSRUNNER_COINS_B_H
#define LIMITLESSRUNNER_COINS_B_H
#include <SDL2/SDL.h>
#include "Drawing.h"
#include "Unit.h"

class Coins_b{
    friend class RunningMan;
    SDL_Rect srcRect, moverRect;

public:
    int counts = 0;
    void draw();
    void operator++();
    Coins_b();
    ~Coins_b();
};



#endif //LIMITLESSRUNNER_COINS_B_H
