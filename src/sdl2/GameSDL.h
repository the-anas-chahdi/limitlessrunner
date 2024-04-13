//
// Created by anas on 13/04/24.
//

#ifndef LIMITLESSRUNNER_GAMESDL_H
#define LIMITLESSRUNNER_GAMESDL_H

#include "PlayerSDL.h"
#include <SDL2/SDL.h>
#include <string>

class GameSDL {
private:
    bool isRunning;
    SDL_Window* window;
    SDL_Renderer* renderer;
    PlayerSDL player;
    int maxObstacles;
    int* obstacles;
    bool isJumping;
    int jumpVelocity;
    int gravity;
    SDL_Texture* backgroundTexture;
    SDL_Texture* playerTexture;
    SDL_Texture* obstacleTexture;

    SDL_Texture* loadTexture(const std::string& filePath);
    void update();
    void render();
    void checkCollisions();

public:
    GameSDL();
    ~GameSDL();
    void run();
};


#endif //LIMITLESSRUNNER_GAMESDL_H
