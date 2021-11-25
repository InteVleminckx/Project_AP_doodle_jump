//
// Created by inte on 11/20/21.
//

#include "Game.h"

#include <memory>

namespace representation {

    Game::Game()
    {
        logic::Stopwatch::Instance();
        representation::Window::Instance();
        m_frameRate = 60.0f;
    }

    void Game::beginGame() {

        shared_ptr<logic::EntityFactory> playerFactory = make_shared<PlayerFactory>();
        m_world.createPlayer(playerFactory);

        while (Window::Instance()->isOpen())
        {
            logic::Stopwatch::Instance()->Tick();
            if (logic::Stopwatch::Instance()->GetDeltaTime() >= 1/m_frameRate)
            {
                Window::Instance()->getWindow()->clear(sf::Color::White);
                m_world.updateEntities();
                Window::Instance()->getWindow()->display();
                logic::Stopwatch::Instance()->Reset();
//            cout << 1 / stopwatch->GetDeltaTime() << endl;

            }
            Window::Instance()->update();
        }


    }

    void Game::stopGame() {
        m_world.releaseObservers();
        logic::Stopwatch::Release();
        representation::Window::Release();
    }

}
