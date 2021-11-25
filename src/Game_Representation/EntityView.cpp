//
// Created by inte on 11/18/21.
//

#include "EntityView.h"


namespace representation {

    EntityView::EntityView() = default;

    EntityView::EntityView(shared_ptr<logic::Subject> &subject){m_subject = subject;}

    void EntityView::createSprite(const string& filepath)
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

    sf::Sprite EntityView::getSprite() { return m_modelSprite; }

}

