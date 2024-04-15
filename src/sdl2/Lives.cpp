/**
 * @file Lives.cpp
 * @author damiyine loubna - anas chahdi
 * @brief
 * @version 0.1
 * @date 2024-04-15
 *
 * @copyright Copyright (c) 2024
 *
 */
#include "Lives.h"

Lives::Lives(){
    srcRect = {0, 0, 599, 478};
    moverRect = {30,40, 50, 50};
}

void Lives::operator--(){
    l_left-=1;
}

void Lives :: draw(){
    moverRect = {20,-30, 50, 50};
    for(int i=0 ; i<l_left ; i++){
        if(i%5==0){
            moverRect.x=30;
            moverRect.y+=50;
        }
        SDL_RenderCopy(Drawing::gRenderer, Drawing::life, &srcRect, &moverRect);
        moverRect.x+=40;


    }
}

Lives :: ~Lives(){
}