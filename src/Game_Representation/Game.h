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
#include <thread>


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

        /****************************************************************************************************
         * @brief Is de title van de game.
         * @type string
         * @var m_gameTitle
         ****************************************************************************************************/
        string m_gameTitle;

        /****************************************************************************************************
         * @brief Is de hoogte van de window.
         * @type int
         * @var m_windowHeight
         ****************************************************************************************************/
        int m_windowHeight;

        /****************************************************************************************************
         * @brief Is de breedre van de window.
         * @type int
         * @var m_windowWidth
         ****************************************************************************************************/
        int m_windowWidth;

        /****************************************************************************************************
         * @brief Houdt bij wat de highest score was in de game.
         * @type int
         * @var m_highScore
         ****************************************************************************************************/
        int m_highScore{};

        shared_ptr<ConcreteFactory> m_concreteFactory;

        /****************************************************************************************************
         * @function setupWorld()
         * @brief Zorgt dat de world correct wordt ingesteld.
         ****************************************************************************************************/
        void setupWorld();

        /****************************************************************************************************
         * @function displayMenu()
         * @brief Geeft het menu scherm weer. Waarop de game kan gestart worden.
         ****************************************************************************************************/
        void displayMenu();

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

        void drawViews();

    public:

        /****************************************************************************************************
         * @function Game()
         * @brief De construct van Game waar waardes voor het spel worden ingesteld.
         ****************************************************************************************************/
        Game();

        /****************************************************************************************************
         * @function displayFullGame()
         * @brief Geeft het game scherm weer. Waarbij geswitched kan worden door het menu en de game zelf.
         ****************************************************************************************************/
        void displayFullGame();

        ~Game();
    };


}


#endif //DOODLE_JUMP_GAME_H
