#ifndef ZOMBIE_H
#define ZOMBIE_H

class Zombie {
private:
    int x, y;

public:
    Zombie(int initialX, int initialY);
    void move();
    int getX() const { return x; }
    int getY() const { return y; }
};

#endif // ZOMBIE_H
