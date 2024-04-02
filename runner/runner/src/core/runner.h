// Dans le fichier runner.h

#ifndef RUNNER_H
#define RUNNER_H

class Runner {
private:
    int x, y;

public:
    Runner(int initialX, int initialY);
    void moveLeft();
    void moveRight();
    int getX() const { return x; }
    int getY() const { return y; }
};

#endif // RUNNER_H
