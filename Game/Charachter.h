#pragma once
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "../Other/Direction.h"
#include "Map.h"
#include <stack>
#include <SFML/Graphics/Sprite.hpp>

class Charachter {
private:
    sf::Texture texture;
    //sf::Sprite pacman;

    sf::RectangleShape* pacman; // текстура
    sf::Color* color; // цвет пакмана
    Direction direction;
    Direction predirection;
    sf::Clock clock;
    int scores; // количество очков
    float time;
    Map* map;
    int PosX, PosY;
    bool isCollision();
    void resolveCollision(bool);
    void update(float);
    void eat();
    float x, y, w, h, dx, dy, speed;

public:
    void run();
    void draw(sf::RenderWindow *);
    Charachter(int, int, int, int, Map*);
    Charachter() {}
    float getX();
    float getY();
    Direction getDirection();
    int getScores();
};