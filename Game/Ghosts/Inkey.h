#ifndef GAMEPROJECT_INKEY_H
#define GAMEPROJECT_INKEY_H


#include "../Enemy.h"

class Inkey : public Enemy {
public:
    Inkey(int, int, int, int, Charachter*, Map*);

private:
    void findPath(bool);
    int pX, pY;
};


#endif //GAMEPROJECT_INKEY_H
