#include "Score.h"

namespace representation{


    Score::Score(shared_ptr<logic::Player_L> player) : logic::Score_L(move(player)) {
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

    void Score::update() {
        updateScore();
        m_textScore.setString(to_string(getScore()));
    }

    void Score::draw() {
        representation::Window::Instance()->getWindow().draw(m_textScore);
    }


}