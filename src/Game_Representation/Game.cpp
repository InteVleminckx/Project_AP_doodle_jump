#include "Game.h"

namespace representation {

    Game::Game()
    {
        m_windowWidth = 390; m_windowHeight = 580; m_gameTitle = "Doodle jump";
        m_frameRate = 60.0f;
    }

    void Game::setupWorld() {
        shared_ptr<logic::EntityFactory> factory = move(make_shared<representation::ConcreteFactory>());
        m_world.setFactory(factory);
        m_world.setupWorld();
    }


    void Game::displayFullGame() {

        //Camera en window zijn nodig voor het opzetten en displayen van de logic world.
        representation::Window::Instance(m_windowWidth, m_windowHeight, m_gameTitle);


        while ( Window::Instance()->isOpen())
        {
            logic::Camera::Instance(m_windowWidth, m_windowHeight);
            if (m_world.getGameStatus()){
                this->setupWorld();
                beginGame();
                stopGame();
            }
            else displayMenu();
        }

        logic::Random::Release();
        logic::Stopwatch::Release();
        logic::Camera::Release();
        Window::Release();

    }

    void Game::beginGame() {
        while (Window::Instance()->isOpen())
        {
            logic::Stopwatch::Instance()->Tick();
            if (logic::Stopwatch::Instance()->GetDeltaTime() >= 1/m_frameRate)
            {
                Window::Instance()->getWindow().clear();
                m_world.updateWorld();

                if (!m_world.getGameStatus()) break;

            }
            Window::Instance()->update(m_world.getScore(), true);
        }
    }

    void Game::stopGame() {
        if (m_highScore < m_world.getScore()) m_highScore = m_world.getScore();
        m_world.releaseObservers();
        m_world = logic::World();

        //Omdat deze enkel nodig zijn in het logic gedeelte.
        //Gaan we deze momenteel releasen want deze zijn niet meer nodig in het menu.
        logic::Stopwatch::Release();
        logic::Random::Release();
        logic::Camera::Release();
    }

    void Game::displayMenu() {

        sf::Font font;
        sf::Text textMen;
        sf::Text textInstr;
        sf::Text score;
        string fontPath = "../Fonts/secrcode.ttf";

        bool fontLoaded = true;

        try {
            if (!font.loadFromFile(fontPath))
                throw InputFontException();
        }
        catch (InputFontException& exception) {
            cout << exception.what() << fontPath << endl;
            fontLoaded = false;
        }

        if (fontLoaded)
        {
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

            textMen.setPosition((float) Window::Instance()->getWindow().getSize().x/2 - textMen.getLocalBounds().width/2, (float) Window::Instance()->getWindow().getSize().y/2 - textMen.getLocalBounds().height*2);
            textInstr.setPosition((float) Window::Instance()->getWindow().getSize().x/2 - textInstr.getLocalBounds().width/2, (float) Window::Instance()->getWindow().getSize().y/2);
            score.setPosition((float) Window::Instance()->getWindow().getSize().x/2 - score.getLocalBounds().width/2, (float) Window::Instance()->getWindow().getSize().y/2 + score.getLocalBounds().height*4);
        }

        while (!m_world.getGameStatus() && Window::Instance()->isOpen())
        {
            if (Window::Instance()->isPressedSpace())
            {
                m_world.changeGameStatus();
                break;
            }

            if (fontLoaded)
            {
                Window::Instance()->getWindow().clear();
                Window::Instance()->getWindow().draw(textMen);
                Window::Instance()->getWindow().draw(textInstr);
                Window::Instance()->getWindow().draw(score);
                Window::Instance()->getWindow().display();
            }
            Window::Instance()->update(m_world.getScore(), false);

        }
    }

    Game::~Game() {cout << "delete Game" << endl; }
}
