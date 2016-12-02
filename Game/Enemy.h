#pragma once
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "../Other/Direction.h"
#include "../Algorithms/WaveTracingAlgorithm.h"
#include "Map.h"
#include "Charachter.h"

class Enemy {
private:
    int a, b;
    sf::Color* color; // цвет госта
    Direction direction;
    sf::Clock clock;
    float time;
    Map* map;
    Charachter* pacman;
    const sf::String* pMap;
    float x, y, w, h, dx, dy, speed;
    int i;
    bool f;
    sf::RectangleShape* ghost; // текстура
    int PosX, PosY;
    WaveTracingAlgorithm algorithm;
    //WaveTracingAlgorithm& algorithm = WaveTracingAlgorithm::Instance();
    void update(float);
public:
    void run();
    void draw(sf::RenderWindow *);
    Enemy(int, int, int, int, sf::Color *, Map*, Charachter*);
};