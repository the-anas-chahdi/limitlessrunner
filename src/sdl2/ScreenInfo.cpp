/**
 * @file ScreenInfo.cpp
 * @author damiyine loubna - anas chahdi
 * @brief
 * @version 0.1
 * @date 2024-04-15
 *
 * @copyright Copyright (c) 2024
 *
 */
#include "ScreenInfo.h"

using namespace std;

ScreenInfo::ScreenInfo(){}

int ScreenInfo::getWidth() {
    return this ->SCREEN_WIDTH;
}
int ScreenInfo::getHeight() {
    return this ->SCREEN_HEIGHT;
}

void ScreenInfo::setData(int w, int h) {
    this -> SCREEN_WIDTH = w;
    this -> SCREEN_WIDTH = h;
}

ScreenInfo::~ScreenInfo(){

}