// Dans le fichier runner.cpp

#include "runner.h"

Runner::Runner(int initialX, int initialY) : x(initialX), y(initialY) {}

void Runner::moveLeft() {
    if (x > 0) {
        --x;
    }
}

void Runner::moveRight() {
    if (x < 2) {
        ++x;
    }
}
