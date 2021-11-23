//
// Created by inte on 11/23/21.
//

#include "Window.h"

namespace representation {

    Window* Window::s_instance = nullptr;

    Window* Window::Instance() {
        if (s_instance == nullptr)
            s_instance = new Window;
        return s_instance;
    }

    void Window::Release() {
        delete s_instance;
        s_instance = nullptr;
    }

    Window::Window() : m_window(sf::VideoMode(600, 600), "Doodle Jump") {
        m_isOpen = true;
    }

    Window::~Window() {}

    sf::RenderWindow *Window::getWindow() {
        return &m_window;
    }

    void Window::update() {
        sf::Event event{};

        while (m_window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
            {
                m_isOpen = false;
            }
        }
    }

    bool Window::isOpen() {
        return m_isOpen;
    }


}