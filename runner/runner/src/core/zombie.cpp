#include "zombie.h"

Zombie::Zombie(int initialX, int initialY) : x(initialX), y(initialY) {}

void Zombie::move() {
    ++y;
}

