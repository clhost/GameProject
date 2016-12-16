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
    sf::RectangleShape* pacman; // текстура
    sf::Color* color; // цвет пакмана
    Direction direction; // направление
    Direction predirection; // пре-направление
    sf::Clock clock;
    int scores; // количество очков
    float time;
    Map& map = Map::Instance();
    int PosX, PosY; // вспомогательные переменные (позиция пакмана на тайл-мапе)
    bool isCollision(); // проверка на коллизии
    void resolveCollision(bool); // решение коллизий
    void update(float);
    void eat(); // есть еду
    float x, y, w, h, dx, dy, speed; // габариты

public:
    void run();
    void draw(sf::RenderWindow *);
    float getX();
    float getY();
    Direction getDirection();
    void setScores(int);
    int getScores();
    static Charachter& Instance();

private:
    Charachter();
    Charachter(const Charachter&) = delete;
    Charachter&operator=(const Charachter&) = delete;
};