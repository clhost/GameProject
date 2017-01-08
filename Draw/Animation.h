#ifndef GAMEPROJECT_ANIMATION_H
#define GAMEPROJECT_ANIMATION_H


#include "../Game/Ghosts/Enemy.h"

class Animation {
public:
    Animation() {};
    void draw(std::unique_ptr<Enemy>&, sf::RenderWindow*);
    void draw(Charachter&, sf::RenderWindow*);
};


#endif //GAMEPROJECT_ANIMATION_H