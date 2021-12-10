#include "Game.h"

namespace representation {

    Game::Game()
    {
        int windowWidth = 390; int windowHeight = 580; string gameTitle = "Doodle jump";
        m_frameRate = 60.0f;
        logic::Stopwatch::Instance();
        representation::Window::Instance(windowWidth, windowHeight, gameTitle);
        logic::Random::Instance();
        logic::Camera::Instance(windowWidth, windowHeight);
    }

    void Game::beginGame() {

        shared_ptr<logic::EntityFactory> factory = make_shared<Representation::ConcreteFactory>();
        m_world.createPlayer(factory);
        m_world.createPlatform(factory, -1.f);
        m_world.createPlatform(factory, -.7f);
        m_world.createPlatform(factory, -0.4f);
        m_world.createPlatform(factory, -.1f);
        m_world.createPlatform(factory, .2f);
        m_world.createPlatform(factory, .5f);
        m_world.createPlatform(factory, .8f);
        m_world.createPlatform(factory, 1.1f);
        m_world.createPlatform(factory, 1.4f);
        m_world.createPlatform(factory, 1.7f);
        m_world.createPlatform(factory, 2.f);
        m_world.createPlatform(factory, 2.3f);
        m_world.createPlatform(factory, 2.6f);

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
        logic::Camera::Release();
    }

}
