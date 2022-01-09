#include "Game.h"

namespace representation {

Game::Game()
{
        m_windowWidth = 390;
        m_windowHeight = 580;
        m_gameTitle = "Doodle jump";
        m_frameRate = 60.0f;
}

void Game::setupWorld()
{
        m_concreteFactory = move(make_shared<representation::ConcreteFactory>());
        shared_ptr<logic::EntityFactory> factory = m_concreteFactory;
        m_world.setFactory(factory);
        m_world.setupWorld();
}

void Game::displayFullGame()
{

        // Camera en window zijn nodig voor het opzetten en displayen van de logic world.
        representation::Window::Instance(m_windowWidth, m_windowHeight, m_gameTitle);

        while (Window::Instance()->isOpen()) {
                logic::Camera::Instance(m_windowWidth, m_windowHeight);
                if (m_world.getGameStatus()) {
                        this->setupWorld();
                        beginGame();
                        stopGame();
                } else
                        displayMenu();
        }

        logic::Random::Release();
        logic::Stopwatch::Release();
        logic::Camera::Release();
        Window::Release();
}

void Game::beginGame()
{

        while (Window::Instance()->isOpen()) {
                logic::Stopwatch::Instance()->Tick();
                if (logic::Stopwatch::Instance()->GetDeltaTime() < 1 / m_frameRate) {
                        chrono::milliseconds ms = chrono::milliseconds(
                            (int)(((1 / m_frameRate) - logic::Stopwatch::Instance()->GetDeltaTime()) * 1000));
                        this_thread::sleep_for(ms);
                }

                logic::Stopwatch::Instance()->Tick();
                logic::Stopwatch::Instance()->Reset();

                m_world.updateWorld();
                Window::Instance()->getWindow().clear();
                drawViews();
                if (!m_world.getGameStatus())
                        break;
                Window::Instance()->update();
        }
}

void Game::stopGame()
{
        m_world.releaseObservers();
        m_world.saveScore();
        m_world = logic::World();

        // Omdat deze enkel nodig zijn in het logic gedeelte.
        // Gaan we deze momenteel releasen want deze zijn niet meer nodig in het menu.
        logic::Stopwatch::Release();
        logic::Random::Release();
        logic::Camera::Release();
}

void Game::displayMenu()
{

        sf::Text textMen;
        sf::Text textInstr;
        sf::Text Highscore;
        sf::Text Prevscore;

        bool fontLoaded = true;

        string fontPath = "../Fonts/secrcode.ttf";
        sf::Font font;

        try {
                if (!font.loadFromFile(fontPath))
                        throw InputFontException();
        } catch (InputFontException& exception) {
                cout << exception.what() << fontPath << endl;
                fontLoaded = false;
        }

        textMen.setFont(font);
        textInstr.setFont(font);
        Highscore.setFont(font);
        Prevscore.setFont(font);
        textMen.setCharacterSize(45);
        textInstr.setCharacterSize(35);
        Highscore.setCharacterSize(25);
        Prevscore.setCharacterSize(25);
        textMen.setFillColor(sf::Color::Green);
        textInstr.setFillColor(sf::Color::White);
        Highscore.setFillColor(sf::Color::Green);
        textMen.setString("DOODLE JUMP");
        textInstr.setString("PRESS SPACE TO START");

        string texthighScore = "Highscore: " + to_string(m_world.getHighScore());
        string textprevScore = "Previous score: " + to_string(m_world.getScore());
        Highscore.setString(texthighScore);
        Prevscore.setString(textprevScore);

        textMen.setPosition((float)Window::Instance()->getWindow().getSize().x / 2 - textMen.getLocalBounds().width / 2,
                            (float)Window::Instance()->getWindow().getSize().y / 2 -
                                textMen.getLocalBounds().height * 2);
        textInstr.setPosition((float)Window::Instance()->getWindow().getSize().x / 2 -
                                  textInstr.getLocalBounds().width / 2,
                              (float)Window::Instance()->getWindow().getSize().y / 2);
        Highscore.setPosition(
            (float)Window::Instance()->getWindow().getSize().x / 2 - Highscore.getLocalBounds().width / 2,
            (float)Window::Instance()->getWindow().getSize().y / 2 + Highscore.getLocalBounds().height * 4);
        Prevscore.setPosition(
            (float)Window::Instance()->getWindow().getSize().x / 2 - Prevscore.getLocalBounds().width / 2,
            (float)Window::Instance()->getWindow().getSize().y / 2 + Prevscore.getLocalBounds().height * 8);

        while (!m_world.getGameStatus() && Window::Instance()->isOpen()) {
                if (Window::Instance()->isPressedSpace()) {
                        m_world.changeGameStatus();
                        break;
                }

                if (fontLoaded) {
                        Window::Instance()->getWindow().clear();
                        Window::Instance()->getWindow().draw(textMen);
                        Window::Instance()->getWindow().draw(textInstr);
                        Window::Instance()->getWindow().draw(Highscore);
                        Window::Instance()->getWindow().draw(Prevscore);
                        Window::Instance()->getWindow().display();
                }
                Window::Instance()->update();
        }
}

void Game::drawViews()
{

        for (int i = (int)m_concreteFactory->getBG_Tiles().size() - 1; i >= 0; --i) {

                if (m_concreteFactory->getBG_Tiles()[i].use_count() == 1) {
                        m_concreteFactory->getBG_Tiles().erase(m_concreteFactory->getBG_Tiles().begin() + i);
                } else {
                        m_concreteFactory->getBG_Tiles()[i]->draw();
                }
        }

        for (int i = (int)m_concreteFactory->getPlatforms().size() - 1; i >= 0; --i) {

                if (m_concreteFactory->getPlatforms()[i].use_count() == 1) {
                        m_concreteFactory->getPlatforms().erase(m_concreteFactory->getPlatforms().begin() + i);
                } else {
                        m_concreteFactory->getPlatforms()[i]->draw();
                }
        }

        for (int i = (int)m_concreteFactory->getBonussen().size() - 1; i >= 0; --i) {

                if (m_concreteFactory->getBonussen()[i].use_count() == 1) {
                        m_concreteFactory->getBonussen().erase(m_concreteFactory->getBonussen().begin() + i);
                } else {
                        m_concreteFactory->getBonussen()[i]->draw();
                }
        }

        if (m_concreteFactory->getScore().use_count() == 1) {
                m_concreteFactory->getScore().reset();
        } else {
                m_concreteFactory->getScore()->draw();
        }

        if (m_concreteFactory->getPlayer().use_count() == 1) {
                m_concreteFactory->getPlayer().reset();
        } else {
                m_concreteFactory->getPlayer()->draw();
        }
}

Game::~Game() = default;
} // namespace representation
