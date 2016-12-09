#pragma once
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "../Other/Direction.h"
#include "../Algorithms/WaveTracingAlgorithm.h"
#include "Map.h"
#include "Charachter.h"

class Enemy {
protected:
    sf::Texture texture;
    sf::Sprite sprite;
    Charachter* pacman;
    float x, y, w, h, dx, dy, speed;
    float initSpeed;
    Map* map;
    bool f;
    int PosX, PosY;
    WaveTracingAlgorithm algorithm;
    virtual void findPath(bool);
    Point first[4]; // первый квадрант карты
    // /* 4 точки в каждом */
    // здесь точка рассматривается не как точка, а как клетка,
    // то есть х с [1, 23], y c [1, 23]
    Point second[4]; // второй квадрант карты
    Point third[4]; // третий квадрант
    Point fourth[4]; // четвертый квадрант
    int index;
private:
    void update(float);
    Enemy() {}
    int i;
    float time;
    Direction direction;
    sf::Clock clock;
    void initQuadrants();
public:
    void run();
    Enemy(int, int, int, int, Charachter*, Map*);
    Direction getDirection();
    void setSprite(sf::IntRect);
    int getIndex();
    sf::Sprite getSprite();
    void scaryMode();
};