#include <SFML/Graphics/Sprite.hpp>
#include "Map.h"
#include "../Other/Point.h"

Map::Map() {
    rect = new sf::RectangleShape(sf::Vector2f(24, 24));
    colorWall = new sf::Color(63, 81, 181);
    colorSpace = new sf::Color(0, 0, 0);
    colorExit = new sf::Color(255, 245, 157);

    texture.loadFromFile("/home/geek/ClionProjects/GameProject/Sprites/points.png");
    sprite.setTexture(texture);
    createCellMap();
}

void Map::draw(sf::RenderWindow *window) {

    for (int i = 0; i < Map::HEIGHT_MAP; i++) {
        for (int j = 0; j < Map::WEIGHT_MAP; j++) {

            // стена
            if (map[i][j] == '1') { rect->setFillColor(*colorWall); }

            // бонус
            if (map[i][j] == '0') {
                sprite.setTextureRect((sf::IntRect(24, 0, 24, 24)));
                sprite.setPosition(j * 24, i * 24);
                window->draw(sprite);
                continue;
            }

            // дверь
            if (map[i][j] == 'e') { rect->setFillColor(*colorExit); }

            // пустота
            if (map[i][j] == ' ') { rect->setFillColor(*colorSpace); }

            // еда
            if (map[i][j] == '.') {
                sprite.setTextureRect((sf::IntRect(48, 0, 24, 24)));
                sprite.setPosition(j * 24, i * 24);
                window->draw(sprite);
                continue;
            }

            rect->setPosition(j * 24, i * 24);
            window->draw(*rect);
        }
    }
}

// билдится 1 раз
void Map::createCellMap() {
    for (int i = 0; i < Map::HEIGHT_MAP; i++) {
        for (int j = 0; j < Map::WEIGHT_MAP; j++) {

            // стена
            if (map[i][j] == '1') {
                /* init cells */
                cellMap[i][j] = new Cell(new Point(j * 24, i * 24), new Point(j * 24 + 24, i * 24 + 24), IMPASSABLE);
            }

            // бонус
            if (map[i][j] == '0' || map[i][j] == ' ' || map[i][j] == '.') {
                /* init cells */
                cellMap[i][j] = new Cell(new Point(j * 24, i * 24), new Point(j * 24 + 24, i * 24 + 24), SUPERFOOD);
            }

            // дверь
            if (map[i][j] == 'e') {
                /* init cells */
                cellMap[i][j] = new Cell(new Point(j * 24, i * 24), new Point(j * 24 + 24, i * 24 + 24), DOOR);
            }

            // пустота
            if (map[i][j] == ' ') {
                /* init cells */
                cellMap[i][j] = new Cell(new Point(j * 24, i * 24), new Point(j * 24 + 24, i * 24 + 24), PASSABLE);
            }

            // еда
            if (map[i][j] == '.') {
                /* init cells */
                cellMap[i][j] = new Cell(new Point(j * 24, i * 24), new Point(j * 24 + 24, i * 24 + 24), FOOD);
            }
        }

    }
}

Map &Map::Instance() {
    static Map singleMap;
    return singleMap;
}
