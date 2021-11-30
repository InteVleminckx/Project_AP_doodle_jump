#include "Platform.h"

namespace representation {

    Platform::Platform() = default;

    Platform::Platform(shared_ptr<logic::Subject>& subject) {m_subject = subject;}

    void Platform::update(float x, float y) {

        m_modelSprite.setPosition(x, y);
        Window::Instance()->getWindow()->draw(m_modelSprite);
    }

    Platform_static::Platform_static(shared_ptr<logic::Subject>& subject) {
        m_width = Window::Instance()->getWindow()->getSize().x/8;
        m_height = Window::Instance()->getWindow()->getSize().y/40;
        m_subject = subject;
        createSprite("../Sprites/Static_platforms.png");
        m_modelSprite.scale(m_width/m_modelTexture.getSize().x, m_height/m_modelTexture.getSize().y);
        m_subject->setWidth(m_width);
        m_subject->setHeight(m_height);
    }

    Platform_vertical::Platform_vertical(shared_ptr<logic::Subject>& subject) {
        m_width = Window::Instance()->getWindow()->getSize().x/8.5;
        m_height = Window::Instance()->getWindow()->getSize().y/11.5;
        m_subject = subject;
        createSprite("../Sprites/Vertical_platforms.png");
        m_modelSprite.scale(m_width/m_modelTexture.getSize().x, m_height/m_modelTexture.getSize().y);
        m_subject->setWidth(m_width);
        m_subject->setHeight(m_height);
    }

    Platform_horizontal::Platform_horizontal(shared_ptr<logic::Subject>& subject) {
        m_width = Window::Instance()->getWindow()->getSize().x/8.5;
        m_height = Window::Instance()->getWindow()->getSize().y/11.5;
        m_subject = subject;
        createSprite("../Sprites/Horizontal_platforms.png");
        m_modelSprite.scale(m_width/m_modelTexture.getSize().x, m_height/m_modelTexture.getSize().y);
        m_subject->setWidth(m_width);
        m_subject->setHeight(m_height);
    }

    Platform_temporary::Platform_temporary(shared_ptr<logic::Subject>& subject) {
        m_width = Window::Instance()->getWindow()->getSize().x/8.5;
        m_height = Window::Instance()->getWindow()->getSize().y/11.5;
        m_subject = subject;
        createSprite("../Sprites/Temporary_platforms.png");
        m_modelSprite.scale(m_width/m_modelTexture.getSize().x, m_height/m_modelTexture.getSize().y);
        m_subject->setWidth(m_width);
        m_subject->setHeight(m_height);
    }
}