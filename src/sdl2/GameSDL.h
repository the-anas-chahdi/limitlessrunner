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
#ifndef LIMITLESSRUNNER_GAMESDL_H
#define LIMITLESSRUNNER_GAMESDL_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <SDL2/SDL_mixer.h>

/**  @brief La classe GameSDL gère l'initialisation et l'exécution du jeu
 */

class GameSDL {
    SDL_Window *gWindow = NULL;

    SDL_Texture *gTexture = NULL;

    Mix_Music *music = NULL;
    int playerLives;

public:
    bool init();
    bool loadMedia();
    bool loadIns();
    bool loadWIN();
    bool loadLOST();
    bool loadGrid();

    void close();
    SDL_Texture *loadTexture(std::string path);
    void run();
    int state = 0;
};

#endif //LIMITLESSRUNNER_GAMESDL_H
