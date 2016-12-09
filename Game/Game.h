#pragma once;
#include <SFML/Graphics.hpp>
#include "Map.h"
#include "Charachter.h"
#include "Enemy.h"
#include "../Menu/Menu.h"
#include "Ghosts/Blinky.h"
#include "Ghosts/Pinky.h"
#include "Ghosts/Inkey.h"
#include "Ghosts/Clyde.h"
#include "../Animation.h"

enum GameState {
    onResume,
    onPaused,
    onClose,
    onMenu
};

class Game {
    sf::RenderWindow *window; // окно игры
    Menu *menu; // окно меню
    Map* map;
    Animation* animation;
    Charachter* pacman;
    Blinky* blinky;
    Pinky* pinky;
    Inkey* inkey;
    Clyde* clyde;
    GameState state;
public:
    void run();
    Game();
};