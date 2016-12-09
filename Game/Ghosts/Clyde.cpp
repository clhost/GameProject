#include <iostream>
#include "Clyde.h"

Clyde::Clyde(int X, int Y, int W, int H, Charachter* charachter, Map* map) : Enemy(
        X, Y, W, H, charachter, map
){ initSpeed = 0.1;
    texture.loadFromFile("/home/geek/ClionProjects/GameProject/Sprites/Ghosts.png");
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0, 48, (int) w, (int) h));
    index = 48;}

void Clyde::findPath(bool f) {

    if (f) {

        srand((unsigned int) std::time(NULL));

        if (abs((int) floor((pacman->getX() / 24)) - PosX) < 5 &&
            abs((int) floor((pacman->getY() / 24)) - PosY) < 5) {
            initSpeed = 0.090;
            algorithm.findPath(PosX, PosY, (int) floor((pacman->getX() + 12) / 24), (int) floor((pacman->getY() + 12) / 24));
        } else {

            initSpeed = 0.1;
            int t = 0 + rand() % 4;
            int k = 1 + rand() % 3;

            if (PosX >= 12 && PosY <= 12) {
                if (k == 3) {
                    pX = first[t].x;
                    pY = first[t].y;
                }
                if (k == 1) {
                    pX = fourth[t].x;
                    pY = fourth[t].y;
                }
                if (k == 2) {
                    pX = third[t].x;
                    pY = third[t].y;
                }
                algorithm.findPath(PosX, PosY, pX, pY);
                Enemy::f = false;
            }

            if (PosX >= 12 && PosY >= 12) {
                if (k == 3) {
                    pX = second[t].x;
                    pY = second[t].y;
                }
                if (k == 1) {
                    pX = first[t].x;
                    pY = first[t].y;
                }
                if (k == 2) {
                    pX = fourth[t].x;
                    pY = fourth[t].y;
                }
                algorithm.findPath(PosX, PosY, pX, pY);
                Enemy::f = false;
            }

            if (PosX <= 12 && PosY >= 12) {
                if (k == 3) {
                    pX = third[t].x;
                    pY = third[t].y;
                }
                if (k == 1) {
                    pX = second[t].x;
                    pY = second[t].y;
                }
                if (k == 2) {
                    pX = first[t].x;
                    pY = first[t].y;
                }
                algorithm.findPath(PosX, PosY, pX, pY);
                Enemy::f = false;
            }

            if (PosX <= 12 && PosY <= 12) {
                if (k == 3) {
                    pX = fourth[t].x;
                    pY = fourth[t].y;
                }
                if (k == 1) {
                    pX = third[t].x;
                    pY = third[t].y;
                }
                if (k == 2) {
                    pX = second[t].x;
                    pY = second[t].y;
                }
                algorithm.findPath(PosX, PosY, pX, pY);
                Enemy::f = false;
            }
        }
        Enemy::f = false;
    }
}