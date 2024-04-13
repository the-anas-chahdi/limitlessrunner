#include "SDLTextures.h"
#include <SDL2/SDL_image.h>
#include <iostream>

SDL_Texture* SDLTextures::loadTexture(SDL_Renderer* renderer, const std::string& filePath) {
    SDL_Surface* loadedSurface = IMG_Load(filePath.c_str());
    if (!loadedSurface) {
        std::cerr << "Unable to load image " << filePath << "! SDL_image Error: " << IMG_GetError() << std::endl;
        return nullptr;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
    if (!texture) {
        std::cerr << "Unable to create texture from " << filePath << "! sdl2 Error: " << SDL_GetError() << std::endl;
    }
    SDL_FreeSurface(loadedSurface);

    return texture;
}
