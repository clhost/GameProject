#include "Animation.h"

void Animation::draw(std::unique_ptr<Enemy>& object, sf::RenderWindow *window) {
    if (object->getDirection() == RIGHT) {
        object->setSprite(sf::IntRect(0, object->getIndex(), 24, 24));
    }
    if (object->getDirection() == LEFT) {
        object->setSprite(sf::IntRect(24, object->getIndex(), 24, 24));
    }
    window->draw(object->getSprite());
}

void Animation::draw(Charachter& pacman, sf::RenderWindow *window) {
    window->draw(pacman.getSprite());
}
