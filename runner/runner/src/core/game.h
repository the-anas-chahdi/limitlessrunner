#ifndef GAME_H
#define GAME_H

#include "Runner.h"
#include "Zombie.h"
#include "Coin.h"
#include "Grille.h"

class Game {
public:
    Game();
    void update();
    void checkCollisions();
private:
    int score;
    int lives;
    Runner runner;
    std::vector<Zombie> zombies;
    std::vector<Coin> coins;
    Grille grille;
};

#endif // GAME_H
