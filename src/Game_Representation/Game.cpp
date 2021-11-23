//
// Created by inte on 11/20/21.
//

#include "Game.h"

namespace representation {

    Game::Game() : m_window(sf::VideoMode(600,600), "Doodle Jump"){
        m_isRunning = true;
    }

    sf::RenderWindow *Game::getWindow() {
        return &m_window;
    }

    bool Game::isRunning() {
        return m_isRunning;
    }

    void Game::updateWindow() {

        sf::Event event{};

        while (m_window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) m_isRunning = false;
        }

    }

}