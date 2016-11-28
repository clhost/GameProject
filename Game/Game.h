#pragma once;
#include <SFML/Graphics.hpp>
#include "Map.h"
#include "Charachter.h"
#include "Enemy.h"
#include "../Menu/Menu.h"

enum GameState {
    onResume,
    onPaused,
    onClose,
    onMenu
};

class Game {
    sf::RenderWindow *window; //Окно игры
    Menu *menu; //Окно меню
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