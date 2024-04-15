/**
 * @file Explosion.h
 * @author damiyine loubna - anas chahdi
 * @brief
 * @version 0.1
 * @date 2024-04-15
 *
 * @copyright Copyright (c) 2024
 *
 */
#ifndef LIMITLESSRUNNER_EXPLOSION_H
#define LIMITLESSRUNNER_EXPLOSION_H
#include <SDL2/SDL.h>
#include "Drawing.h"


/** @brief elle contient des méthodes pour dessiner l'explosion à l'écran.
*/
class Explosion{
    friend class RunningMan;
    SDL_Rect srcRect, moverRect;

public:
    void draw();
    Explosion();
    Explosion(int, int);
    ~Explosion();
    int value = 0;
};



#endif //LIMITLESSRUNNER_EXPLOSION_H
