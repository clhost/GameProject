#include <SFML/Graphics/Sprite.hpp>
#include "Map.h"
#include "Point.h"

Map::Map() {
    rect = new sf::RectangleShape(sf::Vector2f(24, 24));
    colorWall = new sf::Color(63, 81, 181);
    colorSpace = new sf::Color(0, 0, 0);
    colorExit = new sf::Color(255, 245, 157);
}

void Map::draw(sf::RenderWindow *window) {

    /** пока что так **/
    for (int i = 0; i < Map::HEIGHT_MAP; i++) {
        for (int j = 0; j < Map::WEIGHT_MAP; j++) {

            /* стена */
            if (map[i][j] == '1') {
                rect->setFillColor(*colorWall);

                /* init cells */
                cellMap[i][j].uL.x = j * 24;
                cellMap[i][j].uL.y = i * 24;
                cellMap[i][j].uR.x = cellMap[i][j].uL.x + 24;
                cellMap[i][j].uR.y = cellMap[i][j].uL.y + 24;
                cellMap[i][j].condition = IMPASSABLE;

            }

            /* бонус */
            if (map[i][j] == '0' || map[i][j] == ' ' || map[i][j] == '.') {
                rect->setFillColor(*colorSpace);

                /* init cells */
                cellMap[i][j].uL.x = j * 24;
                cellMap[i][j].uL.y = i * 24;
                cellMap[i][j].uR.x = cellMap[i][j].uL.x + 24;
                cellMap[i][j].uR.y = cellMap[i][j].uL.y + 24;
                cellMap[i][j].condition = PASSABLE;
            }

            /* дверь */
            if (map[i][j] == 'e') {
                rect->setFillColor(*colorExit);

                /* init cells */
                cellMap[i][j].uL.x = j * 24;
                cellMap[i][j].uL.y = i * 24;
                cellMap[i][j].uR.x = cellMap[i][j].uL.x + 24;
                cellMap[i][j].uR.y = cellMap[i][j].uL.y + 24;
                cellMap[i][j].condition = DOOR;
            }

            /* пустота */
            if (map[i][j] == ' ') {
                rect->setFillColor(*colorSpace);

                /* init cells */
                cellMap[i][j].uL.x = j * 24;
                cellMap[i][j].uL.y = i * 24;
                cellMap[i][j].uR.x = cellMap[i][j].uL.x + 24;
                cellMap[i][j].uR.y = cellMap[i][j].uL.y + 24;
                cellMap[i][j].condition = PASSABLE;
            }

            /* еда */
            if (map[i][j] == '.') {
                rect->setFillColor(*colorSpace);

                /* init cells */
                cellMap[i][j].uL.x = j * 24;
                cellMap[i][j].uL.y = i * 24;
                cellMap[i][j].uR.x = cellMap[i][j].uL.x + 24;
                cellMap[i][j].uR.y = cellMap[i][j].uL.y + 24;
                cellMap[i][j].condition = PASSABLE;
            }

            rect->setPosition(j*24, i*24);
            window->draw(*rect);
        }
    }
}
