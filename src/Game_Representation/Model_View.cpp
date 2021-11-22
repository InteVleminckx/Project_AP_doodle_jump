//
// Created by inte on 11/18/21.
//

#include "Model_View.h"


namespace representation {

    Model_View::Model_View() = default;

    Model_View::Model_View(logic::Subject &subject) {m_subject = subject;}

    void Model_View::createSprite(const string& filepath)
    {

        try {
            if (!m_modelTexture.loadFromFile(filepath))
                throw InputException();
        }
        catch (InputException& exception) {
            cout << exception.what() << filepath;
            exit(1);
        }

        this->m_modelSprite.setTexture(m_modelTexture);
    }

    sf::Sprite Model_View::getSprite() { return m_modelSprite; }

}

