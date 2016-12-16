#include "Game.h"

Game::Game() {
    window = new sf::RenderWindow(sf::VideoMode(600, 600), "Pacman");
    window->setPosition(sf::Vector2i(400, 400));
    factory = new GhostFactory();
    blinky =  factory->getEnemy("blinky"); // красный
    pinky = factory->getEnemy("pinky"); // розовый
    inkey = factory->getEnemy("inkey"); // голубой
    clyde = factory->getEnemy("clyde"); // оранжевый
}

void Game::run() {
    while (window->isOpen()) {
        sf::Event event;

        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed ||
                    sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                window->close();
        }

        if (pacman.getScores() == 208) {
            window->close();
        }

        // отрисовка игры
        window->clear();
        map.draw(window);

        pacman.run();
        pacman.draw(window);

        blinky->run();
        animation->draw(blinky, window);

        pinky->run();
        animation->draw(pinky, window);

        inkey->run();
        animation->draw(inkey, window);

        clyde->run();
        animation->draw(clyde, window);

        window->display();
    }
}
