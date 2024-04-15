/**
 * @file RunningPlayer.cpp
 * @author damiyine loubna - anas chahdi
 * @brief
 * @version 0.1
 * @date 2024-04-15
 *
 * @copyright Copyright (c) 2024
 *
 */
#include "RunningPlayer.h"

using namespace std;

void RunningPlayer::drawObjects() {
    for (int t = 0; t < explosive.size();) {
        if (explosive[t].value < 20) {
            explosive[t].draw();
            explosive[t].value++;
        } else {
            explosive.erase(explosive.begin() + t);
            continue; // Skip to the next iteration
        }
        ++t;
    }

    for (size_t k = 0; k < player.size(); ++k) {
        player[k]->draw();
        if (left) {
            if ((player[k]->moverRect.x - 130) < 0) {
                player[k]->moverRect.x = 0;
            } else {
                player[k]->moverRect.x -= 130;
            }
            left = false;
        }
        if (right) {
            if ((player[k]->moverRect.x + 130) > 980) {
                player[k]->moverRect.x = 980;
            } else {
                player[k]->moverRect.x += 130;
            }
            right = false;
        }
        if (checks) {
            player[k]->check = true;
            checks = false;
        }
        if (player[k]->check) {
            player[k]->jump();
        } else {
            player[k]->moving();
        }
    }

    for (size_t t = 0; t < living.size(); ++t) {
        living[t].draw();
        if (life_check) {
            --living[t];
            life_check = false;
        }
        if (living[t].l_left < 1) {
            lost_check = true;
        }
    }

    for (size_t t = 0; t < coins.size(); ++t) {
        coins[t].draw();
        if (coin_check) {
            ++coins[t];
            coin_check = false;
        }
        if (coins[t].counts > 10) {
            win_check = true;
        }
    }

    for (size_t t = 0; t < coining.size();) {
        coining[t]->draw();
        coining[t]->move();
        if (((abs(player[0]->moverRect.x - (coining[t]->moverRect.x)) < 12) &&
             (abs(player[0]->moverRect.y - (coining[t]->moverRect.y)) < 12))) {
            coin_check = true;
            delete coining[t];
            coining.erase(coining.begin() + t);
            continue; // Skip to the next iteration
        }
        ++t;
    }

    for (auto it = objects.begin(); it != objects.end();) {
        Unit* object = *it;
        object->draw();
        object->move();

        if ((SDL_HasIntersection(&player[0]->moverRect, &object->moverRect))) {
            life_check = true;
            Explosion ex(object->moverRect.x, object->moverRect.y);
            explosive.push_back(ex);
            it = objects.erase(it);
            continue;
        }

        if ((object->moverRect.x < 0) || (object->moverRect.y > 515)) {
            it = objects.erase(it);
            continue; // Skip to the next iteration
        }

        ++it;
    }
}


void RunningPlayer::createObject() {
    if (counter == 0) {
        if (player.size() < 1) {
            PlayerSDL *Player1 = new PlayerSDL();
            player.push_back(Player1);
        }

        if (living.size() < 1) {
            Lives liv;
            living.push_back(liv);
        }

        if (coins.size() < 1) {
            Coins_b cin;
            coins.push_back(cin);
        }

        counter++;
    }

    tick++;

    if (tick > 25) {
        cout << "created" << endl;
        int number = (rand() % 10);
        if (number == 0) {
            Coins_a *app1 = new Coins_a();
            coining.push_back(app1);
        } else if (number == 1 || number == 4) {
        } else if (number == 2 || number == 5) {
        } else if (number == 3 || number == 6) {
            Ghost *boo = new Ghost();
            objects.push_back(boo);
        } else if (number == 7 || number == 8 || number == 9) {
            Meteor *rock = new Meteor();
            objects.push_back(rock);
        }
        tick = 0;
    }
}

void RunningPlayer::emptying() {
    for (auto &&i : objects) {
        delete i;
    }
    objects.clear();

    for (auto &&i : player) {
        delete i;
    }
    player.clear();

    for (auto &&i : coining) {
        delete i;
    }
    coining.clear();



    explosive.clear();
}

RunningPlayer ::~RunningPlayer() {}