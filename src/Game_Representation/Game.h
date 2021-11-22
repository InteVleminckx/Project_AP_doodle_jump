//
// Created by inte on 11/20/21.
//

#ifndef DOODLE_JUMP_GAME_H
#define DOODLE_JUMP_GAME_H

#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

namespace representation {
    class Game {
        sf::RenderWindow* m_window;
        bool m_isRunning;

    public:

        Game(sf::RenderWindow* window);
        sf::RenderWindow* getWindow();
        bool isRunning();
        void updateWindow();


    };
}


#endif //DOODLE_JUMP_GAME_H