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

    void EntityView::update() {
        //TODO: dit moet nog verplaatst worden naar logic
        projectedPixels pixels = logic::Camera::Instance()->projectToPixel(m_subject->getX(), m_subject->getY());

//        if (logic::Camera::Instance()->visibleInView(pixels.x, pixels.y))
//        {
            //TODO: enkel dit dan nog laten staan
            m_modelSprite.setPosition(pixels.x, pixels.y - m_height);
            representation::Window::Instance()->getWindow()->draw(m_modelSprite);
//        }

        //TODO: verwijder observer als deze niet meer visible is

    }

}

