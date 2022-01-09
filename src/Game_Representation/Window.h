/****************************************************************************************************
 * @Naam Inte Vleminckx
 * @Studentennummer 20201844
 * @Datum 09/01/2022
 * @Class Window
 * @BaseClass none
 * @SubClasses none
 * @Namespace representation
 * @brief Is een singleton implementatie.
 ****************************************************************************************************/

#ifndef DOODLE_JUMP_WINDOW_H
#define DOODLE_JUMP_WINDOW_H

#include "../Exceptions.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

namespace representation {

class Window
{
        /****************************************************************************************************
         * @privatesection
         ****************************************************************************************************/

        /****************************************************************************************************
         * @brief Een pointer naar het window object.
         * @type static Window*
         * @var m_instance
         ****************************************************************************************************/
        static Window* s_instance;

        /****************************************************************************************************
         * @brief Is de window waar alles in getekend wordt.
         * @type sf::RenderWindow
         * @var m_window
         ****************************************************************************************************/
        sf::RenderWindow m_window;

        /****************************************************************************************************
         * @brief Geeft aan of de window geopend is of niet.
         * @type bool
         * @var m_open
         ****************************************************************************************************/
        bool m_isOpen;

        /****************************************************************************************************
         * @function Window(int width, int height, string title)
         * @brief Stelt de instellingen in voor een window en laadt de tekst font in.
         * @param width: is een int wat de breedte van de window wordt.
         * @param height: is een int wat de hoogte van de window wordt.
         * @param title: is een string wat de title van de window wordt.
         ****************************************************************************************************/
        Window(int width, int height, const string& title);

        /****************************************************************************************************
         * @publicsection
         ****************************************************************************************************/
public:
        /****************************************************************************************************
         * @function static Window* Instance(int width = 0, int height = 0, string title = "")
         * @brief Geeft de window terug, moest er nog geen bestaand wordt er 1 aangemaakt.
         * @param width: is een int wat de breedte van de window wordt.
         * @param height: is een int wat de hoogte van de window wordt.
         * @param title: is een string wat de title van de window wordt.
         * @return static Window* de window.
         ****************************************************************************************************/
        static Window* Instance(int width = 0, int height = 0, string title = "");

        /****************************************************************************************************
         * @function static void Release()
         * @brief Verwijderd de pointer naar de window.
         ****************************************************************************************************/
        static void Release();

        /****************************************************************************************************
         * @function sf::RenderWindow* getWindow()
         * @brief Geeft de renderwindow terug zodat hier aanpassing op gedaan kunnen worden.
         * @return sf::RenderWindow* is een pointer naar de RenderWindow.
         ****************************************************************************************************/
        sf::RenderWindow& getWindow();

        /****************************************************************************************************
         * @function void update(int score)
         * @brief Update de RenderWindow van de game, controleert op events.
         ****************************************************************************************************/
        void update();

        /****************************************************************************************************
         * @function bool isOpen()
         * @brief Geeft een bool terug die zegt of de window open is of niet.
         * @return een bool.
         ****************************************************************************************************/
        bool isOpen();

        /****************************************************************************************************
         * @function bool isPressedLeft()
         * @brief Controlleerd of de speler het linkerpijltje heeft ingedrukt op het toetsenbord, zoja gaat
         * deze true weergeven anders false.
         * @return een bool.
         ****************************************************************************************************/
        bool isPressedLeft();

        /****************************************************************************************************
         * @function bool isPressedRight()
         * @brief Controlleerd of de speler het rechterpijltje heeft ingedrukt op het toetsenbord, zoja gaat
         * deze true weergeven anders false.
         * @return een bool.
         ****************************************************************************************************/
        bool isPressedRight();

        /****************************************************************************************************
         * @function bool isPressedSpace()
         * @brief Controlleerd of de speler op de spatiebalk heeft gedrukt op het toetsenbord, zoja gaat
         * deze true weergeven anders false.
         * @return een bool.
         ****************************************************************************************************/
        bool isPressedSpace();

        /****************************************************************************************************
         * @privatesection
         ****************************************************************************************************/
private:
        /****************************************************************************************************
         * @function ~Window()
         * @brief Default destructor
         ****************************************************************************************************/
        ~Window();
};
} // namespace representation

#endif // DOODLE_JUMP_WINDOW_H
