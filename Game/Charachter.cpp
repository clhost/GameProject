#include <iostream>
#include <cmath>
#include "Charachter.h"

Charachter::Charachter(int X, int Y, int W, int H, Map* m) {
    map = m;
    x = X; y = Y; w = W; h = H;
    dx = 0; dy = 0; speed = 0;
    pacman = new sf::RectangleShape(sf::Vector2f(w, h));
    color = new sf::Color(255, 235, 59);
    pacman->setFillColor(*color);
    pacman->setPosition(x, y);
    direction = STAY;
}

void Charachter::run() {
    time = clock.getElapsedTime().asMicroseconds();
    clock.restart();
    time = time / 800;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) direction = LEFT;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) direction = RIGHT;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) direction = UP;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) direction = DOWN;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) direction = STAY;

    if (direction == LEFT) speed = 0.1;
    if (direction == RIGHT) speed = 0.1;
    if (direction == UP) speed = 0.1;
    if (direction == DOWN) speed = 0.1;
    if (direction == STAY) speed = 0;

    update(time);
}

void Charachter::draw(sf::RenderWindow* window) {
    window->draw(*pacman);
}

void Charachter::update(float time) {
    switch (direction) {
        case RIGHT: dx = speed; dy = 0; break;
        case LEFT: dx = -speed; dy = 0; break;
        case DOWN: dx = 0; dy = speed; break;
        case UP: dx = 0; dy = -speed; break;
        case STAY: dx = 0; dy = 0; break;
    }
    x += dx * time;
    y += dy * time;
    resolveCollision(isCollision());
    pacman->setPosition(x, y);
}

bool Charachter::isCollision() {

    /** работа с картой напрямую (переписать) **/

    /* текущее положение пакмана на сетке */
    if (direction == RIGHT) {
        PosX = (int) floor((x + 24) / 24);
        PosY = (int) floor((y + 12) / 24);
        if (map->cellMap[PosY][PosX].condition == IMPASSABLE) return true;
    }
    else if (direction == DOWN) {
        PosX = (int) floor((x + 12) / 24);
        PosY = (int) floor((y + 24) / 24);
        if (map->cellMap[PosY][PosX].condition == IMPASSABLE) return true;
    }
    else if (direction == LEFT) {
        PosX = (int) floor(x / 24);
        PosY = (int) floor((y + 12) / 24);
        if (map->cellMap[PosY][PosX].condition == IMPASSABLE) return true;
    }
    else if (direction == UP) {
        PosX = (int) floor((x + 12) / 24);
        PosY = (int) floor(y / 24);
        if (map->cellMap[PosY][PosX].condition == IMPASSABLE) return true;
    }
    return false;
}

void Charachter::resolveCollision(bool f) {
    if (f) {
        std::cout << "Collision\n";
        if (direction == LEFT) {
            PosX = (int) floor(x / 24);
            PosY = (int) floor((y + 12) / 24);
            x = map->cellMap[PosY][PosX].uR.x; //останавливаем движение по х влево
        }
        if (direction == RIGHT) {
            PosX = (int) floor((x + 24) / 24);
            PosY = (int) floor((y + 12) / 24);
            x = map->cellMap[PosY][PosX].uL.x - 24; //останавливаем движение по х вправо
        }
        if (direction == DOWN) {
            PosX = (int) floor((x + 12) / 24);
            PosY = (int) floor((y + 24) / 24);
            y = map->cellMap[PosY][PosX].uL.y - 24; //останавливаем движение по y вниз
        }
        if (direction == UP) {
            PosX = (int) floor((x + 12) / 24);
            PosY = (int) floor(y / 24);
            y = map->cellMap[PosY][PosX].uR.y; //останавливаем движение по y вверх
        }
        direction = STAY;
    } else return;
}