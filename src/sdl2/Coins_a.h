/**
 * @file Coins_a.h
 * @author damiyine loubna - anas chahdi
 * @brief
 * @version 0.1
 * @date 2024-04-15
 *
 * @copyright Copyright (c) 2024
 *
 */
/**

@brief c les piéce que le joueur gagne
*/
#ifndef LIMITLESSRUNNER_COINS_A_H
#define LIMITLESSRUNNER_COINS_A_H

#include <SDL2/SDL.h>
#include "Drawing.h"
#include "Unit.h"

class Coins_a : public Unit {
    friend class RunningPlayer;
    SDL_Rect srcRect, moverRect;

public:
    void draw();
    void move();
    Coins_a();
    ~Coins_a();
};

#endif //LIMITLESSRUNNER_COINS_A_H
