#ifndef GAMEPROJECT_MENU_H
#define GAMEPROJECT_MENU_H

#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class Menu {
    /*sf::Texture* startGame;
    sf::Texture* about;
    sf::Texture* highScores;
    sf::Texture* exit;*/
    sf::RectangleShape* startGame;
    sf::RectangleShape* about;
    sf::RectangleShape* highScores;
    sf::RectangleShape* exit;
    sf::Color* color;
    sf::Color* defaultColor;
public:
    Menu();
    void display(sf::RenderWindow*);
    void start();
};


#endif //GAMEPROJECT_MENU_H