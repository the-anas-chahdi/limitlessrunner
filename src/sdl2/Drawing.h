/**
 * @file Drawing.h
 * @author damiyine loubna - anas chahdi
 * @brief
 * @version 0.1
 * @date 2024-04-15
 *
 * @copyright Copyright (c) 2024
 *
 */
/** * @brief Elle contient des membres statiques pour le rendu SDL et différentes textures utilisées dans le jeu.
*/
#ifndef LIMITLESSRUNNER_DRAWING_H
#define LIMITLESSRUNNER_DRAWING_H

#include <SDL2/SDL.h>

class Drawing
{
public:
    static SDL_Renderer *gRenderer;
    static SDL_Texture *assets;
    static SDL_Texture *tt;
    static SDL_Texture *life;
    static SDL_Texture *Ghost;
    static SDL_Texture *Meteor;
    static SDL_Texture *exp;
};

#endif // LIMITLESSRUNNER_DRAWING_H
