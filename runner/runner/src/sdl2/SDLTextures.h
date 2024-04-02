#ifndef SDLTEXTURES_H
#define SDLTEXTURES_H

#include <SDL2/SDL.h>
#include <string>

class SDLTextures {
public:
    static SDL_Texture* loadTexture(SDL_Renderer* renderer, const std::string& filePath);
};
#endif // SDLTEXTURES_H
