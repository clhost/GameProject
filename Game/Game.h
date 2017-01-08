#pragma once;
#include <SFML/Graphics.hpp>
#include <memory>
#include "Map/Map.h"
#include "Pacman/Charachter.h"
#include "Ghosts/Enemy.h"
#include "../Draw/Animation.h"
#include "Ghosts/GhostFactory.h"

class Game {
    sf::RenderWindow *window; // окно игры
    Map& map = Map::Instance();
    Charachter& pacman = Charachter::Instance();
    GhostFactory factory;
    std::unique_ptr<Enemy> blinky;
    std::unique_ptr<Enemy> pinky;
    std::unique_ptr<Enemy> inkey;
    std::unique_ptr<Enemy> clyde;
public:
    void run();
    Game();
    ~Game();
};