#include <iostream>
#include "Enemy.h"

Enemy::Enemy(int X, int Y, int W, int H, Charachter* charachter, Map* m) {
    map = m;
    pacman = charachter;
    x = X; y = Y; w = W; h = H;
    dx = 0; dy = 0; speed = 0;
    direction = STAY;
    i = 0;
    f = true;

    initSpeed = 0.1;

    PosX = (int) floor((x + 12) / 24);
    PosY = (int) floor((y + 12) / 24);

    // инициализация квадрантов
    initQuadrants();
}

void Enemy::run() {
    time = clock.getElapsedTime().asMicroseconds();
    clock.restart();
    time = time / 800;

    /*std::cout << PosX << " | " << floor((pacman->getX() + 12) / 24) << std::endl;
    std::cout << PosY << " | " << floor((pacman->getY() + 12) / 24) << std::endl;
    // пересечение с пакманом
    if (PosX == floor((pacman->getX() + 12) / 24) &&
        PosY == floor(pacman->getY() + 12) / 24) {
        std::cout << PosX << " | " << floor((pacman->getX() + 12) / 24) << std::endl;
        std::cout << PosY << " | " << floor((pacman->getY() + 12) / 24) << std::endl;
    }*/

    if (direction == RIGHT) {
        PosX = (int) floor(x / 24);
        PosY = (int) floor((y + 12) / 24);
    }
    if (direction == LEFT) {
        PosX = (int) floor((x + 24) / 24);
        PosY = (int) floor((y + 12) / 24);
    }
    if (direction == UP) {
        PosX = (int) floor((x + 12) / 24);
        PosY = (int) floor((y + 24) / 24);
    }
    if (direction == DOWN) {
        PosX = (int) floor((x + 12) / 24);
        PosY = (int) floor(y / 24);
    }

    // f - чтобы не пересчитывать путь каждый раз
    //scaryMode();
    findPath(f);

    int currX, currY; // текущая клетка в пути, где находится привидение
    int nextX, nextY; // следующая клетка пути, где находится привидение
    int end = algorithm.size; // размер пути

    currX = algorithm.px[i];
    currY = algorithm.py[i];
    nextX = algorithm.px[i + 1];
    nextY = algorithm.py[i + 1];

    if (PosX == nextX && PosY == nextY) i++; // переход к следующей клетке пути

    // поведение привидения на каждом шаге
    if (i < end - 1) {
        if (nextX - currX == 1) { direction = RIGHT; }
        if (nextX - currX == -1) { direction = LEFT; }
        if (nextY - currY == 1) { direction = DOWN; }
        if (nextY - currY == -1) { direction = UP; }


        if (direction == RIGHT) speed = initSpeed;
        if (direction == LEFT) speed = initSpeed;
        if (direction == UP) speed = initSpeed;
        if (direction == DOWN) speed = initSpeed;
        if (direction == STAY) speed = 0;
    }

    update(time);

    // если достигнут конец пути, остановится и обнулить i для поиска возможного дальнейшего пути
    if (i == end - 1) {
        direction = STAY;
        f = true;
        i = 0;
    }
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
    sprite.setPosition(x, y);
}

void Enemy::findPath(bool f) {
    if (f) {
        algorithm.findPath(PosX, PosY, (int) floor((pacman->getX() + 12) / 24), (int) floor((pacman->getY() + 12) / 24));
        Enemy::f = false;
    }
}

void Enemy::initQuadrants() {
    first[0].x = 18;
    first[0].y = 1;

    first[1].x = 23;
    first[1].y = 5;

    first[2].x = 18;
    first[2].y = 8;

    first[3].x = 16;
    first[3].y = 5;

    second[0].x = 18;
    second[0].y = 12;

    second[1].x = 17;
    second[1].y = 19;

    second[2].x = 21;
    second[2].y = 21;

    second[3].x = 13;
    second[3].y = 23;

    third[0].x = 6;
    third[0].y = 12;

    third[1].x = 7;
    third[1].y = 19;

    third[2].x = 3;
    third[2].y = 21;

    third[3].x = 11;
    third[3].y = 23;

    fourth[0].x = 6;
    fourth[0].y = 1;

    fourth[1].x = 1;
    fourth[1].y = 5;

    fourth[2].x = 8;
    fourth[2].y = 5;

    fourth[3].x = 6;
    fourth[3].y = 7;
}

Direction Enemy::getDirection() {
    return direction;
}

void Enemy::setSprite(sf::IntRect s) {
    sprite.setTextureRect(s);
}

int Enemy::getIndex() {
    return index;
}

sf::Sprite Enemy::getSprite() {
    return sprite;
}

void Enemy::scaryMode() {

    if (map->cellMap[19][23].condition == PASSABLE /*||
        map->cellMap[19][1].condition == PASSABLE ||
        map->cellMap[3][1].condition == PASSABLE ||
        map->cellMap[3][23].condition == PASSABLE*/) {

        initSpeed = 0.05;
    }
}
