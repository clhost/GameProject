#include "Game.h"

Game::Game() {
    window = new sf::RenderWindow(sf::VideoMode(600, 600), "Pacman");
    window->setPosition(sf::Vector2i(400, 400));
    blinky = std::unique_ptr<Enemy> (factory.getEnemy("blinky")); // красный
    pinky = std::unique_ptr<Enemy> (factory.getEnemy("pinky")); // розовый
    inkey = std::unique_ptr<Enemy> (factory.getEnemy("inkey")); // голубой
    clyde = std::unique_ptr<Enemy> (factory.getEnemy("clyde")); // оранжевый
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
        Animation().draw(pacman, window);

        blinky->run();
        Animation().draw(blinky, window);

        pinky->run();
        Animation().draw(pinky, window);

        inkey->run();
        Animation().draw(inkey, window);

        clyde->run();
        Animation().draw(clyde, window);

        window->display();
    }
}

Game::~Game() {
    delete window;
}
