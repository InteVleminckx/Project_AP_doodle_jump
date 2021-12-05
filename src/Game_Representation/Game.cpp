#include "Game.h"

namespace representation {

    Game::Game()
    {
        logic::Stopwatch::Instance();
        representation::Window::Instance();
        logic::Random::Instance();
        m_frameRate = 60.0f;
    }

    void Game::beginGame() {

        shared_ptr<logic::EntityFactory> factory = make_shared<Representation::ConcreteFactory>();
        m_world.createPlayer(factory);
        m_world.createPlatform(factory);

        while (Window::Instance()->isOpen())
        {
            logic::Stopwatch::Instance()->Tick();
            if (logic::Stopwatch::Instance()->GetDeltaTime() >= 1/m_frameRate)
            {
                Window::Instance()->getWindow()->clear(sf::Color(122,122,122));
                m_world.updateEntities();
                Window::Instance()->getWindow()->display();
                logic::Stopwatch::Instance()->Reset();
//                cout << 1 / logic::Stopwatch::Instance()->GetDeltaTime() << endl;
                if (Window::Instance()->isPressedLeft()) m_world.movePlayerLeft();
                if (Window::Instance()->isPressedRight()) m_world.movePlayerRight();
//                sf::sleep(sf::seconds(0.1f));

            }
            Window::Instance()->update();
        }
    }

    void Game::stopGame() {
        m_world.releaseObservers();
        logic::Stopwatch::Release();
        representation::Window::Release();
        logic::Random::Release();
    }

}
