/**
 * @file ScreenInfo.h
 * @author damiyine loubna - anas chahdi
 * @brief
 * @version 0.1
 * @date 2024-04-15
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef LIMITLESSRUNNER_SCREENINFO_H
#define LIMITLESSRUNNER_SCREENINFO_H
#include <iostream>

using namespace std;

class ScreenInfo
{
    static ScreenInfo *instance;
    int SCREEN_WIDTH = 1000;
    int SCREEN_HEIGHT = 600;

    ScreenInfo();

public:
    static ScreenInfo *getInstance()
    {
        if (!instance)
            instance = new ScreenInfo;
        return instance;
    }
    int getWidth();
    int getHeight();
    void setData(int w, int h);
    ~ScreenInfo();
};

#endif //LIMITLESSRUNNER_SCREENINFO_H
