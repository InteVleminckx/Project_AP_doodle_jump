/****************************************************************************************************
 * @author Inte Vleminckx
 * @Studentennummer 20201844
 * @Datum
 * @Class Game
 * @BaseClass none
 * @SubClasses none
 * @Namespace representation
 * @brief Bevat de game loop.
 ****************************************************************************************************/

#ifndef DOODLE_JUMP_GAME_H
#define DOODLE_JUMP_GAME_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "../Logic_libary/World.h"
#include "Window.h"
#include "ConcreteFactory.h"
#include "../Logic_libary/Random.h"
#include "../Logic_libary/Camera.h"

using namespace std;

namespace representation {
    class Game {

        /****************************************************************************************************
         * @brief Is de world die het spel regelt.
         * @type logic::World
         * @var m_world
         ****************************************************************************************************/
        logic::World m_world;

        /****************************************************************************************************
         * @brief Is de maximale frameRate die het spel mag bevatten.
         * @type float
         * @var m_frameRate
         ****************************************************************************************************/
        float m_frameRate;

    public:

        /****************************************************************************************************
         * @function Game()
         * @brief De construct van Game waar waardes voor het spel worden ingesteld.
         ****************************************************************************************************/
        Game();

        /****************************************************************************************************
         * @function beginGame()
         * @brief Start het spel en bevat de main loop van de game.
         ****************************************************************************************************/
        void beginGame();

        /****************************************************************************************************
         * @function stopGame()
         * @brief Stopt het spel en verwijderd alle pointers die aangemaakt zijn.
         ****************************************************************************************************/
        void stopGame();
    };
}


#endif //DOODLE_JUMP_GAME_H
