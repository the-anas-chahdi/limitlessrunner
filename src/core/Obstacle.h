
#ifndef LIMITLESSRUNNER_OBSTACLE_H
#define LIMITLESSRUNNER_OBSTACLE_H

class Obstacle {
private:
    int posX, posY;

public:
    Obstacle(int x = -1, int y= -1);
    int getX() const;
    int getY() const;
    void setX(int x);
    void setY(int y);
};

#endif // LIMITLESSRUNNER_OBSTACLE_H
