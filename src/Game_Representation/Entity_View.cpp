//
// Created by inte on 11/18/21.
//

#include "Entity_View.h"


namespace representation {

    Entity_View::Entity_View() = default;

    Entity_View::Entity_View(shared_ptr<logic::Subject> &subject){m_subject = subject;}

    void Entity_View::createSprite(const string& filepath)
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

    sf::Sprite Entity_View::getSprite() { return m_modelSprite; }

}

