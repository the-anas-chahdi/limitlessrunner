/**
 * @file RunningPlayer.h
 * @author damiyine loubna - anas chahdi
 * @brief
 * @version 0.1
 * @date 2024-04-15
 *
 * @copyright Copyright (c) 2024
 *
 */
#ifndef LIMITLESSRUNNER_RUNNINGPLAYER_H
#define LIMITLESSRUNNER_RUNNINGPLAYER_H
#include <SDL2/SDL.h>
#include "PlayerSDL.h"
#include "Lives.h"
#include "Coins_a.h"
#include "Coins_b.h"
#include "Unit.h"
#include "Ghost.h"
#include "Meteor.h"
#include "Explosion.h"
#include <vector>
#include <list>

using namespace std;

class RunningPlayer {
    vector<PlayerSDL *> player;
    vector<Lives> living;
    vector<Explosion> explosive;
    vector<Coins_b> coins;
    vector<Coins_a *> coining;
    list<Unit *> objects;

public:
    bool coin_check = false;
    bool lost_check = false;
    bool win_check = false;
    int tick = 0;
    bool life_check = false;
    bool checks = false;
    bool left = false;
    bool right = false;
    int counter = 0;
    void drawObjects();
    void createObject();
    void emptying();

    ~RunningPlayer();
};


#endif //LIMITLESSRUNNER_RUNNINGPLAYER_H
