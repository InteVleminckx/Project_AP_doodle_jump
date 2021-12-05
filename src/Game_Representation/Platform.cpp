#include "Platform.h"

namespace representation {

    Platform::Platform() = default;

    Platform::Platform(shared_ptr<logic::Subject>& subject) {
        float scale = Window::Instance()->getWindow()->getSize().x;
        m_width =  scale * subject->getWidth();
        m_height = scale * subject->getHeight();
        m_subject = subject;
    }

    void Platform::update() {

        float x = Window::Instance()->getWindow()->getSize().x*m_subject->getX()-m_width/2;
        float y = Window::Instance()->getWindow()->getSize().y - (m_subject->getY()*Window::Instance()->getWindow()->getSize().y)-m_height/2;
        m_modelSprite.setPosition(x, y);
        representation::Window::Instance()->getWindow()->draw(m_modelSprite);
    }

    Platform_static::Platform_static(shared_ptr<logic::Subject>& subject) : Platform(subject){
        createSprite("../Sprites/Static_platforms.png");
        m_modelSprite.scale(m_width/m_modelTexture.getSize().x, m_height/m_modelTexture.getSize().y);
        cout << m_modelSprite.getPosition().x << " " << m_modelSprite.getPosition().y << endl;

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