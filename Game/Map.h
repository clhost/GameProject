#pragma once;
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/String.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "../Other/Point.h"
#include <string>

class Map {
    const static int HEIGHT_MAP = 25; // 25
    const static int WEIGHT_MAP = 25; // 25
private:
    sf::RectangleShape* rect; // текстура
    sf::Color* colorWall; // цвет стен (синий)
    sf::Color* colorSpace; // цвет пустоты (черный)
    sf::Color* colorExit; // цвет двери дома призраков (желтый)
    const std::string map[HEIGHT_MAP] = {
            "1111111111111111111111111",
            "1...........1...........1",
            "1.1111.1111.1.1111.1111.1",
            "101  1.1  1.1.1  1.1  101",
            "1.1111.1111.1.1111.1111.1",
            "1.......................1",
            "1.1111.1.1111111.1.1111.1",
            "1......1....1....1......1",
            "111111.1111 1 1111.111111",
            "     1.1         1.1     ",
            "     1.1 111e111 1.1     ",
            "111111.1 1     1 1.111111",
            "      .  1     1  .      ",
            "111111.1 1     1 1.111111",
            "     1.1 1111111 1.1     ",
            "     1.1         1.1     ",
            "111111.1 1111111 1.111111",
            "1...........1...........1",
            "1.1111.1111.1.1111.1111.1",
            "10..1....... .......1..01",
            "111.1.1.111111111.1.1.111",
            "1.....1.....1.....1.....1",
            "1.111111111.1.111111111.1",
            "1.......................1",
            "1111111111111111111111111"
    };
    void createCellMap();
public:
    Map();
    void draw(sf::RenderWindow *);
    Cell cellMap[HEIGHT_MAP][WEIGHT_MAP];
};