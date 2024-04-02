//
// Created by etulyon1 on 01/04/2024.
//
#ifndef COIN_H
#define COIN_H

class Coin {
private:
    int x, y;

public:
    Coin(int initialX, int initialY);
    void move(); // deplacement to the south
    int getX() const { return x; }
    int getY() const { return y; }
};

#endif // COIN_H

