//
// Created by etulyon1 on 01/04/2024.
//


#ifndef GRILLE_H
#define GRILLE_H

#include "runner.h"
#include "zombie.h"
#include "coin.h"

class Grille {
private:
    static const int LARGEUR_GRILLE = 3; // Nombre de colonnes dans la grille
    static const int HAUTEUR_GRILLE = 10; // Nombre de lignes dans la grille
    char tableau[LARGEUR_GRILLE][HAUTEUR_GRILLE]; // Représentation de la grille

    Runner runner; // Le joueur
    Zombie zombies[HAUTEUR_GRILLE]; // Tableau de zombies
    Coin coins[HAUTEUR_GRILLE]; // Tableau de pièces

public:
    Grille();

    // Méthodes pour initialiser, mettre à jour et afficher la grille
    void initialiser();
    void mettreAJour();
    void afficher();
};

#endif // GRILLE_H
