//
// Created by inte on 11/23/21.
//

#ifndef DOODLE_JUMP_WINDOW_H
#define DOODLE_JUMP_WINDOW_H

#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

namespace representation {
    class Window {
        static Window* s_instance;
        sf::RenderWindow m_window;
        sf::Text m_textScore;
        sf::Font m_font;
        bool m_isOpen;

    public:

        static Window* Instance(int width = 0, int height = 0, string title = "");

        static void Release();

        sf::RenderWindow* getWindow();

        void update(int score);

        bool isOpen();

        bool isPressedLeft();

        bool isPressedRight();


    private:
        Window(int width, int height, string title);

        ~Window();

    };
}


#endif //DOODLE_JUMP_WINDOW_H
