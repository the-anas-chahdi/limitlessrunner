//
// Created by etulyon1 on 01/04/2024.
//
#include "src/core/Game.h"
#include "src/sdl2/SDLGame.h"

int main() {
    Game game;
    if (!game.init()) {
        std::cerr << "Erreur initialisation du jeu." << std::endl;
        return 1;
    }
    SDLGame sdlGame;
    if (!sdlGame.init("Runner Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false)) {
        std::cerr << "Erreur initialisation de sdl2." << std::endl;
        return 1;
    }
    while (!game.isGameOver()) {
        game.handleEvents();
        game.update();
        sdlGame.clear();
        sdlGame.render(game);
        sdlGame.present();
    }
    return 0;
}
