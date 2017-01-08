#include "Charachter.h"

Charachter::Charachter() {
    x = 240; y = 456; w = 24; h = 24;
    dx = 0; dy = 0; speed = 0;
    pacman = sf::RectangleShape(sf::Vector2f(w, h));
    color = sf::Color(255, 235, 59);
    pacman.setFillColor(color);
    pacman.setPosition(x, y);
    direction = RIGHT;
    predirection = STAY;
    scores = 0;
}

void Charachter::run() {
    time = clock.getElapsedTime().asMicroseconds();
    clock.restart();
    time = time / 800;


    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) predirection = LEFT;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) predirection = RIGHT;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) predirection = UP;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) predirection = DOWN;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) predirection = STAY;

    // движение (пакман не останавливается)

    // если остановился, считать движение снова
    if (direction == STAY) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) direction = LEFT;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) direction = RIGHT;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) direction = UP;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) direction = DOWN;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) direction = STAY;
    }

    // проверка при движении влево
    if (direction == LEFT) {
        PosX = (int) floor((x + 23) / 24);
        PosY = (int) floor((y) / 24);

        int xX = (int) floor((x) / 24);
        int yY = (int) floor((y) / 24);

        if (predirection == RIGHT) direction = RIGHT;

        if (predirection == UP)
            if (map.cellMap[PosY - 1][PosX].condition == PASSABLE ||
                map.cellMap[PosY - 1][PosX].condition == FOOD ||
                map.cellMap[PosY - 1][PosX].condition == SUPERFOOD) {

                if (map.cellMap[yY - 1][xX].condition == PASSABLE ||
                    map.cellMap[yY - 1][xX].condition == FOOD ||
                    map.cellMap[yY - 1][xX].condition == SUPERFOOD) {
                    x = x - 1;
                    direction = predirection;
                }
            }

        if (predirection == DOWN)
            if (map.cellMap[PosY + 1][PosX].condition == PASSABLE ||
                map.cellMap[PosY + 1][PosX].condition == FOOD ||
                map.cellMap[PosY + 1][PosX].condition == SUPERFOOD) {

                if (map.cellMap[yY + 1][xX].condition == PASSABLE ||
                    map.cellMap[yY + 1][xX].condition == FOOD ||
                    map.cellMap[yY + 1][xX].condition == SUPERFOOD) {
                    x = x - 1;
                    direction = predirection;
                }
            }
    }

    // проверка при движении вправо
    if (direction == RIGHT) {
        PosX = (int) floor((x) / 24);
        PosY = (int) floor((y) / 24);

        int xX = (int) floor((x + 23) / 24);
        int yY = (int) floor((y) / 24);

        if (predirection == LEFT) direction = LEFT;

        if (predirection == UP)
            if (map.cellMap[PosY - 1][PosX].condition == PASSABLE ||
                map.cellMap[PosY - 1][PosX].condition == FOOD ||
                map.cellMap[PosY - 1][PosX].condition == SUPERFOOD) {

                if (map.cellMap[yY - 1][xX].condition == PASSABLE ||
                    map.cellMap[yY - 1][xX].condition == FOOD ||
                    map.cellMap[yY - 1][xX].condition == SUPERFOOD) {
                    direction = predirection;
                }
            }

        if (predirection == DOWN)
            if (map.cellMap[PosY + 1][PosX].condition == PASSABLE ||
                map.cellMap[PosY + 1][PosX].condition == FOOD ||
                map.cellMap[PosY + 1][PosX].condition == SUPERFOOD) {

                if (map.cellMap[yY + 1][xX].condition == PASSABLE ||
                    map.cellMap[yY + 1][xX].condition == FOOD ||
                    map.cellMap[yY + 1][xX].condition == SUPERFOOD) {
                    direction = predirection;
                }
            }
    }

    // проверка при движении вверх
    if (direction == UP) {
        PosX = (int) floor((x + 23) / 24);
        PosY = (int) floor((y) / 24);

        int xX = (int) floor((x + 23) / 24);
        int yY = (int) floor((y + 23) / 24);

        if (predirection == DOWN) direction = DOWN;

        if (predirection == RIGHT)
            if (map.cellMap[PosY][PosX + 1].condition == PASSABLE ||
                map.cellMap[PosY][PosX + 1].condition == FOOD ||
                map.cellMap[PosY][PosX + 1].condition == SUPERFOOD) {

                if (map.cellMap[yY][xX + 1].condition == PASSABLE ||
                    map.cellMap[yY][xX + 1].condition == FOOD ||
                    map.cellMap[yY][xX + 1].condition == SUPERFOOD) {
                    direction = predirection;
                }
            }

        if (predirection == LEFT)
            if (map.cellMap[PosY][PosX - 1].condition == PASSABLE ||
                map.cellMap[PosY][PosX - 1].condition == FOOD ||
                map.cellMap[PosY][PosX - 1].condition == SUPERFOOD) {

                if (map.cellMap[yY][xX - 1].condition == PASSABLE ||
                    map.cellMap[yY][xX - 1].condition == FOOD ||
                    map.cellMap[yY][xX - 1].condition == SUPERFOOD) {
                    direction = predirection;
                }
            }
    }

    // проверка при движении вниз
    if (direction == DOWN) {
        PosX = (int) floor((x + 23) / 24);
        PosY = (int) floor((y + 23) / 24);

        int xX = (int) floor((x + 23) / 24);
        int yY = (int) floor((y) / 24);

        if (predirection == UP) direction = UP;

        if (predirection == RIGHT)
            if (map.cellMap[PosY][PosX + 1].condition == PASSABLE ||
                map.cellMap[PosY][PosX + 1].condition == FOOD ||
                map.cellMap[PosY][PosX + 1].condition == SUPERFOOD) {

                if (map.cellMap[yY][xX + 1].condition == PASSABLE ||
                    map.cellMap[yY][xX + 1].condition == FOOD ||
                    map.cellMap[yY][xX + 1].condition == SUPERFOOD) {
                    direction = predirection;
                }
            }

        if (predirection == LEFT)
            if (map.cellMap[PosY][PosX - 1].condition == PASSABLE ||
                map.cellMap[PosY][PosX - 1].condition == FOOD ||
                map.cellMap[PosY][PosX - 1].condition == SUPERFOOD) {

                if (map.cellMap[yY][xX - 1].condition == PASSABLE ||
                    map.cellMap[yY][xX - 1].condition == FOOD ||
                    map.cellMap[yY][xX - 1].condition == SUPERFOOD) {
                    direction = predirection;
                }
            }
    }

    if (direction == LEFT) speed = 0.1;
    if (direction == RIGHT) speed = 0.1;
    if (direction == UP) speed = 0.1;
    if (direction == DOWN) speed = 0.1;
    if (direction == STAY) speed = 0;

    update(time);
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
    eat();
    resolveCollision(isCollision());
    pacman.setPosition(x, y);
}

