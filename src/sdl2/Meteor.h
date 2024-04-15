/**
 * @file Meteor.h
 * @author damiyine loubna - anas chahdi
 * @brief
 * @version 0.1
 * @date 2024-04-15
 *
 * @copyright Copyright (c) 2024
 *
 */
#ifndef LIMITLESSRUNNER_METEOR_H
#define LIMITLESSRUNNER_METEOR_H
#include <SDL2/SDL.h>
#include "Drawing.h"
#include "Unit.h"

class Meteor : public Unit{

    friend class RunningMan;

public:
    int objType;
    void draw();
    void move();
    Meteor();
    ~Meteor();
};

#endif //LIMITLESSRUNNER_METEOR_H
