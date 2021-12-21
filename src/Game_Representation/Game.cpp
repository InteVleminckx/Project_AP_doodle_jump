#include "Game.h"

namespace representation {

    Game::Game()
    {
        m_windowWidth = 390; m_windowHeight = 580; m_gameTitle = "Doodle jump";
        m_frameRate = 60.0f;
    }

    void Game::displayFullGame() {

        representation::Window::Instance(m_windowWidth, m_windowHeight, m_gameTitle);
        logic::Stopwatch::Instance();
        logic::Random::Instance();
        logic::Camera::Instance(m_windowWidth, m_windowHeight);

        while ( Window::Instance()->isOpen())
        {
            if (m_world.getGameStatus()){
                beginGame();
                stopGame();
            }
            else
            {
                displayMenu();
            }
        }

        logic::Stopwatch::Release();
        logic::Random::Release();
        logic::Camera::Release();
        Window::Release();
    }



    void Game::beginGame() {

        logic::Stopwatch::Instance()->Reset();
        shared_ptr<logic::EntityFactory> factory = make_shared<representation::ConcreteFactory>();
        m_world.createPlayer(factory);
        m_world.createAplatform(factory, true);
        m_world.createScore(factory);
        m_world.createBG_Tile(factory, false);
        m_world.createBG_Tile(factory, true);

        while (Window::Instance()->isOpen())
        {
            logic::Stopwatch::Instance()->Tick();
            if (logic::Stopwatch::Instance()->GetDeltaTime() >= 1/m_frameRate)
            {
                Window::Instance()->getWindow()->clear();
                m_world.updateEntities();
                m_world.createAplatform(factory);
                logic::Stopwatch::Instance()->Reset();
//                cout << 1 / logic::Stopwatch::Instance()->GetDeltaTime() << endl;
                if (Window::Instance()->isPressedLeft()) m_world.movePlayerLeft();
                if (Window::Instance()->isPressedRight()) m_world.movePlayerRight();
                if (!m_world.getGameStatus()) break;
//                sf::sleep(sf::seconds(0.1f));

            }
            Window::Instance()->update(m_world.getScore());
        }
    }

    void Game::stopGame() {
        m_highScore = m_world.getScore();
        m_world.releaseObservers();
        m_world = logic::World();

        logic::Stopwatch::Release();
        logic::Random::Release();
        logic::Camera::Release();
        logic::Stopwatch::Instance();
        logic::Random::Instance();
        logic::Camera::Instance(m_windowWidth, m_windowHeight);


    }

    void Game::displayMenu() {

        sf::Font font;
        sf::Text textMen;
        sf::Text textInstr;
        sf::Text score;
        //TODO: nog met try en catch doen
        if (!font.loadFromFile("../Fonts/secrcode.ttf"))
        {
            cout << "error" << endl;
        }

        textMen.setFont(font);
        textInstr.setFont(font);
        score.setFont(font);
        textMen.setCharacterSize(45);
        textInstr.setCharacterSize(35);
        score.setCharacterSize(25);
        textMen.setFillColor(sf::Color::Green);
        textInstr.setFillColor(sf::Color::White);
        score.setFillColor(sf::Color::Green);
        textMen.setString("DOODLE JUMP");
        textInstr.setString("PRESS SPACE TO START");

        string textScore = "Highscore: " + to_string(m_highScore);
        score.setString(textScore);

        textMen.setPosition(Window::Instance()->getWindow()->getSize().x/2 - textMen.getLocalBounds().width/2, Window::Instance()->getWindow()->getSize().y/2 - textMen.getLocalBounds().height*2);
        textInstr.setPosition(Window::Instance()->getWindow()->getSize().x/2 - textInstr.getLocalBounds().width/2, Window::Instance()->getWindow()->getSize().y/2);
        score.setPosition(Window::Instance()->getWindow()->getSize().x/2 - score.getLocalBounds().width/2, Window::Instance()->getWindow()->getSize().y/2 + score.getLocalBounds().height*4);

        while (!m_world.getGameStatus() && Window::Instance()->isOpen())
        {
            if (Window::Instance()->isPressedSpace())
            {
                m_world.changeGameStatus();
                break;
            }

            Window::Instance()->getWindow()->clear();
            Window::Instance()->getWindow()->draw(textMen);
            Window::Instance()->getWindow()->draw(textInstr);
            Window::Instance()->getWindow()->draw(score);
            Window::Instance()->getWindow()->display();

            Window::Instance()->update(m_world.getScore());

        }
    }
}
