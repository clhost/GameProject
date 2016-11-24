#ifndef GAMEPROJECT_MENU_H
#define GAMEPROJECT_MENU_H


#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

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
public:
    Menu();
    void display();
};


#endif //GAMEPROJECT_MENU_H