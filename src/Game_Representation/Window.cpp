//
// Created by inte on 11/23/21.
//

#include "Window.h"

namespace representation {

    Window* Window::s_instance = nullptr;

    Window* Window::Instance(int width, int height, string title) {

//        static Window instance(width, height, title);
//        return instance;
        if (s_instance == nullptr)
            s_instance = new Window(width, height, title);
        return s_instance;
    }

    void Window::Release() {
        delete s_instance;
        s_instance = nullptr;
    }

    Window::Window(int width, int height, const string& title) : m_window(sf::VideoMode( width,  height), title) {
        m_isOpen = true;

        string fontPath = "../Fonts/secrcode.ttf";

        bool fontLoaded = true;

        try {
            if (!m_font.loadFromFile(fontPath))
                throw InputFontException();
        }
        catch (InputFontException& exception) {
            cout << exception.what() << fontPath << endl;
            fontLoaded = false;
        }

        if (fontLoaded)
        {
            m_textScore.setFont(m_font);
            m_textScore.setCharacterSize(26);
            m_textScore.setFillColor(sf::Color::Black);
        }

    }

    Window::~Window() {cout << "delete Window" << endl;};

    sf::RenderWindow& Window::getWindow() {
        return m_window;
    }

    void Window::update(int score, bool inGame) {
        sf::Event event{};

        while (m_window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
            {
                m_isOpen = false;
            }
        }

        if (!inGame) return;

        m_textScore.setString(to_string(score));
        m_window.draw(m_textScore);
        m_window.display();

    }

    bool Window::isOpen() {
        return m_isOpen;
    }

    bool Window::isPressedLeft() {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) return true;
        return false;
    }

    bool Window::isPressedRight() {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) return true;
        return false;
    }

    bool Window::isPressedSpace() {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) return true;
        return false;
    }


}