#pragma once
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "../Other/Direction.h"

class Enemy {
private:
    sf::RectangleShape* ghost; // текстура
    sf::Color* color; // цвет госта
    Direction direction;
public:
    void run();
    void draw(sf::RenderWindow *);
    Enemy(int, int, sf::Color *);
};