#include <iostream>
#include <SFML/Window/Keyboard.hpp>
#include "Enemy.h"

Enemy::Enemy(int X, int Y, int W, int H, sf::Color *col, Map *m, Charachter* charachter) {
    pacman = charachter;
    map = m;
    x = X; y = Y; w = W; h = H;
    dx = 0; dy = 0; speed = 0;
    ghost = new sf::RectangleShape(sf::Vector2f(w, h));
    //color = new sf::Color(255, 235, 59);
    color = col;
    ghost->setFillColor(*color);
    ghost->setPosition(x, y);
    direction = STAY;
    i = 0;
    f = true;
    //algorithm = new WaveTracingAlgorithm();

    PosX = (int) floor((x + 12) / 24);
    PosY = (int) floor((y + 12) / 24);

    a = 23, b = 23;
}

/** Этот метод щас делаю **/
void Enemy::run() {
    time = clock.getElapsedTime().asMicroseconds();
    clock.restart();
    time = time / 800;

    if (direction == RIGHT) { // LEFT
        PosX = (int) floor(x / 24);
        PosY = (int) floor((y + 12) / 24);
    }
    if (direction == LEFT) { // RIGHT
        PosX = (int) floor((x + 24) / 24);
        PosY = (int) floor((y + 12) / 24);
    }
    if (direction == UP) { // DOWN
        PosX = (int) floor((x + 12) / 24);
        PosY = (int) floor((y + 24) / 24);
    }
    if (direction == DOWN) { // UP
        PosX = (int) floor((x + 12) / 24);
        PosY = (int) floor(y / 24);
    }

    if (f) {
        //std::cout << PosX << " | " << PosY << "\n";
        algorithm.findPath(PosX, PosY, (int) floor((pacman->getX() + 12) / 24), (int) floor((pacman->getY() + 12) / 24));
        f = false;
    }

    //std::cout << (int) floor((Charachter::x + 12) / 24) << " | " << (int) floor((Charachter::y + 12) / 24) << "\n";
    //std::cout << (int) floor((pacman->getX() + 12) / 24) << " | " << (int) floor((pacman->getY() + 12) / 24) << "\n";

    int currX, currY;
    int nextX, nextY;
    int end = algorithm.size;

    //std::cout << i << " | " << end - 1 << std::endl;

    currX = algorithm.px[i];
    currY = algorithm.py[i];
    nextX = algorithm.px[i + 1];
    nextY = algorithm.py[i + 1];

    /* самая важная строчка этого алгоритма */
    if (PosX == nextX && PosY == nextY) i++;

    if (i < end - 1) {
        if (nextX - currX == 1) { direction = RIGHT; }
        if (nextX - currX == -1) { direction = LEFT; }
        if (nextY - currY == 1) { direction = DOWN; }
        if (nextY - currY == -1) { direction = UP; }


        if (direction == RIGHT) speed = 0.1;
        if (direction == LEFT) speed = 0.1;
        if (direction == UP) speed = 0.1;
        if (direction == DOWN) speed = 0.1;
        if (direction == STAY) speed = 0;
    }
    update(time);

    if (i == end - 1) {
        direction = STAY;
        f = true;
        a = 1;
        b = 1;
        i = 0;
    }
}

void Enemy::draw(sf::RenderWindow* window) {
    window->draw(*ghost);
}

void Enemy::update(float) {
    switch (direction) {
        case RIGHT: dx = speed; dy = 0; break;
        case LEFT: dx = -speed; dy = 0; break;
        case DOWN: dx = 0; dy = speed; break;
        case UP: dx = 0; dy = -speed; break;
        case STAY: dx = 0; dy = 0; break;
    }
    x += dx * time;
    y += dy * time;
    ghost->setPosition(x, y);
}