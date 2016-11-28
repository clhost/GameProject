#include "Enemy.h"

Enemy::Enemy(int x, int y, sf::Color *col) {
    ghost = new sf::RectangleShape(sf::Vector2f(24, 24));
    //color = new sf::Color(255, 235, 59);
    color = col;
    ghost->setFillColor(*color);
    ghost->setPosition(x, y);
}

void Enemy::run() {

}

void Enemy::draw(sf::RenderWindow* window) {
    window->draw(*ghost);
}