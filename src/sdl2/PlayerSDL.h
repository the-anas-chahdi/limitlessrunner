//
// Created by anas on 13/04/24.
//

#ifndef LIMITLESSRUNNER_PLAYERSDL_H
#define LIMITLESSRUNNER_PLAYERSDL_H

class PlayerSDL {
private:
    int posX, posY;
    int lives;

public:
    PlayerSDL(int x = 2, int y = 600 - 2, int startingLives = 3);
    int getX() const;
    int getY() const;
    void setX(int x);
    void setY(int y);
    int getLives() const;
    void setLives(int newLives);
    void loseLife();
};

#endif //LIMITLESSRUNNER_PLAYERSDL_H
