#include "Game.h"

Game::Game() : score(0), lives(3), runner(0, 0), grille() {
    zombies.push_back(Zombie(1, 0));
    coins.push_back(Coin(2, 0));
}

void Game::update() {
    for (Zombie& zombie : zombies) {
        zombie.moveDown();
    }

    for (Coin& coin : coins) {
        coin.moveDown();
    }
    checkCollisions();
}

void Game::checkCollisions() {
    for (Zombie& zombie : zombies) {
        if (runner.collidesWith(zombie)) {
            lives--; // Réduire le nombre de vies du joueur
            runner.resetPosition(); // Réinitialiser la position du joueur
            if (lives == 0) {
                // fin jeu ^^
            }
        }
    }

    for (Coin& coin : coins) {
        if (runner.collidesWith(coin)) {
            score++;
            coin.resetPosition();
        }
    }
}
