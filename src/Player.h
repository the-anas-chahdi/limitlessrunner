//
// Created by anasc on 25/03/2024.
//

#ifndef LIMITLESSRUNNER_PLAYER_H
#define LIMITLESSRUNNER_PLAYER_H

class Player {
private:
    int posX, posY;
    bool jumping;
    //
    int verticalVelocity;

public:
    Player(int x = 0, int y = 0);
    int getX() const;
    int getY() const;
    void setX(int x);
    void setY(int y);
    void move(int dx, int dy);
};

#endif //LIMITLESSRUNNER_PLAYER_H