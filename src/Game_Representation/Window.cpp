//
// Created by inte on 11/23/21.
//

#include "Window.h"

namespace representation {

    Window* Window::s_instance = nullptr;

    Window* Window::Instance(int width, int height, string title) {
        if (s_instance == nullptr)
            s_instance = new Window(width, height, title);
        return s_instance;
    }

    void Window::Release() {
        delete s_instance;
        s_instance = nullptr;
    }

    Window::Window(int width, int height, string title) : m_window(sf::VideoMode(width, height), title) {
        m_isOpen = true;

        //TODO: nog met try en catch doen
        if (!m_font.loadFromFile("../Fonts/secrcode.ttf"))
        {
            cout << "error" << endl;
        }
        m_textScore.setFont(m_font);
        m_textScore.setCharacterSize(26);
        m_textScore.setFillColor(sf::Color::Black);
    }

    Window::~Window() = default;

    sf::RenderWindow *Window::getWindow() {
        return &m_window;
    }

    void Window::update(int score) {
        sf::Event event{};

        while (m_window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
            {
                m_isOpen = false;
            }
        }
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