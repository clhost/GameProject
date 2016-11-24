#include "Game.h"

Game::Game() {
    window = new sf::RenderWindow(sf::VideoMode(600, 600), "Pacman");
    window->setPosition(sf::Vector2i(400, 400));
    map = new Map();
    pacman = new Charachter(264, 456, 24, 24, map); // 264, 456
    blinky = new Enemy(264, 264, new sf::Color(239, 83, 80)); // красный
    pinky = new Enemy(264, 312, new sf::Color(236, 64, 122)); // розовый
    inkey = new Enemy(312, 264, new sf::Color(41, 182, 246)); // голубой
    clyde = new Enemy(312, 312, new sf::Color(255, 152, 0)); // оранжевый
    state = onMenu;
}

void Game::run() {
    while (window->isOpen()) {
        sf::Event event;

        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed ||
                    sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                window->close();
        }

        /* отрисовка меню */
        if (state == onMenu) {
            window->clear();
            window->display();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Tab)) state = onResume;
        }

        /* отрисовка игры */
        if (state == onResume) {
            window->clear();
            map->draw(window);
            pacman->run();
            pacman->draw(window);
            blinky->draw(window);
            pinky->draw(window);
            inkey->draw(window);
            clyde->draw(window);
            window->display();
        }
    }
}