void Charachter::eat() {
    PosX = (int) floor((x + 12) / 24);
    PosY = (int) floor((y + 12) / 24);

    if (map.cellMap[PosY][PosX].condition == FOOD ||
            map.cellMap[PosY][PosX].condition == SUPERFOOD) {
        map.map[PosY][PosX] = ' ';
        map.cellMap[PosY][PosX].condition = PASSABLE;
        scores++;
    }
}


bool Charachter::isCollision() {
    if (direction == RIGHT) {
        PosX = (int) floor((x + 24) / 24);
        PosY = (int) floor((y + 12) / 24);
        if (map.cellMap[PosY][PosX].condition == IMPASSABLE) return true;
    }
    else if (direction == DOWN) {
        PosX = (int) floor((x + 12) / 24);
        PosY = (int) floor((y + 24) / 24);
        if (map.cellMap[PosY][PosX].condition == IMPASSABLE) return true;
    }
    else if (direction == LEFT) {
        PosX = (int) floor(x / 24);
        PosY = (int) floor((y + 12) / 24);
        if (map.cellMap[PosY][PosX].condition == IMPASSABLE) return true;
    }
    else if (direction == UP) {
        PosX = (int) floor((x + 12) / 24);
        PosY = (int) floor(y / 24);
        if (map.cellMap[PosY][PosX].condition == IMPASSABLE) return true;
    }
    return false;
}

void Charachter::resolveCollision(bool f) {
    if (f) {
        if (direction == LEFT) {
            PosX = (int) floor(x / 24);
            PosY = (int) floor((y + 12) / 24);
            x = map.cellMap[PosY][PosX].uR.x; //останавливаем движение по х влево
        }
        if (direction == RIGHT) {
            PosX = (int) floor((x + 24) / 24);
            PosY = (int) floor((y + 12) / 24);
            x = map.cellMap[PosY][PosX].uL.x - 24; //останавливаем движение по х вправо
        }
        if (direction == DOWN) {
            PosX = (int) floor((x + 12) / 24);
            PosY = (int) floor((y + 24) / 24);
            y = map.cellMap[PosY][PosX].uL.y - 24; //останавливаем движение по y вниз
        }
        if (direction == UP) {
            PosX = (int) floor((x + 12) / 24);
            PosY = (int) floor(y / 24);
            y = map.cellMap[PosY][PosX].uR.y; //останавливаем движение по y вверх
        }
        direction = STAY;
    } else return;
}

float Charachter::getX() {
    return x;
}

float Charachter::getY() {
    return y;
}

Direction Charachter::getDirection() {
    return direction;
}

int Charachter::getScores() {
    return scores;
}

Charachter &Charachter::Instance() {
    static Charachter singleCharachter;
    return singleCharachter;
}

void Charachter::setScores(int s) {
    this->scores = s;
}

sf::RectangleShape Charachter::getSprite() {
    return pacman;
}