#include "Inkey.h"

Inkey::Inkey(int X, int Y, int W, int H) : Enemy(
        X, Y, W, H
){ initSpeed = 0.1;
    texture.loadFromFile("/home/geek/ClionProjects/GameProject/Sprites/Ghosts.png");
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0, 72, (int) w, (int) h));
    index = 72;}

void Inkey::findPath(bool) {
    if (f) {
        algorithm.findPath(PosX, PosY, (int) floor((pacman.getX() + 12) / 24), (int) floor((pacman.getY() + 12) / 24));
        Enemy::f = false;
    }
}
