#ifndef GAMEPROJECT_BLINKY_H
#define GAMEPROJECT_BLINKY_H


#include "../Enemy.h"

class Blinky : public Enemy {
public:
    Blinky(int, int, int, int, Charachter*, Map*);

private:
    void findPath(bool);
    int pX, pY;
};

#endif //GAMEPROJECT_BLINKY_H