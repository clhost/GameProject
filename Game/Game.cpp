#include "Game.h"

Game::Game() {
    window = new sf::RenderWindow(sf::VideoMode(600, 600), "Pacman");
    window->setPosition(sf::Vector2i(400, 400));
    menu = new Menu();
    map = new Map();
    pacman = new Charachter(240, 456, 24, 24, map);
    blinky =  new Blinky(264, 264, 24, 24, pacman, map); // красный
    pinky = new Pinky(264, 312, 24, 24, pacman, map); // розовый
    inkey = new Inkey(312, 264, 24, 24, pacman, map); // голубой
    clyde = new Clyde(312, 312, 24, 24, pacman, map); // оранжевый
    state = onResume;
}

void Game::run() {
    while (window->isOpen()) {
        sf::Event event;

        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed ||
                    sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                window->close();
        }

        // отрисовка меню
        if (state == onMenu) {
            window->clear();
            menu->display(window);
            menu->start();
            window->display();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Tab)) state = onResume;
            continue;
        }

        // отрисовка игры
        if (state == onResume) {
            window->clear();
            map->draw(window);

            pacman->run();
            pacman->draw(window);

            blinky->run();
            animation->draw(blinky, window);

            pinky->run();
            animation->draw(pinky, window);

            inkey->run();
            animation->draw(inkey, window);

            clyde->run();
            animation->draw(clyde, window);

            window->display();
            continue;
        }
    }
}