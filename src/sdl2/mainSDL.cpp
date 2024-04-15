/**
 * @file mainSDL.cpp
 * @author damiyine loubna - anas chahdi
 * @brief
 * @version 0.1
 * @date 2024-04-15
 *
 * @copyright Copyright (c) 2024
 *
 */
#include "GameSDL.h"

int main()
{
    GameSDL game;
    srand(time(NULL));
    if (!game.init())
    {
        printf("Failed to initialize!\n");
        return 0;
    }

    if (!game.loadMedia())
    {
        printf("Failed to load media!\n");
        return 0;
    }

    game.run();
    game.close();

    return 0;
}
