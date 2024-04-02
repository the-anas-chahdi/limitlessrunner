#ifndef SDLGAME_H
#define SDLGAME_H

#include <SDL2/SDL.h>

class SDLGame {
public:
    SDLGame();
    ~SDLGame();

    bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
    void render();

private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Texture* textureRunner;
    SDL_Texture* textureZombie;
    SDL_Texture* textureCoin;
    SDL_Texture* textureGameOver;
    SDL_Texture* textureBackground;
    SDL_Texture* loadTexture(const char* fileName);
    void renderTexture(SDL_Texture* texture, SDL_Rect dstRect);
};

#endif // SDLGAME_H
