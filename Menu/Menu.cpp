#include <SFML/Window/Keyboard.hpp>
#include <iostream>
#include "Menu.h"

void Menu::display(sf::RenderWindow* window) {
    startGame->setPosition(200, 400);
    about->setPosition(200, 448);
    highScores->setPosition(200, 496);
    exit->setPosition(200, 544);
    window->draw(*startGame);
    window->draw(*about);
    window->draw(*highScores);
    window->draw(*exit);
}

Menu::Menu() {
    startGame = new sf::RectangleShape(sf::Vector2f(200, 24));
    about = new sf::RectangleShape(sf::Vector2f(200, 24));
    highScores = new sf::RectangleShape(sf::Vector2f(200, 24));
    exit = new sf::RectangleShape(sf::Vector2f(200, 24));
    color = new sf::Color(255, 235, 59);
    defaultColor = new sf::Color(255, 255, 255);
    startGame->setFillColor(*color);
}

void Menu::start() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        if (startGame->getFillColor() == *color) {
            startGame->setFillColor(*defaultColor);
            about->setFillColor(*color);
            return;
        }
        if (about->getFillColor() == *color) {
            about->setFillColor(*defaultColor);
            highScores->setFillColor(*color);
            return;
        }
        if (highScores->getFillColor() == *color) {
            highScores->setFillColor(*defaultColor);
            exit->setFillColor(*color);
            return;
        }
        if (exit->getFillColor() == *color) {
            exit->setFillColor(*defaultColor);
            startGame->setFillColor(*color);
            return;
        }
    }
}
