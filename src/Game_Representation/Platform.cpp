#include "Platform.h"

namespace representation {

    Platform::Platform() = default;

    Platform::Platform(shared_ptr<logic::Subject>& subject) {
        m_subject = subject;
        m_width = Window::Instance()->getWindow()->getSize().x*subject->getWidth();
        m_height = Window::Instance()->getWindow()->getSize().y*subject->getHeight();
    }

    void Platform::update() {

        float x = Window::Instance()->getWindow()->getSize().x/2 + (Window::Instance()->getWindow()->getSize().x/2 * m_subject->getX()) - m_width/2;
        float y = Window::Instance()->getWindow()->getSize().y/2 + (Window::Instance()->getWindow()->getSize().y/2 * (-m_subject->getY())) - m_height /2;
        m_modelSprite.setPosition(x, y);
        representation::Window::Instance()->getWindow()->draw(m_modelSprite);
    }

    Platform_static::Platform_static(shared_ptr<logic::Subject>& subject) : Platform(subject){
        createSprite("../Sprites/Static_platforms.png");
        m_modelSprite.scale(m_width/m_modelTexture.getSize().x, m_height/m_modelTexture.getSize().y);
    }

    Platform_vertical::Platform_vertical(shared_ptr<logic::Subject>& subject) : Platform(subject) {

        createSprite("../Sprites/Vertical_platforms.png");
        m_modelSprite.scale(m_width/m_modelTexture.getSize().x, m_height/m_modelTexture.getSize().y);
    }

    Platform_horizontal::Platform_horizontal(shared_ptr<logic::Subject>& subject) : Platform(subject) {
        createSprite("../Sprites/Horizontal_platforms.png");
        m_modelSprite.scale(m_width/m_modelTexture.getSize().x, m_height/m_modelTexture.getSize().y);
    }

    Platform_temporary::Platform_temporary(shared_ptr<logic::Subject>& subject) : Platform(subject) {
        createSprite("../Sprites/Temporary_platforms.png");
        m_modelSprite.scale(m_width/m_modelTexture.getSize().x, m_height/m_modelTexture.getSize().y);
    }
}