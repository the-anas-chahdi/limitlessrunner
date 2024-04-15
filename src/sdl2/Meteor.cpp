/**
 * @file Meteor.cpp
 * @author damiyine loubna - anas chahdi
 * @brief
 * @version 0.1
 * @date 2024-04-15
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "Meteor.h"

Meteor::Meteor(){
    moverRect = {(200 + rand() % 780), 0, 70, 70};
    srcRect = {212, 326, 1978, 1807};
    objType = rand() % 2;
}
/**

@brief dessine le météore sur l'écran et utilise le rendu SDL pour copier la texture
*/

void Meteor::draw(){
    SDL_RenderCopy(Drawing::gRenderer, Drawing::Meteor, &srcRect, &moverRect);
}

void Meteor::move(){
    if (objType == 0){
        moverRect.x += 15;
        moverRect.y += 20;
    }
    else if (objType == 1){
        moverRect.x -= 15;
        moverRect.y += 20;
    }
    else if (objType == 2){
        moverRect.y += 20;
    }
}

Meteor ::~Meteor(){
}