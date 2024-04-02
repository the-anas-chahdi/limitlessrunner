//
// Created by etulyon1 on 01/04/2024.
//

#include "Grille.h"
#include "grille.h"
#include <iostream>

Grille::Grille() : runner(1, 9) {
    for (int i = 0; i < HAUTEUR_GRILLE; ++i) {
        zombies[i] = Zombie(rand() % LARGEUR_GRILLE, i);
        coins[i] = Coin(rand() % LARGEUR_GRILLE, i);
    }
}

void Grille::initialiser() {
    for (int i = 0; i < HAUTEUR_GRILLE; ++i) {
        for (int j = 0; j < LARGEUR_GRILLE; ++j) {
            tableau[j][i] = ' ';
        }
    }
}

void Grille::mettreAJour() {
    for (int i = 0; i < HAUTEUR_GRILLE; ++i) {
        zombies[i].deplacerBas();
        coins[i].deplacerBas();
    }
    char input;
    std::cin >> input;
    if (input == 'G') {
        runner.deplacerGauche();
    } else if (input == 'D') {
        runner.deplacerDroite();
    }
}

void Grille::afficher() {
    system("clear");
    for (int i = 0; i < HAUTEUR_GRILLE; ++i) {
        for (int j = 0; j < LARGEUR_GRILLE; ++j) {
            if (runner.getX() == j && runner.getY() == i) {
                std::cout << 'R';
            } else if (coins[i].getX() == j && coins[i].getY() == i) {
                std::cout << 'C';
            } else if (zombies[i].getX() == j && zombies[i].getY() == i) {
                std::cout << 'Z';
            } else {
                std::cout << tableau[j][i];
            }
        }
        std::cout << std::endl;
    }
}
