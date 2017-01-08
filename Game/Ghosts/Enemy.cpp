#include <iostream>
#include "Enemy.h"

Enemy::Enemy(int X, int Y, int W, int H) {
    x = X; y = Y; w = W; h = H;
    dx = 0; dy = 0; speed = 0;
    direction = STAY;
    i = 0;
    f = true;

    initSpeed = 0.1;

    PosX = (int) floor((x + 12) / 24);
    PosY = (int) floor((y + 12) / 24);

    // инициализация квадрантов для бота
    initQuadrants();
}

void Enemy::run() {
    time = clock.getElapsedTime().asMicroseconds();
    clock.restart();
    time = time / 800;

    if ((int) floor((pacman.getY() + 12) / 24) == (int) floor((y + 12) / 24) &&
        (int) floor((pacman.getX() + 12) / 24) == (int) floor((x + 12) / 24)) {
        pacman.setScores(208);
    }

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
    scaryMode();
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

void Enemy::findPath(bool) {}

void Enemy::initQuadrants() {
    first[0] = Point(18, 1);
    first[1] = Point(23, 5);
    first[2] = Point(18, 8);
    first[3] = Point(16, 5);

    second[0] = Point(18, 12);
    second[1] = Point(17, 19);
    second[2] = Point(21, 21);
    second[3] = Point(13, 23);

    third[0] = Point(6, 12);
    third[1] = Point(7, 19);
    third[2] = Point(3, 21);
    third[3] = Point(11, 23);

    fourth[0] = Point(6, 1);
    fourth[1] = Point(1, 5);
    fourth[2] = Point(8, 5);
    fourth[3] = Point(6, 7);
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
    if (a)
        if (map.cellMap[19][23].condition == PASSABLE) {
            timer = std::time(NULL);
            a = false;
            initSpeed = 0.05;
        }
    if (b)
        if (map.cellMap[19][1].condition == PASSABLE) {
            timer = std::time(NULL);
            b = false;
            initSpeed = 0.05;
        }
    if (c)
        if (map.cellMap[3][1].condition == PASSABLE) {
            timer = std::time(NULL);
            c = false;
            initSpeed = 0.05;
        }
    if (d)
        if (map.cellMap[3][23].condition == PASSABLE) {
            timer = std::time(NULL);
            d = false;
            initSpeed = 0.05;
        }
    if (timer + 5 == std::time(NULL)) initSpeed = 0.1;
}
