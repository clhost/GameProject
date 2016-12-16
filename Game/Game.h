#pragma once;
#include <SFML/Graphics.hpp>
#include "Map.h"
#include "Charachter.h"
#include "Ghosts/Enemy.h"
#include "Ghosts/Blinky.h"
#include "Ghosts/Pinky.h"
#include "Ghosts/Inkey.h"
#include "Ghosts/Clyde.h"
#include "../Animation.h"
#include "Ghosts/GhostFactory.h"

class Game {
    sf::RenderWindow *window; // окно игры
    Map& map = Map::Instance();
    Animation* animation;
    Charachter& pacman = Charachter::Instance();
    GhostFactory* factory;
    Enemy *blinky, *pinky, *inkey, *clyde;
public:
    void run();
    Game();
};