#pragma once
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Direction.h"
#include "Map.h"
#include <stack>

class Charachter {
private:
    sf::RectangleShape* pacman; // текстура
    sf::Color* color; // цвет пакмана
    Direction direction;
    Direction predirection;
    sf::Clock clock;
    float time;
    Map* map;
    const sf::String* pMap;

    // с урока
    /*
     * x, y - координаты
     * w, h - высота и ширина
     * dx, dy - ускорения по x и y соответственно
     * speed - скорость
     */
    float x, y, w, h, dx, dy, speed;
    std::stack<Direction> stack; // стэк операций
    bool isCollision();
    void resolveCollision(bool);
    void update(float);

public:
    void run();
    void draw(sf::RenderWindow *);
    Charachter(int, int, int, int, Map*);
};