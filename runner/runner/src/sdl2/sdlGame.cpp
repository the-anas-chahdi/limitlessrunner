#include "sdlGame.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

SDLGame::SDLGame() : window(nullptr), renderer(nullptr), textureRunner(nullptr), textureZombie(nullptr), textureCoin(nullptr) {}

SDLGame::~SDLGame() {
    SDL_DestroyTexture(textureRunner);
    SDL_DestroyTexture(textureZombie);
    SDL_DestroyTexture(textureCoin);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_DestroyTexture(textureGameOver);
    SDL_DestroyTexture(textureBackground);
    IMG_Quit();
    SDL_Quit();
}
bool SDLGame::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "Erreur initialisation de SDL : " << SDL_GetError() << std::endl;
        return false;
    }

    Uint32 flags = fullscreen ? SDL_WINDOW_FULLSCREEN : 0;
    window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
    if (!window) {
        std::cerr << "Erreur création de la fenêtre : " << SDL_GetError() << std::endl;
        return false;
    }
    renderer = SDL_CreateRenderer(window, -1, 0);
    if (!renderer) {
        std::cerr << "Erreur création du renderer : " << SDL_GetError() << std::endl;
        return false;
    }

    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
        std::cerr << "Erreur initialisation de SDL image : " << IMG_GetError() << std::endl;
        return false;
    }
    textureRunner = loadTexture("runner.png");
    if (!textureRunner) {
        std::cerr << "Erreur chargement du runner : " << SDL_GetError() << std::endl;
        return false;
    }
    textureZombie = loadTexture("zombie.png");
    if (!textureZombie) {
        std::cerr << "Erreur chargement de texture du zombie : " << SDL_GetError() << std::endl;
        return false;
    }
    textureCoin = loadTexture("coin.png");
    if (!textureCoin) {
        std::cerr << "Erreur chargement de la pièce : " << SDL_GetError() << std::endl;
        return false;
    }
    textureGameOver = loadTexture("game_over.png");
    if (!textureGameOver) {
        std::cerr << "Erreur chargement de l'image game over : " << SDL_GetError() << std::endl;
        return false;
    }
    textureBackground = loadTexture("background.png");
    if (!textureBackground) {
        std::cerr << "Erreur chargement de l'image de fond : " << SDL_GetError() << std::endl;
        return false;
    }

    return true;
}

void SDLGame::render() {
    SDL_RenderClear(renderer);
    renderTexture(textureRunner, runnerRect);
    renderTexture(textureZombie, zombieRect);
    renderTexture(textureCoin, coinRect);
    SDL_RenderPresent(renderer);
}
SDL_Texture* SDLGame::loadTexture(const char* fileName) {
    SDL_Surface* surface = IMG_Load(fileName);
    if (!surface) {
        std::cerr << "Erreur hargement de l'image : " << IMG_GetError() << std::endl;
        return nullptr;
    }
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    return texture;
}
void SDLGame::renderTexture(SDL_Texture* texture, SDL_Rect dstRect) {
    SDL_RenderCopy(renderer, texture, NULL, &dstRect);
}
