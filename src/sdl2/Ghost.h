/**
 * @file Ghost.h
 * @author damiyine loubna - anas chahdi
 * @brief
 * @version 0.1
 * @date 2024-04-15
 *
 * @copyright Copyright (c) 2024
 *
 */
#ifndef LIMITLESSRUNNER_GHOST_H
#define LIMITLESSRUNNER_GHOST_H
#include <SDL2/SDL.h>
#include "Drawing.h"
#include "Unit.h"


/** @brief cette classe représente un fantôme dans le jeu et hérite de la classe Unit et contient des méthodes pour dessiner le fantôme et le déplacer
*/

class Ghost : public Unit{

    friend class RunningMan;

public:
    int frame = 0;
    void draw();
    void move();
    Ghost();
    ~Ghost();
};

#endif //LIMITLESSRUNNER_GHOST_H
