#pragma once;
#include <SFML/Graphics.hpp>
#include "Map.h"
#include "Charachter.h"
#include "Enemy.h"

enum GameState {
    onResume,
    onPaused,
    onClose,
    onMenu
};

class Game {
    sf::RenderWindow *window; //Окно игры
    sf::RenderWindow *menu; //Окно меню
    Map* map;
    Charachter* pacman;
    Enemy* blinky;
    Enemy* pinky;
    Enemy* inkey;
    Enemy* clyde;
    GameState state;
public:
    void run();
    Game();
};