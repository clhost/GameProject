#include "Animation.h"

void Animation::draw(Enemy *object, sf::RenderWindow *window) {
    if (object->getDirection() == RIGHT) {
        object->setSprite(sf::IntRect(0, object->getIndex(), 24, 24));
    }
    if (object->getDirection() == LEFT) {
        object->setSprite(sf::IntRect(24, object->getIndex(), 24, 24));
    }
    window->draw(object->getSprite());
}
