#ifndef GAMEPROJECT_PINKY_H
#define GAMEPROJECT_PINKY_H


#include "../Enemy.h"

class Pinky : public Enemy{
public:
    Pinky(int, int, int, int, Charachter*, Map*);

private:
    Direction dir; // направление пакмана
    int pX, pY; // позиции пакмана (вспомогательные переменные)
    void findPath(bool);
};


#endif //GAMEPROJECT_PINKY_H
