#ifndef GAMEPROJECT_CLYDE_H
#define GAMEPROJECT_CLYDE_H


#include "Enemy.h"

class Clyde : public Enemy {
public:
    Clyde(int, int, int, int);

private:
    void findPath(bool);
    int pX, pY;
};


#endif //GAMEPROJECT_CLYDE_H
