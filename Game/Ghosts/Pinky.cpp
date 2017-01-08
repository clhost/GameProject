#include "Pinky.h"

Pinky::Pinky(int X, int Y, int W, int H) : Enemy(
        X, Y, W, H
){ initSpeed = 0.085;
    texture.loadFromFile("/home/geek/ClionProjects/GameProject/Sprites/Ghosts.png");
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0, 24, (int) w, (int) h));
    index = 24; }

void Pinky::findPath(bool f) {

    if (f) {
        dir = pacman.getDirection();

        if (dir == LEFT) {
            pX = (int) floor((pacman.getX() + 12) / 24) - 2;
            pY = (int) floor((pacman.getY() + 12) / 24);

            if (pX >= 1 && pX <= 23 &&
                    map.cellMap[pY][pX].condition == PASSABLE) {
                algorithm.findPath(PosX, PosY, pX, pY);
            } else {
                algorithm.findPath(PosX, PosY,
                                   (int) floor((pacman.getX() + 12) / 24),
                                   (int) floor((pacman.getY() + 12) / 24));
            }
        }

        if (dir == RIGHT) {
            pX = (int) floor((pacman.getX() + 12) / 24) + 2;
            pY = (int) floor((pacman.getY() + 12) / 24);

            if (pX >= 1 && pX <= 23 &&
                map.cellMap[pY][pX].condition == PASSABLE) {
                algorithm.findPath(PosX, PosY, pX, pY);
            } else {
                algorithm.findPath(PosX, PosY,
                                   (int) floor((pacman.getX() + 12) / 24),
                                   (int) floor((pacman.getY() + 12) / 24));
            }
        }

        if (dir == UP) {
            pX = (int) floor((pacman.getX() + 12) / 24);
            pY = (int) floor((pacman.getY() + 12) / 24) - 2;

            if (pY >= 1 && pY <= 23 &&
                map.cellMap[pY][pX].condition == PASSABLE) {
                algorithm.findPath(PosX, PosY, pX, pY);
            } else {
                algorithm.findPath(PosX, PosY,
                                   (int) floor((pacman.getX() + 12) / 24),
                                   (int) floor((pacman.getY() + 12) / 24));
            }
        }

        if (dir == DOWN) {
            pX = (int) floor((pacman.getX() + 12) / 24);
            pY = (int) floor((pacman.getY() + 12) / 24) + 2;

            if (pY >= 1 && pY <= 23 &&
                map.cellMap[pY][pX].condition == PASSABLE) {
                algorithm.findPath(PosX, PosY, pX, pY);
            } else {
                algorithm.findPath(PosX, PosY,
                                   (int) floor((pacman.getX() + 12) / 24),
                                   (int) floor((pacman.getY() + 12) / 24));
            }
        }

        if (dir == STAY) {
            algorithm.findPath(PosX, PosY,
                               (int) floor((pacman.getX() + 12) / 24),
                               (int) floor((pacman.getY() + 12) / 24));
        }

        Enemy::f = false;
    }
}
