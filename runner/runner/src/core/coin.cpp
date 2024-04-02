//
// Created by etulyon1 on 01/04/2024.
//

#include "coin.h"
#include "coin.h"

Coin::Coin(int initialX, int initialY) : x(initialX), y(initialY) {}

void Coin::move() {
    ++y;
}
