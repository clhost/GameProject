#ifndef GAMEPROJECT_GHOSTFACTORY_H
#define GAMEPROJECT_GHOSTFACTORY_H


#include "Enemy.h"

class GhostFactory {
public:
    GhostFactory();
    Enemy* getEnemy(std::string);
};


#endif //GAMEPROJECT_GHOSTFACTORY_H
